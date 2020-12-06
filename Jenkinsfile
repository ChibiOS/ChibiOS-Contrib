pipeline {
  agent {
    docker {
      image 'fpoussin/jenkins:ubuntu-18.04-chibios'
    }

  }
  stages {
    stage('Prepare ChibiOS') {
      steps {
        sh '''
        echo $CH_BRANCH
        echo $CH_PATH
        echo $CHC_PATH

        exit 0
        '''
        sh '''
        arm-none-eabi-gcc -v

        cd $WORKSPACE/ext
        for i in *.7z; do 7z x -y $i; done

        cd $WORKSPACE
        rm -rf $CH_PATH
        git clone /var/lib/git/ChibiOS $CH_PATH
        cd $CH_PATH
        git remote set-url origin https://github.com/ChibiOS/ChibiOS.git
        git fetch --all
        git checkout -b $CH_BRANCH origin/$CH_BRANCH
        git pull --rebase origin $CH_BRANCH

        cd ext
        for i in *.7z; do 7z x -y $i; done
        '''
      }
    }

    stage('Build STM32') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./testhal/STM32/
        ./tools/chbuild.sh ./demos/STM32/
        '''
      }
    }

    stage('Build NRF51') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./testhal/NRF51/
        ./tools/chbuild.sh ./demos/NRF51/
        '''
      }
    }

    stage('Build NRF52') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./testhal/NRF52/
        ./tools/chbuild.sh ./demos/NRF52/
        '''
      }
    }

    stage('Build Kinetis') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./testhal/KINETIS/
        ./tools/chbuild.sh ./demos/KINETIS/
        '''
      }
    }

    stage('Build LPC') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./demos/LPC/
        '''
      }
    }

    stage('Build NUMICRO') {
      steps {
        sh '''
        export CH_PATH=$WORKSPACE/ChibiOS
        export CHC_PATH=$WORKSPACE
        ./tools/chbuild.sh ./testhal/NUMICRO/
        ./tools/chbuild.sh ./demos/NUMICRO/
        '''
      }
    }

  }
  environment {
    CH_BRANCH = 'stable_20.3.x'
  }
}
