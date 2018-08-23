#! /bin/sh
for var in "$*"
do
	scp -r "$var"  192.168.2.111:/home/u1/kernel/hk/"$var"stu/lujian
done

