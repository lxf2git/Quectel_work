#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
		int data;
		struct Node *prev;
		struct Node *next;
}sNode,*pNode;
void Deatory_deat(pNode *pdel);

void gmgeory(pNode *palit,int size)
{
		*palit = malloc(size);
}

void init_Node(pNode *palit,int size)
{
		gmgeory(palit,size);
		(*palit)->next=(*palit);
		(*palit)->prev=(*palit);

}

pNode print_lad(pNode pHead,pNode pNew)
{
		pNode palit=pHead;
		while(palit->next!=pHead)
		{
				if(palit->next->data >= pNew->data)
				{
						return palit;
				}
				palit=palit->next;
		}
		return palit;

}

int input_back(pNode pSort,pNode pNew)
{
		if(pSort==NULL||NULL==pNew)
		{
				printf("pSort||pNew为空\n");
				exit (-1);
		}
		pSort->next->prev=pNew;
		pNew->prev=pSort;
		pNew->next = pSort->next;
		pSort->next=pNew;	
		return 0;
}


void scan(pNode pHead,int i)
{
		pNode pNew;
		for(i;i>0;i--)
		{
		init_Node(&pNew,sizeof(sNode));
		printf("请输入data\n");
		scanf("%d",&pNew->data);
		pNode palit=print_lad(pHead,pNew);
		input_back(palit,pNew);
		}
}

del_del(pNode pHeadA,pNode pHeadB,int data)
{

		pNode palitA=pHeadA->next;
		pNode palitB=pHeadB->next;
		while(palitA!=pHeadA)
		{
				if(palitA->data==data)
				{
						palitA->prev->next=palitA->next;
						palitA->next->prev=palitA->prev;
						palitA->prev=palitA;
						palitA->next=palitA;
						Deatory_deat(&palitA);
						palitA=pHeadA;

				}
				palitA=palitA->next;
		}
		while(palitB!=pHeadB)
		{
				if(palitB->data==data)
				{
						palitB->prev->next=palitB->next;
						palitB->next->prev=palitB->prev;
						palitB->prev=palitB;
						palitB->next=palitB;
						Deatory_deat(&palitB);
						palitB=pHeadB;
				}
				palitB=palitB->next;
		}
}



void del(pNode pHeadA,pNode pHeadB)
{
		pNode palitA=pHeadA->next;
		pNode palitB=pHeadB->next;
		while(palitA!=pHeadA)
		{
				while(palitB!=pHeadB)
				{
						if(palitA->data==palitB->data)
						{
								printf("del_del\n");
								del_del(pHeadA,pHeadB,palitA->data);
								printf("del_del  ok\n");
								palitA=pHeadA->next;
								if(palitA==pHeadA)
								{
									break;
								}
								palitB=pHeadB->next;
						}
						else
						{
								palitB=palitB->next;
						}
				}
				palitA=palitA->next;
	            palitB=pHeadB->next;
		}
}

void print_(pNode pHead)
{
			pNode ptmp=NULL;
#if 1
			for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
			{
						printf(" %d\n",ptmp->data);
			}
			puts("=======================");
#endif
#if 0
			for(ptmp=pHead->prev;ptmp!=pHead;ptmp=ptmp->prev)
			{
						printf(" %d\n",ptmp->data);
			}

			puts("=======================");
#endif
}

void Deatory_deat(pNode *pdel)
{
		if(*pdel!=NULL)
		{
				free(*pdel);
				*pdel=NULL;
		}
}

void Destory_list(pNode *pHead)
{
		pNode pdel=NULL;
		while((*pHead)->next!=NULL)
		{
				pdel=(*pHead)->next;
				pdel->next->prev=pdel->prev;
				(*pHead)->next=(*pHead)->next->next;
				pdel->next=NULL;
				pdel->next=NULL;
				Deatory_deat(&pdel);
		}
}

int main()
{
		int i;
		pNode pHeadA;
		pNode pHeadB;
		init_Node(&pHeadA,sizeof(sNode));
		init_Node(&pHeadB,sizeof(sNode));
		printf("请给A链赋值\n");
		printf("输入赋值次数\n");
		scanf("%d",&i);
		scan(pHeadA,i);
		printf("请给B链赋值\n");
		printf("输入赋值次数\n");
		scanf("%d",&i);
		scan(pHeadB,i);
		printf("赋值完成正在查重\n");
		del(pHeadA,pHeadB);
		printf("完成\n");
		printf("pHeadA\n");
		print_(pHeadA);
		Destory_list(&pHeadA);
		printf("pHeadB\n");
		print_(pHeadB);
		Destory_list(&pHeadB);
		 

}

