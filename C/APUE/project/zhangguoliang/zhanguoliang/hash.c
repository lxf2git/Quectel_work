#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
	int data;
	struct data *prev;
	struct data *next;
}sData,*pData;

typedef struct and
{
	struct data*and[8];//data>>3&7
}sAnd,*pAnd;

typedef struct mod
{
	struct and*mod[5];// data%5
}sMod,*pMod;

void create_memory(pData *p)
{
	(*p)=(pData)malloc(sizeof(sData));
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_data(pData *p)
{
	create_memory(p);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}

void chain_head(pData pHead,pData pnew)
{
	pnew->prev=pHead;
	pnew->next=pHead->next;
	pHead->next->prev=pnew;
	pHead->next=pnew;
}

void del_data(pData *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void input_number(pData pHead)
{
	pData pnew=NULL;
	for(;;)
	{
		printf("please input member:\n");
		printf("if you want to stop please input '-1'\n");
		init_data(&pnew);
		scanf("%d",&pnew->data);
		if(pnew->data>=0)
		{
			chain_head(pHead,pnew);
		}
		else
		{
			del_data(&pnew);
			break;
		}
	}
}

void build_hash(pData pHead,pMod pstart)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		pstart->mod[i]=(pAnd)malloc(sizeof(sAnd));
		for(j=0;j<8;j++)
		{
			pstart->mod[i]->and[j]=(pData)malloc(sizeof(sData));
			init_data(&(pstart->mod[i]->and[j]));
		}
	}
	pData pnew=pHead->next;
	while(pnew!=pHead)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(pnew->data%5==i && ((pnew->data)>>3&7)==j)
				{
					pData ptmp=NULL;
					pData pdel=pnew;
					init_data(&ptmp);
					ptmp->data=pnew->data;
					chain_head(pstart->mod[i]->and[j],ptmp);
					del_data(&pdel);
				}
			}
		}
		pnew=pnew->next;
	}
}

void find_num(pMod pstart)
{
	int a,b=0;
	printf("please input number what you find:\n");
	scanf("%d",&a);
	int i,j;
	i=a%5;
	j=a>>3&7;
	pData pnew=pstart->mod[i]->and[j]->next;
	while(pnew!=pstart->mod[i]->and[j])
	{
		if(a==pnew->data)
		{
			printf("have : %d\n",pnew->data);
			b=1;
			return ;
		}
		pnew=pnew->next;
	}
	if(b==0)
	{
		printf("not have\n");
	}

}

void del_and(pAnd *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void del_mod(pMod *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void del_mem(pMod pstart)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<8;j++)
		{
			pData pnew=pstart->mod[i]->and[j]->next;
			while(pnew!=pstart->mod[i]->and[j])
			{
				pData pdel=pnew;
				pnew->prev->next=pnew->next;
				pnew->next->prev=pnew->prev;
				del_data(&pdel);
				pnew=pnew->next;
			}
			del_data(&(pstart->mod[i]->and[j]));
		}
		del_and(&(pstart->mod[i]));
	}
	del_mod(&pstart);
}

int main()
{
	pData pHead=NULL;
	init_data(&pHead);
	input_number(pHead);
	pMod pstart=NULL;
	pstart=(pMod)malloc(sizeof(sMod));
	build_hash(pHead,pstart);
	find_num(pstart);
	del_mem(pstart);
	return 0;
}
