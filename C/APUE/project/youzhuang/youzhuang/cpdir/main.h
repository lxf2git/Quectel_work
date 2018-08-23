#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void scna(char *src_dir, char *dest_path);
void copy(char *src_file, char *dest_file);
void new_str(char *stc,char *dest, char *src_dir,char *dest_dir,char *d_name);
#endif
