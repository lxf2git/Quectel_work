#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data
{
		int data;
		struct data *next;
		struct data *prev;
}sdata,*pdata;

typedef struct and
{
		struct data *and[8];
}sAnd,*pAnd;

typedef struct mod
{
		struct and *mod[5];
}smod,*pmod;

enum su
{
		scan_=1,
		find_,
		exit_
};

int gand_memoty(pAnd *pf)
{
		*pf=malloc(sizeof(sAnd));
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}
}

int gmod_memoty(pmod *pf)
{
		*pf=malloc(sizeof(smod));
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}

}

int great_memoty(pdata *pf)
{
		*pf=malloc(sizeof(sdata));
		(*pf)->next=(*pf);
		(*pf)->prev=(*pf);
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}
}

void mod_and_data(pmod pmod_head)
{
		int i,j;
		for(i=0;i<5;i++)
		{
				pAnd pand_new;
				gand_memoty(&pand_new);
				pmod_head->mod[i]=pand_new;
				for(j=0;j<8;j++)
				{
						pdata pdata_head;
						great_memoty(&pdata_head);
						pmod_head->mod[i]->and[j]=pdata_head;
				}
		}
}

void scan(pmod pmod_head)
{
		int i,j;
		pdata pdata_new;
		great_memoty(&pdata_new);
		printf("输入一个整数\n");
		scanf("%d",&pdata_new->data);
		i=(pdata_new->data)%5;
		j=((pdata_new->data)>>3)&7;
		pmod_head->mod[i]->and[j]->next->prev=pdata_new;
		pdata_new->next= pmod_head->mod[i]->and[j]->next;
		pdata_new->prev= pmod_head->mod[i]->and[j];
		pmod_head->mod[i]->and[j]->next=pdata_new;
}

void find(pmod pmod_head)
{
		int data;
		int i,j;
		pdata palit;
		printf("输入要查找的数\n");
		scanf("%d",&data);
		i=data%5;
		j=(data>>3)&7;
		for(palit=pmod_head->mod[i]->and[j]->next;palit!=pmod_head->mod[i]->and[j];palit=palit->next)
		{
					if(palit->data==data)
					{
							printf("存在%d\n",palit->data);
							return ;
					}
		}
		printf("不存在\n");

}

void myfree(pmod pmod_head)
{
		int i,j;
		for(i=0;i<5;i++)
		{
				for(j=0;j<8;j++)
				{
						pdata palit=pmod_head->mod[i]->and[j]->next;
						while(palit!=pmod_head->mod[i]->and[j])
						{
								palit->prev->next=palit->next;
								palit->next->prev=palit->prev;
								palit->next=palit;
								palit->prev=palit;
								if(palit!=NULL)
								{
										free(palit);
										palit=NULL;
								}
								palit=pmod_head->mod[i]->and[j]->next;
						}
						if(pmod_head->mod[i]->and[j]!=NULL)
						{
								free(pmod_head->mod[i]->and[j]);
								pmod_head->mod[i]->and[j]=NULL;
						}
				}
				if(pmod_head->mod[i]!=NULL)
				{
						free(pmod_head->mod[i]);
						pmod_head->mod[i]=NULL;
				}
		}
		
}

int main()
{
		int sum;
		pmod pmod_head;
		gmod_memoty(&pmod_head);
		mod_and_data(pmod_head);
		while(1)
		{
				printf("1.输入  2查找  3退出\n");
				scanf("%d",&sum);
				switch(sum)
				{
						case scan_:
								scan(pmod_head);
								break;
						case find_:
								find(pmod_head);
								break;
						case exit_:
								myfree(pmod_head);
								exit (-1);
								break;
				}
		}
}
