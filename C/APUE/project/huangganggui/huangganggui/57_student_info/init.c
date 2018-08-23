#include"init.h"

void init_node(pStu *pNode)
{
    create_memory((void **)pNode,sizeof(sStu));
    (*pNode)->next = NULL;
    (*pNode)->num = 0;
    (*pNode)->age = 0;
    

}

void create_memory(void **p,int size)
{
    *p = malloc(size);
    if(NULL == *p)
    {
        printf("Malloc Error\n");
        exit(-1);
    }
}

void insert_behind(pStu pPosition,pStu pnew)
{
    if(NULL == pnew || NULL == pPosition)
    {
        printf("Error:%s\n",__FUNCTION__);
        exit(-1);
    }
    pnew->next = pPosition->next;
    pPosition->next = pnew;

}


pStu find_bigger_position(pStu pHead,pStu pNew) 
{
    pStu ptemp = NULL;
    ptemp = pHead;

    while(NULL != ptemp->next ) 
    {   
        if(ptemp->next->num > pNew->num) 
        {   
            return ptemp;
        }   
        ptemp = ptemp->next;
    }   
    return ptemp;

}

