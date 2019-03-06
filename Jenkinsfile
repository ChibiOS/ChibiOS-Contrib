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
      parallel {
        stage('Build STM32') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            ws(dir: 'Contrib') {
              sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/../ChibiOS-RT
bash $WORKSPACE/tools/chbuild.sh $WORKSPACE/testhal/STM32/'''
            }

          }
        }
        stage('Build NRF51') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            ws(dir: 'Contrib') {
              sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/../ChibiOS-RT
bash $WORKSPACE/tools/chbuild.sh $WORKSPACE/testhal/NRF51/'''
            }

          }
        }
        stage('Build NRF52') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            ws(dir: 'Contrib') {
              sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/../ChibiOS-RT
bash $WORKSPACE/tools/chbuild.sh $WORKSPACE/testhal/NRF52/'''
            }

          }
        }
        stage('Build TIVA') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            ws(dir: 'Contrib') {
              sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/../ChibiOS-RT
bash $WORKSPACE/tools/chbuild.sh $WORKSPACE/testhal/TIVA/'''
            }

          }
        }
        stage('Build Kinetis') {
          agent {
            docker {
              image 'fpoussin/jenkins:ubuntu-18.04-arm'
            }

          }
          steps {
            ws(dir: 'Contrib') {
              sh '''git clone -b stable_19.1.x --single-branch https://github.com/ChibiOS/ChibiOS.git $WORKSPACE/../ChibiOS-RT
bash $WORKSPACE/tools/chbuild.sh $WORKSPACE/testhal/KINETIS/'''
            }

          }
        }
      }
    }
  }
}