#!/bin/bash
#Creation time    ：20190929
#Author           ：Huang LongPeng
#Version          ：v1_0
#Introduction     ：compile scan_code
#Update time      ：

project_path=$(cd `dirname $0`; pwd)
SUDO="sudo -s"

echo $project_path

if [ $1x == "compile"x  ]; then
        echo start to compile scan_src code 
        mkdir -p build
        cd $project_path/build 
        cmake ../  
	make 
        chmod 777 ./ -R
elif [ $1x == "package"x ]; then
        echo start to package for install
        cd $project_path/build
	cp scan $project_path/target 

        cd ../target
        tar cJvf scan_update.tar.bz2 scan update_scan.sh
else
        echo command:
        echo ./build compile  ----- compile scan_src code
        echo ./build package  ----- package for install
fi

cd $project_path
echo complete

