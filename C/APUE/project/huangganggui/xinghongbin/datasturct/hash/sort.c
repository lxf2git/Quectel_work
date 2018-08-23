#include"main.h"
void create_chain(pMod pClass)
{
		int number;
		int ret=0;
		pNode p;
		do
		{
				printf("input number\n");
				ret = scanf("%d",&number);
				if(ret == 1)
				{
						chain_init(&p);
						p->data = number;
						insert_chain(pClass->mod[number%5]->and_[number>>3&7] , p);

				}
		}while(ret !=0 );
		getchar();


}
void insert_chain(pNode pHead,pNode pInsert)
{
		pInsert->next = pHead;
		pInsert->prev = pHead->prev;
		pHead->prev->next = pInsert;
		pHead->prev = pInsert;
}

void find_number(pMod pClass)
{
		int number;
		printf("find you number\n");
		scanf("%d",&number);
		find_fun(pClass->mod[number%5]->and_[number>>3&7] ,number);

}
void find_fun(pNode pHead,int number)
{
		int ret =0;
		pNode pTemp = pHead->next;
		while(pTemp != pHead)
		{
				if(pTemp->data == number)
				{
						printf("%d\n",pTemp->data);
						ret = 1;
				}
				pTemp = pTemp->next;
		}
		if(ret == 0)
				printf("No number\n");
}
