#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <sys/types.h>      
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#define FAIL -1
#define SUC 0
#define N 1024*1024//文件最大字节数
#define M 1024	//目录名最长长度
void file_cp(char *path_start,char *path_end);
int dir_cp(char *path_start,char *path_end);
int judge_fileORdir(int argc,char **argv);
void get_prevDir_Addr(char *path);

#endif
