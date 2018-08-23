#include"stack.h"

int init_stack(pSta ps)
{
    create_memory((void **)&ps->bottom,N*sizeof(int));
    ps->top = 0;
}

void create_memory(void **p, int size)
{
    *p = malloc(size);
    if(NULL == *p)
    {
        printf("Malloc Error\n");
        exit(-1);
    }
}

int pull(pSta ps,int data)
{
    if(N == ps->top)
    {
        printf("stack is full\n");
        return FAILE;
    }
    ps->bottom[ps->top] = data;
    ps->top++;
    
    return SUCCESSED;
}

int pop(pSta ps, int *result)
{
    if(0 == ps->top)
    {
        printf("stack is empty");
        return FAILE;
    }
    ps->top--;
    *result = ps->bottom[ps->top];

    return SUCCESSED;
}

