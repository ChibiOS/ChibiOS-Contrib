/**********************************************************************************************
* Arduino PID Library - Version 1.2.1
* by Brett Beauregard <br3ttb@gmail.com> brettbeauregard.com
* Modified by Fabien Poussin <fabien.poussin@gmail.com> for ChibiOS.
*
* This Library is licensed under the MIT License
**********************************************************************************************/

#include "pid.h"
#include "osal.h"

#define TIME_MS (osalOsGetSystemTimeX() / (OSAL_ST_FREQUENCY / 1000))

/*Constructor (...)*********************************************************
*    The parameters specified here are those for for which we can't set up
*    reliable defaults, so we need to have the user set them.
***************************************************************************/
void pid_create(pid_t* p, float* Input, float* Output, float* Setpoint,
        float Kp, float Ki, float Kd, int POn, int ControllerDirection)
{
    p->myOutput = Output;
    p->myInput = Input;
    p->mySetpoint = Setpoint;
    p->inAuto = false;

    pid_setOutputLimits(p, 0, 255); // default output limit corresponds to
                                    // the arduino pwm limits

    p->SampleTime = 100; // default Controller Sample Time is 100ms

    pid_setControllerDirection(p, ControllerDirection);
    pid_setTunings(p, Kp, Ki, Kd, POn);

    p->lastTime = TIME_MS - p->SampleTime;
}


/* Compute() **********************************************************************
*   This, as they say, is where the magic happens.  this function should be called
*   every time "void loop()" executes.  the function will decide for itself whether a new
*   pid Output needs to be computed.  returns true when the output is computed,
*   false when nothing has been done.
**********************************************************************************/
bool pid_compute(pid_t* p)
{
    if(!p->inAuto) return false;
    unsigned long now = TIME_MS;
    unsigned long timeChange = (now - p->lastTime);
    if(timeChange >= p->SampleTime)
    {
        /* Compute all the working error variables */
        float input = *p->myInput;
        float error = *p->mySetpoint - input;
        float dInput = (input - p->lastInput);
        p->outputSum += (p->ki * error);

        /* Add Proportional on Measurement, if P_ON_M is specified */
        if(!p->pOnE) p->outputSum -= p->kp * dInput;

        if(p->outputSum > p->outMax) p->outputSum = p->outMax;
        else if(p->outputSum < p->outMin) p->outputSum = p->outMin;

        /* Add Proportional on Error, if P_ON_E is specified */
        float output;
        if(p->pOnE) output = p->kp * error;
        else output = 0;

        /* Compute Rest of PID Output */
        output += p->outputSum - p->kd * dInput;

        if(output > p->outMax) output = p->outMax;
        else if(output < p->outMin) output = p->outMin;
            *p->myOutput = output;

        /* Remember some variables for next time */
        p->lastInput = input;
        p->lastTime = now;
        return true;
    }
    else return false;
}

/* SetTunings(...)*************************************************************
* This function allows the controller's dynamic performance to be adjusted.
* it's called automatically from the constructor, but tunings can also
* be adjusted on the fly during normal operation
******************************************************************************/
void pid_setTunings(pid_t* p, float Kp, float Ki, float Kd, int POn)
{
    if (Kp<0 || Ki<0 || Kd<0) return;

    p->pOn = POn;
    p->pOnE = POn == PID_P_ON_E;

    p->dispKp = Kp; p->dispKi = Ki; p->dispKd = Kd;

    float SampleTimeInSec = ((float)p->SampleTime)/1000;
    p->kp = Kp;
    p->ki = Ki * SampleTimeInSec;
    p->kd = Kd / SampleTimeInSec;

    if(p->controllerDirection == PID_REVERSE)
    {
        p->kp = (0 - p->kp);
        p->ki = (0 - p->ki);
        p->kd = (0 - p->kd);
    }
}

/* SetSampleTime(...) *********************************************************
* sets the period, in Milliseconds, at which the calculation is performed
******************************************************************************/
void pid_setSampleTime(pid_t* p, int NewSampleTime)
{
    if (NewSampleTime > 0)
    {
        float ratio  = (float)NewSampleTime / (float)p->SampleTime;
        p->ki *= ratio;
        p->kd /= ratio;
        p->SampleTime = (unsigned long)NewSampleTime;
    }
}

/* SetOutputLimits(...)****************************************************
*     This function will be used far more often than SetInputLimits.  while
*  the input to the controller will generally be in the 0-1023 range (which is
*  the default already,)  the output will be a little different.  maybe they'll
*  be doing a time window and will need 0-8000 or something.  or maybe they'll
*  want to clamp it from 0-125.  who knows.  at any rate, that can all be done
*  here.
**************************************************************************/
void pid_setOutputLimits(pid_t* p, float Min, float Max)
{
    if(Min >= Max) return;
    p->outMin = Min;
    p->outMax = Max;

    if(p->inAuto)
    {
        if(*p->myOutput > p->outMax) *p->myOutput = p->outMax;
        else if(*p->myOutput < p->outMin) *p->myOutput = p->outMin;

        if(p->outputSum > p->outMax) p->outputSum = p->outMax;
        else if(p->outputSum < p->outMin) p->outputSum = p->outMin;
    }
}

/* SetMode(...)****************************************************************
* Allows the controller Mode to be set to manual (0) or Automatic (non-zero)
* when the transition from manual to auto occurs, the controller is
* automatically initialized
******************************************************************************/
void pid_setMode(pid_t* p, int Mode)
{
    bool newAuto = (Mode == PID_AUTOMATIC);
    if(newAuto && !p->inAuto)
    {  /* we just went from manual to auto */
        pid_initialize(p);
    }
    p->inAuto = newAuto;
}

/* Initialize()****************************************************************
*	does all the things that need to happen to ensure a bumpless transfer
*  from manual to automatic mode.
******************************************************************************/
void pid_initialize(pid_t* p)
{
    p->outputSum = *p->myOutput;
    p->lastInput = *p->myInput;
    if(p->outputSum > p->outMax) p->outputSum = p->outMax;
    else if(p->outputSum < p->outMin) p->outputSum = p->outMin;
}

/* SetControllerDirection(...)*************************************************
* The PID will either be connected to a DIRECT acting process (+Output leads
* to +Input) or a REVERSE acting process(+Output leads to -Input.)  we need to
* know which one, because otherwise we may increase the output when we should
* be decreasing.  This is called from the constructor.
******************************************************************************/
void pid_setControllerDirection(pid_t* p, int Direction)
{
    if(p->inAuto && Direction != p->controllerDirection)
    {
        p->kp = (0 - p->kp);
        p->ki = (0 - p->ki);
        p->kd = (0 - p->kd);
    }
    p->controllerDirection = Direction;
}

