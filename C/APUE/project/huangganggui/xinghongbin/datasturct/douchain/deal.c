
#include"chain.h"

int create_chain(pSode p_head)
{
		pSode p=NULL;
		int ret;
		int ch;

		chain_init(&p);
		create_memory((pSode *)&p->name,20);
		printf("input id name gender age\n");


		do
		{
				
				while(getchar() != '\n');
				printf("input your   id  :");
				while(((ch = getchar() ) != EOF) && integer(ch))
				{
						printf("\nThe type is char \ninput your  id  :");
				}
				ungetc(ch,stdin);
				scanf("%d",&p->id);  
				ret=find_repet(p_head,p->id);
		}while(ret == -1);


		while(getchar() != '\n');
		printf("input your name  :");
		scanf("%s",p->name);  


		while(getchar() != '\n');
		printf("input your gender:");
		scanf("%c",&p->gender);
		
		do
		{
				while(getchar() != '\n');
				printf("input your age   :");
				while(((ch = getchar() ) != EOF) && integer(ch))
				{
						printf("\nThe type is char \ninput your age  :");
				}
				ungetc(ch,stdin);
				scanf("%d",&p->age);
		}while(0 > p->age);


		while(getchar() != '\n');
		insert_chain(p_head,p);
		return 1;


}
int integer(int ch)
{
		if((ch>='0')&&(ch<='9'))
						return 0;
}
int insert_chain(pSode p_head,pSode p_insert)
{
		pSode p_temp = p_head->next;
		pSode p_pro = p_head;
		while((p_temp != NULL))		
		{

				if(((p_temp->id > p_insert->id)&& (p_pro->id <= p_insert->id)))
				{
						p_pro->next = p_insert;
						p_insert->next = p_temp;
						return 1;
				}
				p_pro = p_temp;
				p_temp = p_pro->next;

		}
		printf("------------------\nThis   id is   max|\ninsert chain tiall|\n------------------\n");
		p_pro->next = p_insert;
		
}
int find_repet(pSode p_head,int id)
{
		pSode p_search = p_head;
		while(p_search != NULL)
		{
				if(p_search->id == id)
				{
						
						printf("this id is repet this (%d %s %d %c )\nplease input again\n",p_search->id,p_search->name,p_search->age,p_search->gender);
						return -1;
				}
				p_search=p_search->next;

		}

}
int search_chain(pSode p_head)
{
		int search;
		int ret=0;
		pSode p_search = p_head;
		printf("input you search age\n");
		scanf("%d",&search);
		while(p_search != NULL)
		{
				if(p_search->age == search)
				{
						printf("%d %s %d %c \n",p_search->id,p_search->name,p_search->age,p_search->gender);
						ret=1;
				}
				p_search=p_search->next;

		}
		if(ret == 0)
		{
				printf("NO age\n");
		}

}
int save_chain(pSode p_head)
{
		
		pSode p_temp;
		p_temp = p_head->next;
		FILE * fp;
		int len=sizeof(struct node);
		fp=fopen("a","w");
		while(p_temp != NULL)
		{
				fwrite(p_temp,1,len,fp);
				p_temp = p_temp->next;
		}
		printf("save ok\n");
		fclose(fp);
		return 0;

}
void output_chain(pSode p_head)
{
		printf("\n");
		pSode p_temp;
		p_temp=p_head->next;
		while(p_temp != NULL)
		{
				printf("%d %s %d %c \n",p_temp->id,p_temp->name,p_temp->age,p_temp->gender);
				p_temp=p_temp->next;

		}

}

void get_file()
{
		pSode p_fhead;
		chain_init(&p_fhead);
		pSode p;
		pSode p_pro=p_fhead;
		
		FILE * fp;
		int len=sizeof(struct node);
		int flen,i;
		fp=fopen("a","r");
		fseek(fp,0,SEEK_END);
		flen=ftell(fp);
		rewind(fp);
		printf("%d  len%d\n",flen,len);
		for(i=0;i<flen;i+=len)
		{
				chain_init(&p);
				fread(p,1,len,fp);
				p_pro->next = p;
				p_pro = p;
//			   printf("-read--\n");	
		}
		fclose(fp);
		output_chain(p_fhead);
		findtiall(&p_fhead);



}
void exit_chain(int save,pSode p_head)
{
		char save_che;
		char exit_che;
		printf("do you want exit?y/n\n");
		while(getchar() != '\n');
		scanf("%c",&exit_che);
		if(exit_che == 'y')
		{
				if(save == 1)
				{
						printf("you donot save you want save?y/n\n");

						while(getchar() != '\n');
						scanf("%c",&save_che);
						if(save_che == 'y')
								save_chain(p_head);
				}
		}

		else
				menu_chain(p_head);
		printf("bye bye\n");


}
