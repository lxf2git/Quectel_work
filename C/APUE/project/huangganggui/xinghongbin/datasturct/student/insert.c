#include"chain.h"
void create_chain(pStu pHead ,pList plist)
{
		int ret;
		pStu p;
		chain_init(&p);
		plist->pInsert = chain_insert;
		p->stu_input = input_fun;
		do
		{
				p->stu_input(p);
				ret = plist->pInsert(pHead ,p , id_find , insert_position);
		}while(ret == -1);

}
int input_fun(pStu p)
{
		printf("input id:");
		scanf("%d",&p->id);
		printf("input age :");
		scanf("%d",&p->age);
		return 0;
		

}
int chain_insert ( pStu pHead , pStu pInsert , pIDFind pid, pInsertp pspiont)
{
		int ret;
		pStu pPro;
		ret = pid(pHead,pInsert);
		if(ret == -1)
				return -1;
		else
		{
				pPro = pspiont(pHead , pInsert);
				pInsert->next = pPro->next;
				pPro->next = pInsert;
				

		}
		return 0;



}
int id_find ( pStu pHead , pStu pInsert )
{
		pStu pTemp = pHead;
		while(pTemp != NULL)
		{
				if(pTemp->id == pInsert->id)
				{
						
						printf("this id is repet this (%d %d)\nplease input again\n",pTemp->id,pTemp->age);
						return -1;
				}
				pTemp=pTemp->next;

		}
		return 0;

}

pStu insert_position( pStu pHead , pStu pInsert)
{
		pStu pTemp = pHead->next;
		pStu pPro = pHead;
		while((pTemp != NULL))		
		{

				if(((pTemp->id > pInsert->id)&& (pPro->id < pInsert->id)))
				{
//						p_pro->next = p_insert;
//						p_insert->next = p_temp;
						return pPro;
				}
				pPro = pTemp;
				pTemp = pPro->next;

		}
		printf("------------------\nThis   id is   max|\ninsert chain tiall|\n------------------\n");
		return pPro;
		
}
	

void chain_output(pStu pHead)
{
		pStu p;
		p=pHead->next;
		pHead->next;
		while(p != NULL)
		{
				p->stu_print = output_fun;
				p->stu_print(p);
				p=p->next;
		}

}
void output_fun(pStu p)
{
				printf("id:%d age:%d\n",p->id,p->age);
}

