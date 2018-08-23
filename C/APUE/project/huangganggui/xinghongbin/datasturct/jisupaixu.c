#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
		int id;
		struct node *prev;
		struct node *next;
}*pNode;


void chainarry_init(pNode *p,int num);
void chain_init(pNode *p);
void create_memory(pNode *p,int size);
int create_chain(pNode pHead);
int id_highest(int num);
void play_card(pNode pDataHead,pNode *pHead,int higest);
void distribute(pNode pDataHead,pNode *pHead,int i,int higest);
void collected(pNode pHead,pNode pInsert);      //head->next; head->prev;
void chain_del(pNode pTemp);
void connect(pNode pHead,pNode p);
void chain_output(pNode pHead);
void chainarry_output(pNode *pHead);
int *resolve_id(int id,int higest);
void free_arry(pNode *p);
void free_fun(pNode *pHead);
int main()
{
		int higest;

		pNode pDataHead;
		chain_init(&pDataHead);

		pNode pHead[10];
		chainarry_init(pHead,10);

		higest = create_chain(pDataHead);
		chain_output(pDataHead);

		play_card(pDataHead,pHead,higest);
		chain_output(pDataHead);
		free_fun(&pDataHead);
				
		return 0;
}
void chainarry_init(pNode *p,int num)
{
		int i;
		for(i=0;i<num;i++)
		{
				chain_init(&p[i]);
				p[i]->id = i;
		//		printf("pHead[%d]->id=%d\n",i,p[i]->id);
			   	
		}

}
void chain_init(pNode *p)
{
		create_memory(p,sizeof(struct node));
		(*p)->prev = (*p);
		(*p)->next = (*p);

}

void create_memory(pNode *p,int size)
{
		(*p) = (pNode)malloc(size);
}
int create_chain(pNode pHead)
{
		int ret;
		int higest;
		pNode p;
		do
		{
				chain_init(&p);
				printf("input id\n");
				ret = scanf("%d",&p->id);
				if(ret != 0)
				{
						higest=id_highest(p->id);
						p->next = pHead->next;
						p->prev = pHead;
						pHead->next->prev = p;
						pHead->next = p;
				}
				else
				{
						free(p);
				}

		}while(ret != 0);
		return higest;

}
int id_highest(int num)
{
		static highest = 0;
		int i;
		for(i=0;num%10 != 0;i++)
		{
				num/=10;
		}
		if(highest < i)
				highest = i;
		return highest;
		

}
int *resolve_id(int id,int higest)
{
		int *p;
		p = malloc(20*sizeof(int));
		int i;
		for(i=0;i<higest;i++)
		{
				p[i] = id%10;
				id/=10;
		}
		return (int *)p;
}
void play_card(pNode pDataHead,pNode *pHead,int higest)
{
		int i,j;
		printf("%d\n",higest);
		for(j=0;j<higest;j++)
		{
				printf("bit%d\n",j+1);
				distribute(pDataHead,pHead,j,higest);
				chainarry_output(pHead);
				for(i=8;i>=0;i--)
				if(pHead[i]->next != pHead[i])
				{
						collected(pHead[9],pHead[i]);
				}
				pDataHead->next = pHead[9]->next;
				pDataHead->prev = pHead[9]->prev;
				pHead[9]->prev->next = pDataHead;
				pHead[9]->next->prev = pDataHead;

				pHead[9]->next = pHead[9];
				pHead[9]->prev = pHead[9];
				free_arry(pHead);
				chainarry_init(pHead,10);		
		}
}
void distribute(pNode pDataHead,pNode *pHead,int bit,int higest)
{
		int i;
		int *p;
		pNode pTemp=pDataHead->next;
				while(pTemp != pDataHead)
				{
						p = resolve_id(pTemp->id,higest);
						i = p[bit];
						chain_del(pTemp);
						connect(pHead[i],pTemp);
						pTemp = pDataHead->next;
/*						
						for(i=0;i<10;i++)
						{
							

								if( p[bit] == pHead[i]->id)
								{
										chain_del(pTemp);
										connect(pHead[i],pTemp);
										pTemp = pDataHead;
										break;
						



								}

						}
						
						pTemp = pTemp->next;
*/						

				}
}
void collected(pNode pHead,pNode pInsert)      //head->next; head->prev;
{
		pHead->next->prev = pInsert->prev;
		pInsert->prev->next = pHead->next;

		pHead->next = pInsert->next;
		pInsert->next->prev = pHead;

		pInsert->next = pInsert;
		pInsert->prev = pInsert;
}
void chain_del(pNode pTemp)
{
		pTemp->prev->next = pTemp->next;
		pTemp->next->prev = pTemp->prev;

}

void connect(pNode pHead,pNode p)
{
		p->next = pHead;
		p->prev = pHead->prev;
		pHead->prev->next = p;
		pHead->prev = p;
}
void chain_output(pNode pHead)
{
		pNode p= pHead->next;
		while(p != pHead)
		{
				printf("%d ",p->id);
				p = p->next;
		}
		printf("\n");
}
void chainarry_output(pNode *pHead)
{
		int i;
		for(i=0;i<10;i++)
		{
				printf("pHead[%d]:",i);
				chain_output(pHead[i]);
		}
}
void free_arry(pNode *p)
{
		int i;
		for(i=0;i<10;i++)
		{
				free_fun(&p[i]);
			

		}
}
void free_fun(pNode *pHead)
{
		pNode p = (*pHead)->next;
		while(p!= *pHead)
		{
				(*pHead)->next = p->next;
				p->next->prev = *pHead;
				p->next = p;
				p->prev = p;
				if(p == NULL)
				{
						printf("free error\n");
						exit(-1);
				}
				free(p);
				p = NULL;
				printf("free==free--free******\n");
				p = (*pHead)->next;
		}
		free(*pHead);
		printf("free==free--free******\n");

}
