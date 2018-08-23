#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct node 
{
		int id;
		struct node *prev;
		struct node *next;
}*pSode;
void chain_init(pSode *p);
void create_memory(pSode *p,int size);
void douinsert_chain(pSode p_head);
//void headinsert_chain(pSode p_head);
//void rank_chain(pSode p_temp);
//void del_chain(pSode p);
void print_chain(pSode p_head);
void insert_chain(pSode p_head,pSode p_insert);
int main()
{
		pSode p_head;
		chain_init(&p_head);
//		headinsert_chain(p_head);
//		rank_chain(p_head);
		douinsert_chain(p_head);
		print_chain(p_head);

}
void chain_init(pSode *p)
{
		create_memory(p,sizeof(struct node));
		(*p)->next = *p;
		(*p)->prev = *p;

}

void create_memory(pSode *p,int size)
{
		*p=(pSode)malloc(size);
}
/*
void douinsert_chain(pSode p_head)                         //tou cha
{
		pSode p;
		int i=0;
		for(i=0;i<N-1;i++)
		{
				chain_init(&p);
				printf("input id\n");
				scanf("%d",&p->id);
				

		}
//				printf("input id\n");
//				scanf("%d",&p_head->id);


}
*/

void douinsert_chain(pSode p_head)                   //wei cha 
{
		pSode p;
		int i=0;
		for(i=0;i<N-1;i++)
		{
				chain_init(&p);
				printf("input id\n");

				scanf("%d",&p->id);
/*				
#ifdef HHH
				p_head->prev->next = p;
				p->prev = p_head->prev;
				p_head->prev = p;
				p->next = p_head;
//#else 
				p->next = p_head->next;
				p_head->next->prev = p;
				p_head->next = p;
				p->prev = p_head;
#endif
*/
				insert_chain(p_head,p);

		}
//				printf("input id\n");
//				scanf("%d",&p_head->id);


}
void insert_chain(pSode p_head,pSode p_insert)
{
		pSode p = p_head->next;
		
		while(p != p_head)
		{
				if(p->id >= p_insert->id)
				{
						p_insert->next = p;
						p_insert->prev = p->prev;
						p->prev->next = p_insert;
					    p->prev = p_insert;
						return ;
						
				}
				p = p->next;

		}
		p_insert->prev = p->prev;
		p_insert->next = p;
		p->prev->next = p_insert;
		p->prev = p_insert;
		
}

void print_chain(pSode p_head)
{
		int i;
		pSode p = p_head->next;
		for(i=0;i<N-1;i++)
		{
				printf("%d\n",p->id);
				p = p->next;
		}
}

/*
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
}*/
