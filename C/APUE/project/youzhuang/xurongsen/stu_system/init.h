#ifndef _INIT_H_
#define _INIT_H_

#include"main_st.h"

void init_node(pStu *pp, int size);
void create_memory(void **pp, int size);
void input_message(pStu *pp);
void destory_node(pStu *p);
void openfile(FILE **popen);
void readfile(FILE **popen);
void exit_my(pStu *phead);
void load(pStu phead,FILE *fp);
void load_read(pStu phead, FILE *fp);

#endif
