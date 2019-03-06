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
        sh '''mkdir -p $WORKSPACE/contrib
mv -v $WORKSPACE/* $WORKSPACE/.* contrib/'''
      }
    }
    stage('Build STM32') {
      parallel {
        stage('Build STM32') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/STM32/'''
          }
        }
        stage('Build NRF51') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/NRF51/'''
          }
        }
        stage('Build NRF52') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/NRF52/'''
          }
        }
        stage('Build TIVA') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/TIVA/'''
          }
        }
        stage('Build Kinetis') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/ChibiOS-RT
bash $WORKSPACE/contrib/tools/chbuild.sh $WORKSPACE/contrib/testhal/KINETIS/'''
          }
        }
      }
    }
  }
}