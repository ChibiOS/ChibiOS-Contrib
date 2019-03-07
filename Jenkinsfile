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
        sh '''BRANCH=stable_18.2.x

git -C $WORKSPACE/ChibiOS checkout $BRANCH && git -C $WORKSPACE/ChibiOS pull || rm -rf $WORKSPACE/ChibiOS && git clone -b $BRANCH --single-branch https://github.com/ChibiOS/ChibiOS.git'''
        sh 'CH_PATH=$WORKSPACE/ChibiOS CHC_PATH=$WORKSPACE ./tools/chbuild.sh ./testhal/STM32/'
        sh 'CH_PATH=$WORKSPACE/ChibiOS CHC_PATH=$WORKSPACE ./tools/chbuild.sh ./demos/STM32/'
      }
    }
  }
}