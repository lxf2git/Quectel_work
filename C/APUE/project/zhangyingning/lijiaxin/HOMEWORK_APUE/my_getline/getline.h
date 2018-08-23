#ifndef GETLINE_H_
#define GETLINE_H_
#define _GNU_SOURCE
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void pbuf_free(void **pbuf);
void creat_memory(char **pbuf,int p_len);
int my_getline(char **pbuf,int *p_len,FILE *fp);
int before_len;
#endif
