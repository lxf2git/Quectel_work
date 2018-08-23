#include"chain.h"
int main()
{
		pSode p_head=NULL;
		chain_init(&p_head);
		menu_chain(p_head);
		findtiall(&p_head);


}
void menu_chain(pSode p_head)
{
		int choose;
		int ret;
		int save=1;
		do
		{
				
				printf("                   -------------------\n");
				printf("------------------>");
				printf("please choose  way|\n");
				printf(" student           1  chain INPUT    |\n");
				printf("                   2  chain SEARCH   |\n");
				printf("     management    3  chain SAVE     |\n");
				printf("                   4  chain OUTPUT   |\n");
				printf("           system  5  chain EXIT     |\n");
				printf("                   -------------------\n");

				printf("plese input choose:");
				ret=scanf("%d",&choose);
				switch(choose)
				{
						case INPUT: 
								save=create_chain(p_head);
								break;
						case INSERT:
								search_chain(p_head);
								break;
						case SAVE:
								save=save_chain(p_head);
								get_file();
								break;
						case PRINTF:
								output_chain(p_head);
								break;
						case EXIT:
								exit_chain(save,p_head);
								return;
								break;
						default:
								printf("input error\n");
								break;				
				}

		}while(ret !=0);
		printf("input error\n");


}
void chain_init(pSode *p)
{
		create_memory(p,sizeof(struct node));
		(*p)->next=NULL;

}
void create_memory(pSode *p,int size)
{
		*p=(pSode)malloc(size);
}


void findtiall(pSode *p_pro)
{
		
		pSode p_tiall ;
		p_tiall=(*p_pro)->next;

		while(p_tiall != NULL)
		{
				 findtiall(&p_tiall);

		}
		printf("->free->free->free->free->free--\n");
		myfree(p_pro);


}

void myfree(pSode *p)
{
		if(*p != NULL)
		{
				free(*p);
				*p=NULL;
		}
}
/*
void insert_chain(pSode p_head,pSode p_tiall)
{
		int choose;
		printf("input your chain \n");
		pSode p_insert;
		chain_init(&p_insert);
		create_memory((pSode*)&p_insert->name,20);
		scanf("%d",&p_insert->date);
//		scanf("%d%s%d",&p_insert->date,p_insert->name,&p_insert->sce);
//		printf("%d %s %d\n",p_insert->date,p_insert->name,p_insert->sce);
		printf("please choose insert of way\n");
		printf("1 insert head\n");
		printf("2 insert tiall\n");
		printf("3 insert custom\n");
		scanf("%d",&choose);
		switch(choose)
		{
				case 1: 
						p_insert->next = p_head->next;
						p_head->next = p_insert;
						break;
				case 2:
						p_tiall=p_head;
						while(p_tiall->next->next !=NULL)
						{
								p_tiall = p_tiall->next; 
						}
						p_tiall->next = p_insert;
						break;
				case 3:
						insert_custom(p_head,p_insert);
						break;
				default:
						printf("input error\n");
						break;				
		}


}

int  del_chain(pSode p_head)
{
		int goal;
		printf("input you want del_chain num\n");
		scanf("%d",&goal);
		pSode p_goal = (p_head)->next;
		pSode p_pro =p_head;
		while(p_pro->next != NULL)		
		{
				if(p_goal->date == goal)
				{
						p_pro->next = p_goal->next;
						p_goal->next = NULL;
						printf("del-----chain_date= %d\n",p_goal->date);
						myfree(&p_goal);
						return 0;
				}
				p_pro=p_goal;
				p_goal= p_pro->next;

		}
		printf("No have chain\n");


}
*/
