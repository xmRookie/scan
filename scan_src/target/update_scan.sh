#!/bin/bash
#Creation time    ：20190929
#Author           ：Huang LongPeng
#Version          ：v1_0
#Introduction     ：update scan
#Update time      ：

SUDO="sudo -s"
project_path=$(cd `dirname $0`; pwd)
src_target_path='/usr/local/share/starnet/scan/'

echo $project_path

$SUDO mkdir -p $src_target_path
$SUDO cp $project_path/scan $src_target_path
