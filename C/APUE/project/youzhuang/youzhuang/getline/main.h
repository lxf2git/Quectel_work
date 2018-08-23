#ifndef _MAIN_H_
#define _MAIN_H_
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream);
void create_memory(void **p,int size);
#endif
