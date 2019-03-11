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
echo $CHC_PATH

exit 0'''
      }
    }
    stage('Build Platforms') {
      parallel {
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
            sh '''export CH_PATH=$WORKSPACE/ChibiOS
export CHC_PATH=$WORKSPACE

./tools/chbuild.sh ./testhal/STM32/
./tools/chbuild.sh ./demos/STM32/'''
          }
        }
        stage('Build NRF51') {
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
for i in *.7z; do 7z x -y $i; done
'''
            sh '''export CH_PATH=$WORKSPACE/ChibiOS
export CHC_PATH=$WORKSPACE

./tools/chbuild.sh ./testhal/NRF51/
./tools/chbuild.sh ./demos/NRF51/
'''
          }
        }
        stage('Build NRF52') {
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
for i in *.7z; do 7z x -y $i; done
'''
            sh '''export CH_PATH=$WORKSPACE/ChibiOS
export CHC_PATH=$WORKSPACE

./tools/chbuild.sh ./testhal/NRF52/
./tools/chbuild.sh ./demos/NRF52/
'''
          }
        }
        stage('Build Kinetis') {
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
            sh '''export CH_PATH=$WORKSPACE/ChibiOS
export CHC_PATH=$WORKSPACE

./tools/chbuild.sh ./testhal/KINETIS/
./tools/chbuild.sh ./demos/KINETIS/
'''
          }
        }
      }
    }
  }
  environment {
    CH_BRANCH = 'stable_18.2.x'
    CH_PATH = 'ChibiOS'
  }
}