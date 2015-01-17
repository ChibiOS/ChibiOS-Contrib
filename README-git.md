Quick start:
============

Assume you already have a github account. Lets your account name is
"username".

First you need to fork 2 repos:
- ChibiOS
- ChibiOS-contrib

Make local clone of your fork
```bash
# git clone git@github.com:username/ChibiOS-gitmain.git
```

Make local branch for your feature
```bash
# cd ChibiOS-gitmain
# git branch feature
# git checkout feature
```

There is no code from ChibiOS-contrib in your repo. We have to connect 
ChibiOS-contrib as a git submodule
```bash
# git submodule add git@github.com:username/ChibiOS-Contrib.git community
```

Make branch again, but now in freshly connected submodule
```bash
# cd community
# git branch feature
# git checkout feature
```

Hack, hack, hack... Commit our changes and push to server. Note: you have 
to do this for both repositories. First ChibiOS-Contrib
```bash
# cd community
# git add .
# git commit -m "Feature implemented"
# git push origin feature:feature
```

Now for parent repo
```bash
# cd ..
# git add .
# git commit -m "Feature implemented"
# git push origin feature:feature
```

Now all your changes published on github. Just use web interface to send
pull 2 requests: for ChibiOS-contrib and for ChibiOS-gitmain.

Links:
======

https://help.github.com/

http://git-scm.com/

http://chibios.org/dokuwiki/doku.php?id=chibios:guides:style_guide
