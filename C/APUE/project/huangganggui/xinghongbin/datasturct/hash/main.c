#include"main.h"
int main()
{
		pMod pClass;
		mod_init(&pClass);
		menu(pClass);
//		deal_mod(pClass,myfree);

}
void menu(pMod pClass)
{
		int choose;
		int ret = 0;
		do
		{
				printf("1 Insert 2 find 3 output");
				ret = scanf("%d",&choose);
				if(ret ==1 )
				switch(choose)
				{
						case 1:
								create_chain(pClass);
								break;
						case 2:
								find_number(pClass);
								break;
						case 3:
								deal_mod(pClass,output);
								break;
						default:
								printf("input error\n");
								exit(-1);		

				}

		}while(ret != 0);

}
void mod_init(pMod *p)
{
		int i;
		create_memory((void**)p,sizeof(sMod));
		for(i=0;i<5;i++)
		{
//				create_memory((void **)& ((*p)->mod[i]) ,sizeof(sMod));
				and_init(&(*p)->mod[i]);
		}
}
void and_init(pAnd *p)
{
		int i;
		create_memory((void **)p,sizeof(sAnd));
		for(i=0;i<8;i++)
		{
//				create_memory((void **)& ((*p)->and_[i]),sizeof(sAnd));
				chain_init(&(*p)->and_[i]);
		}
}
void chain_init(pNode *p)
{
		create_memory((void **)p,sizeof(sNode));
		(*p)->next = (*p);
		(*p)->prev = (*p);
}
void create_memory(void**p,int size)
{
		*p = malloc(size);
}
void output(pNode pHead)
{
		pNode pTemp =pHead->next;
		while(pTemp !=pHead)
		{
				printf("%3d ",pTemp->data);
				pTemp = pTemp->next;
		}
		printf("\n");
}
void deal_mod(pMod pClass,void (*p)(pNode pHead))
{
		int i,j;
		for(i=0;i<5;i++)
				for(j=0;j<8;j++)
				{
						printf("mod[%d]and[%d]\n",i,j);
						p(pClass->mod[i]->and_[j]);
				}
}
void myfree(pNode pHead)
{
		pNode pTemp =pHead->next;
		while(pTemp !=pHead)
		{
				if(pTemp != NULL)
				{
						free(pTemp);
						pTemp = NULL;
				}
				else
				{
						printf("free again\n");
				}
				pTemp = pHead->next;
				printf("free---free\n");
		}
		
}
