#include"str.h"
//#include"stack.h"
void output(pSig pHead,int *p);
void delete_chain(pSig pDel);
int calulate(int bf,char sign,int af);
void deal(pSig pHead,int *data,pSig pTaill);
pSig wipe_off(pSig pHead,int *data);
int main()
{
//		pSta p;	
		int *data;
		pSig pHead;
		char *argv[2];
		argv[1] = (char *)malloc(50);
		gets(argv[1]);

//		stack_init(&p);
		chain_init(&pHead);
		create_memory((void**)&data,strlen(argv[1])*sizeof(int));

		sort_char(argv,data,pHead);
		output(pHead,data);
		wipe_off(pHead,data);
//		output(pHead,data);
		deal(pHead,data,pHead);

}
void output(pSig pHead,int *data)
{
		pSig p=pHead->next;
		while(p != pHead)
		{

				p->bf = data[p->number];
				p->af = data[p->number+1];
				printf("%d %d %d\n",p->bf,p->sign,p->af);

				p = p->next;
		}
		printf("-----------------------------\n");
}
pSig wipe_off(pSig pHead,int *data)
{
		pSig p =pHead->next;
		pSig pTemp;
		while(p != pHead )
		{
				if(sign_priority(p->sign) == 1)
						p = wipe_off(p,data);
				if(sign_priority(p->sign) == 2)
				{
						deal(pHead,data,p);
				//		if(pHead->prev != pHead)
				//		{
								pTemp = pHead->prev;
//								printf("pHead->af %d prev->af %d\n",pHead->af,pHead->prev->af);
								pHead->prev->af = pHead->af;
//								printf("pHead->af %d prev->af %d\nprev->bf %d\n",pHead->af,pHead->prev->af,pHead->prev->bf);
								delete_chain(pHead);
								p->next->bf = p->bf;
								delete_chain(p);
				//		}
						return pTemp;
				}	
				p = p->next;
		}

}
void deal(pSig pHead,int *data,pSig pTaill)
{
		int sum;
		pSig p =pHead->next;
		while(p != pTaill )
		{
				if(sign_priority(p->sign) == 3)
				{

						sum = calulate(p->bf,p->sign,p->af);
						printf("%d %c %d=%d\n",p->bf,p->sign,p->af,sum);
						p->prev->af = sum;
						p->next->bf = sum;

						delete_chain(p);
						p = pHead;

				}
				p = p->next;
		}
		p = pHead->next;
		while(p != pTaill )
		{
				if(sign_priority(p->sign) == 4)
				{

						sum = calulate(p->bf,p->sign,p->af);
						printf("%d %c %d=%d\n",p->bf,p->sign,p->af,sum);
						p->prev->af = sum;
						p->next->bf = sum;

						delete_chain(p);
						p = pHead;

				}
				p = p->next;
		}


}

int calulate(int bf,char sign,int af)
{

		switch(sign)
		{
				case '+':
						return bf+af;
				case '-':
						return bf-af;
				case '*':
						return bf*af;		
				case '%':
						return bf%af;
		}
}

void delete_chain(pSig pDel)
{
		pDel->prev->next = pDel->next;
		pDel->next->prev = pDel->prev;
		pDel->next = NULL;
		pDel->prev = pDel;
}
