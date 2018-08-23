#include"main.h"

void create_memory(pTree *p)
{
        *p=(pTree)malloc(sizeof(sTree));
        if(*p==NULL)
        {
                printf("create error!\n");
                exit(-1);
        }
        (*p)->lc=NULL;
        (*p)->rc=NULL;
}

