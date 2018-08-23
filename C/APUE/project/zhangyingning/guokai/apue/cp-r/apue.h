#ifndef APUE_H
#define APUE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <shadow.h>
#include <unistd.h>
#include <pwd.h>
#include<time.h>
#include<setjmp.h>
#include<stdlib.h>
int func(char *buf1,char *buf2,char *buf3);
int cp_file(char *a,char *dest,char *ar2);
#endif
