#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
	int data;
	struct data *prev;
	struct data *next;
}sDat,*pDat;

typedef struct and
{
	struct data *and[8];
}sAnd,*pAnd;

typedef struct mod
{
	struct and *mod[5];
}sMod,*pMod;

void creat_memory(pDat *p)
{
	*p = malloc(sizeof(sDat));
}

void init_memory(pDat *p)
{
	creat_memory(p);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}	

void insert(pDat pHeadD,pDat pNewD)
{
	pNewD->prev=pHeadD->prev;
	pHeadD->prev->next=pNewD;
	pNewD->next=pHeadD;
	pHeadD->prev=pNewD;
}

int main()
{
	int m=0;
	pDat pHeadD,pNewD;
	init_memory(&pHeadD);
  /****数据录入****/
	while(m==0)
	{
		printf("please input data:\n");
		init_memory(&pNewD);
		scanf("%d",&pNewD->data);

		insert(pHeadD,pNewD);
		printf("End input 1:Yes 0:No!\n");
		scanf("%d",&m);
	}
  
	pMod pmod;
	pmod = malloc(sizeof(sMod));
		printf("1************\n");

	int i,j;
	for(i=0;i<5;i++)
	{
		pmod->mod[i] = malloc(sizeof(sAnd));
		//pand = malloc(sizeof(sAnd));
		for(j=0;j<8;j++)
		{
		printf("%d************\n",i*j);
		init_memory(&(pmod->mod[i]->and[j]));
			//pmod->mod[i]->and[j]->data=i*j;
		}
	}

	pDat ptmp;
	for(ptmp=pHeadD->next;ptmp!=pHeadD;)
	{
		i=ptmp->data%5;
		j=ptmp->data>>3&7;
		
		ptmp->next->prev=ptmp->prev;
		ptmp->prev->next=ptmp->next;
		ptmp->next=ptmp;
		ptmp->prev=ptmp;
		printf("%d***%d*\n",i*j,ptmp->data);

		pmod->mod[i]->and[j]->prev->next=ptmp;
	printf("%d************\n",i*j);
		ptmp->prev=pmod->mod[i]->and[j]->prev;
		pmod->mod[i]->and[j]->prev=ptmp;
		ptmp->next=pmod->mod[i]->and[j];
		
		ptmp=pHeadD->next;
	}
	int l=0;
while(l==0)
{
	int data;
	printf("please data to search!\n");
	scanf("%d",&data);
	
	i=data%5;
	j=data>>3&7;
	int r=0;
	for(ptmp=pmod->mod[i]->and[j]->next;ptmp!=pmod->mod[i]->and[j];ptmp=ptmp->next)
	{
		if(ptmp->data==data)
		{
			r=1;
			printf("matrix-data:%d\n",ptmp->data);
		}
	}
	if(r==0)
	{
		printf("no data search\n");
	}
	printf("continue search 0:yes 1:no\n");
	scanf("%d",&l);
}
}






