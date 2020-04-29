#!/bin/sh
#Author: lightjia
#Date: 2020.4.29


#use subtree  quote svrbase 
#The specific steps are 
## git remote add svrbase https://github.com/lightjia/SvrBase.git  
## git subtree add  --prefix=svrbase  svrbase master --squash

#To Update SvrBase use push
## git subtree push  --prefix=svrbase  svrbase master
ROOTDIR=`pwd`
git subtree pull  --prefix=svrbase  svrbase master --squash
cd svrbase/svrbase
mkdir build bin
cd build
cmake ..
make

cd $ROOTDIR
rm -rf third
mkdir third
cd third
cp -rf $ROOTDIR/svrbase/svrbase/third/* ./
mkdir -p svrbase/lib/linux svrbase/base svrbase/cfg svrbase/openssl svrbase/libuv
cp -rf $ROOTDIR/svrbase/svrbase/SvrBase/base/include ./svrbase/base
cp -rf $ROOTDIR/svrbase/svrbase/SvrBase/cfg/include ./svrbase/cfg
cp -rf $ROOTDIR/svrbase/svrbase/SvrBase/openssl/include ./svrbase/openssl
cp -rf $ROOTDIR/svrbase/svrbase/SvrBase/libuv/include ./svrbase/libuv
cp -rf $ROOTDIR/svrbase/svrbase/bin/* ./svrbase/lib/linux