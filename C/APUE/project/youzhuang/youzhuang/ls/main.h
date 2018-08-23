#ifndef _MAIN_H_
#define _MAIN_H_
#define SUC 0
#define FAIL -1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
typedef struct file
{
		int ino;
		int size;
		int link;
		int day;
		int hour;
		int min;
		char mode[11];
		char gname[10];
		char mon[4];
		char uname[10];
		char name[256];
		struct file *prev;
		struct file *next;
}sFile,*pFile;
void create_memory(pFile *p,int size);
void free_memory(pFile *p);
void init_node(pFile *p);
void add_node(pFile phead,pFile pnew);
void unload_link(pFile *phead);
void del_node(pFile phead, pFile p);
void ls(int argc, char **argv, pFile phead);
void save_struct(char *file_flage, char *path, pFile phead);
void show(char *file_flage, pFile phead);
int mode(char *file_name,pFile pnew);
int judge(char *file_flage, char ch);
#endif
