#ifndef _SHOW_H_
#define _SHOW_H_
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "mode.h"
void show_file_inode(char *);
void dir_file(int,int,int,char *);

#endif
