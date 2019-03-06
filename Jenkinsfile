pipeline {
  agent any
  stages {
    stage('Prepare ChibiOS') {
      agent {
        docker {
          image 'fpoussin/jenkins:ubuntu-18.04'
        }

      }
      steps {
        sh 'exit 0'
      }
    }
    stage('Build STM32') {
      agent {
        docker {
          image 'fpoussin/jenkins:ubuntu-18.04-arm'
        }

      }
      steps {
        sh '''mkdir /tmp/contrib_$EXECUTOR_NUMBER

cp -r $WORKSPACE/* $WORKSPACE/.git /tmp/contrib_$EXECUTOR_NUMBER

cp -r /tmp/contrib_$EXECUTOR_NUMBER $WORKSPACE/'''
        sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
cd $WORKSPACE/contrib
bash ./tools/chbuild.sh ./testhal/STM32/'''
      }
    }
  }
}