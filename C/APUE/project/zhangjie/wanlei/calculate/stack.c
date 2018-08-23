#include"stack.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_num(pNum pn)
{
	creat_memory((void **)&pn->num,SIZE*sizeof(int));
	pn->top=0;
}

void init_ch(pChar pc)
{
	creat_memory((void **)&pc->ch,SIZE*sizeof(char));
	pc->top=0;
}

int push_num(pNum pn,int num)
{
	if(pn->top==SIZE)
	{
		printf("full\n");
		return FULL;
	}
	pn->num[pn->top++]=num;
	return SUC;
}

int push_char(pChar pc,char ch)
{
	if(pc->top==SIZE)
	{
		printf("full\n");
		return FULL;
	}
	pc->ch[pc->top++]=ch;
	return SUC;
}

int pop_num(pNum pn,int *pop_num)
{
	if(pn->top==0)
	{
		return EMPTY;
	}
	*pop_num=pn->num[--pn->top];
	return SUC;
}

int pop_char(pChar pc,char *pop_ch)
{
	if(pc->top==0)
	{
		return EMPTY;
	}
	*pop_ch=pc->ch[--pc->top];
	//printf("%c ",*pop_ch);
	return SUC;
}
