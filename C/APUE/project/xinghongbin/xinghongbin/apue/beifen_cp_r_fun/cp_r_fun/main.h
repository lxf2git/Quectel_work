#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
int find_fileName(char *srcPath,char *destPath);
int file_information(char *fileName,char*srcPath,char *destPath);
int copy_str(char *fileName,char *destName);
int  mkdir_destPath(char *path);
#endif
