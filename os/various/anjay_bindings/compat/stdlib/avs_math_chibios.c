/*
Copyright © 2005-2020 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* Portions of this file are extracted from musl-1.2.4:
 * src/internal/libm.h
 * src/math/fmod.c
 * src/math/trunc.c
 * src/math/round.c
 */


#include <stdint.h>
#include <float.h>
#include <math.h>


#ifndef fp_force_evalf
#define fp_force_evalf fp_force_evalf
static inline void fp_force_evalf(float x)
{
	volatile float y;
	y = x;
}
#endif

#ifndef fp_force_eval
#define fp_force_eval fp_force_eval
static inline void fp_force_eval(double x)
{
	volatile double y;
	y = x;
}
#endif

#ifndef fp_force_evall
#define fp_force_evall fp_force_evall
static inline void fp_force_evall(long double x)
{
	volatile long double y;
	y = x;
}
#endif

#define FORCE_EVAL(x) do {                        \
	if (sizeof(x) == sizeof(float)) {         \
		fp_force_evalf(x);                \
	} else if (sizeof(x) == sizeof(double)) { \
		fp_force_eval(x);                 \
	} else {                                  \
		fp_force_evall(x);                \
	}                                         \
} while(0)


double fmod(double x, double y) {
  union {
    double f;
    uint64_t i;
  } ux = {x}, uy = {y};
  int ex = ux.i >> 52 & 0x7ff;
  int ey = uy.i >> 52 & 0x7ff;
  int sx = ux.i >> 63;
  uint64_t i;

  /* in the followings uxi should be ux.i, but then gcc wrongly adds */
  /* float load/store to inner loops ruining performance and code size */
  uint64_t uxi = ux.i;

  if (uy.i << 1 == 0 || isnan(y) || ex == 0x7ff)
    return (x * y) / (x * y);

  if (uxi << 1 <= uy.i << 1) {
    if (uxi << 1 == uy.i << 1)
      return 0 * x;

    return x;
  }

  /* normalize x and y */
  if (!ex) {
    for (i = uxi << 12; i >> 63 == 0; ex--, i <<= 1);

    uxi <<= -ex + 1;
  } else {
    uxi &= -1ULL >> 12;
    uxi |= 1ULL << 52;
  }

  if (!ey) {
    for (i = uy.i << 12; i >> 63 == 0; ey--, i <<= 1);

    uy.i <<= -ey + 1;
  } else {
    uy.i &= -1ULL >> 12;
    uy.i |= 1ULL << 52;
  }

  /* x mod y */
  for (; ex > ey; ex--) {
    i = uxi - uy.i;

    if (i >> 63 == 0) {
      if (i == 0)
        return 0 * x;

      uxi = i;
    }

    uxi <<= 1;
  }

  i = uxi - uy.i;

  if (i >> 63 == 0) {
    if (i == 0)
      return 0 * x;

    uxi = i;
  }

  for (; uxi >> 52 == 0; uxi <<= 1, ex--);

  /* scale result */
  if (ex > 0) {
    uxi -= 1ULL << 52;
    uxi |= (uint64_t)ex << 52;
  } else {
    uxi >>= -ex + 1;
  }

  uxi |= (uint64_t)sx << 63;
  ux.i = uxi;
  return ux.f;
}


double trunc(double x) {
  union {
    double f;
    uint64_t i;
  } u = {x};
  int e = (int)(u.i >> 52 & 0x7ff) - 0x3ff + 12;
  uint64_t m;

  if (e >= 52 + 12)
    return x;

  if (e < 12)
    e = 1;

  m = -1ULL >> e;

  if ((u.i & m) == 0)
    return x;

  FORCE_EVAL(x + 0x1p120f);
  u.i &= ~m;
  return u.f;
}

#if FLT_EVAL_METHOD==0 || FLT_EVAL_METHOD==1
#define EPS DBL_EPSILON
#elif FLT_EVAL_METHOD==2
#define EPS LDBL_EPSILON
#endif
static const double_t toint = 1 / EPS;


double round(double x) {
  union {
    double f;
    uint64_t i;
  } u = {x};
  int e = u.i >> 52 & 0x7ff;
  double_t y;

  if (e >= 0x3ff + 52)
    return x;

  if (u.i >> 63)
    x = -x;

  if (e < 0x3ff - 1) {
    /* raise inexact if x!=0 */
    FORCE_EVAL(x + toint);
    return 0 * u.f;
  }

  y = x + toint - toint - x;

  if (y > 0.5)
    y = y + x - 1;
  else if (y <= -0.5)
    y = y + x + 1;
  else
    y = y + x;

  if (u.i >> 63)
    y = -y;

  return y;
}
