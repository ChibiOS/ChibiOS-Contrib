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
        sh '''mkdir /tmp/contrib
cp -r $WORKSPACE/* $WORKSPACE/.git /tmp/contrib/


mv -v /tmp/contrib $WORKSPACE/'''
        sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/STM32/'''
      }
    }
  }
}