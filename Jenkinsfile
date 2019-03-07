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
        sh '''git -C $WORKSPACE/ChibiOS pull || git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git

CH_PATH=$WORKSPACE/ChibiOS ./tools/chbuild.sh ./testhal/STM32/'''
      }
    }
  }
}