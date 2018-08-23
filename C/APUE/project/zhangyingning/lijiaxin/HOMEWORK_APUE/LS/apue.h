#ifndef APUE_H
#define APUE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int file_show(char *argv,int show_l,int show_a,int show_i);
int show_inode(char *file,int flag);
int show_all_attr(char *argv,int l);
#endif
