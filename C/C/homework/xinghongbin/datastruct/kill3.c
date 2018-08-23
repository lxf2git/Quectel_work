#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct node 
{
		int id;
		struct node *next;
}*pSode;
void chain_init(pSode *p);
void create_memory(pSode *p,int size);
void headinsert_chain(pSode p_head);
void rank_chain(pSode p_temp);
void del_chain(pSode p);
int main()
{
		pSode p_head;
		chain_init(&p_head);
		headinsert_chain(p_head);
		rank_chain(p_head);


}
void chain_init(pSode *p)
{
		create_memory(p,sizeof(struct node));
		(*p)->next = *p;

}

void create_memory(pSode *p,int size)
{
		*p=(pSode)malloc(size);
}
/*
void douinsert_chain(pSode p_head)
{
		pSode p;
		int i=0;
		for(i=0;i<N-1;i++)
		{
				chain_init(&p);
				printf("input id\n");
				scanf("%d",&p->id);
				p->next = p_head->next;
				p_head->next = p;
		}
				printf("input id\n");
				scanf("%d",&p_head->id);


}*/
void headinsert_chain(pSode p_head)
{

		pSode p;
		int i=0;
		for(i=0;i<N-1;i++)
		{
				chain_init(&p);
				printf("input id\n");
				scanf("%d",&p->id);
				p->next = p_head->next;
				p_head->next = p;
		}
				printf("input id\n");
				scanf("%d",&p_head->id);

}
void rank_chain(pSode p_temp)
{
		int i;
		for(i=1;p_temp->next != p_temp;i++)
		{
				if(i == 2 )
				{
						i=0;
				
				printf("kill___%d\n",p_temp->next->id);
				del_chain(p_temp);
				}			
				p_temp = p_temp->next;
				printf("%d\n",p_temp->id);

		}
		free(p_temp);
		printf("free\n");
//printf("%d\n",p_temp->id);
}

void del_chain(pSode p)
{
		pSode p_pro =p;
		p = p_pro->next;
		p_pro->next = p->next;
		p->next = NULL;
		free(p);
		printf("free\n");
//		p->next = p->next->next;

//		p->next->next = NULL;
}
