#include"stack.h"
void create_memory(void **p)
{
		*p=malloc(SIZE);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}
void init_stack(pNum num,pSig sig)
{
		create_memory((void**)&num->bottom);
		num->top=0;
		create_memory((void**)&sig->bottom);
		sig->top=0;
}
int push_num(pNum num,int value)
{
		if(num->top>SIZE)
		{
				printf("stack push!\n");
				return FULL;
		}
		num->bottom[num->top]=value;
		num->top++;
		return SUCCESS;
}
int push_sig(pSig sig,char value)
{
		if(sig->top>SIZE)
		{
				printf("stack push!\n");
				return FULL;
		}
		sig->bottom[sig->top]=value;
		sig->top++;
		return SUCCESS;
}
int pop_num(pNum num,int *value)
{
		if(num->top==0)
		{
				return EMPTY;
		}
		num->top--;
		*value=num->bottom[num->top];
		return SUCCESS;
}
int pop_sig(pSig sig,char *value)
{
		if(sig->top==0)
		{
				return EMPTY;
		}
		sig->top--;
		*value=sig->bottom[sig->top];
		return SUCCESS;
}
