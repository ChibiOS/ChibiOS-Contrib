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
        sh '''echo $CH_BRANCH
echo $CH_PATH
echo $CHC_PATH'''
      }
    }
    stage('Build STM32') {
      agent {
        docker {
          image 'fpoussin/jenkins:ubuntu-18.04-arm'
        }

      }
      steps {
        sh '''arm-none-eabi-gcc -v

rm -rf $CH_PATH
git clone -b $CH_BRANCH --single-branch https://github.com/ChibiOS/ChibiOS.git $CH_PATH

cd $CH_PATH/ext
for i in *.7z; do 7z x -y $i; done'''
        sh './tools/chbuild.sh ./testhal/STM32/'
        sh './tools/chbuild.sh ./demos/STM32/'
      }
    }
  }
  environment {
    CH_BRANCH = 'stable_18.2.x'
    CH_PATH = '$PWD/ChibiOS'
    CHC_PATH = '$PWD'
  }
}