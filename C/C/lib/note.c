
/*
 * 1 静态库
 *
 * 使用归档工具ar 将一系列
 *
 *ar -crv  libxx.a lib

 * 2 动态库 
 * 
 * gcc -shared -fpic fun1.o fun2.o -o libmyfun.so
 *
 * mv libmyfun.so /usr/lib   //usr/lib/local
 *
 *
 *设置环境变量 库的路径 
 *
 *export LD_LIBRARY_PATH=path：
 *
 *
 *改写配置文件

 * vim /ect/profile
 *
 *
 *
