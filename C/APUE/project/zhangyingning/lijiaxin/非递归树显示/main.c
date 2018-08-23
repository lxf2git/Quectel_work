/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
	char tr_data;
	struct tree *tr_lc;
	struct tree *tr_rc;
}sTree,*pTree;*/
#include"stack_chain.h"
int i;
void get_memory(pTree *p,int size)
{
		*p = malloc(size);
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
void init_tree(pTree *pHead)
{
		get_memory(pHead,sizeof(sTree));
		(*pHead)->tr_data =' ';
		(*pHead)->tr_lc = NULL;
		(*pHead)->tr_rc = NULL;
}
void creat_tree_chain(char *str,pTree pbefore)
{
		if(str[++i]!=' ')
		{
				pTree ptmp = NULL;
				init_tree(&ptmp);
				ptmp->tr_data = str[i];
	//			printf("tr_lc:%c\n",ptmp->tr_data);
				pbefore->tr_lc = ptmp;
				creat_tree_chain(str,ptmp);
				
		}
		if(str[++i]!=' ')
		{
				pTree ptmp = NULL;
				init_tree(&ptmp);
				ptmp->tr_data = str[i];
	//			printf("tr_rc:%c\n",ptmp->tr_data);
				pbefore->tr_rc = ptmp;
				creat_tree_chain(str,ptmp);
		}
}
void creat_tree(pTree pHead,char *str,int n)
{
		if(str[0]==' ')
		{
				printf("error!\n");
				exit(-1);
		}
		pHead->tr_data = str[0];
		creat_tree_chain(str,pHead);
		
}
void prev_tree(pTree root)
{
#if 0
		printf("%c",root->tr_data);
		if(root->tr_lc!=NULL)
		{
				prev_tree(root->tr_lc);
		}
		if(root->tr_rc!=NULL)
		{
				prev_tree(root->tr_rc);
		}
#endif
		sStack sta;
		init_stack(&sta);
		pTree p = root;
		while(p!=NULL || EMPTY!=is_empty(&sta))
		{
				while(p!=NULL)
				{
						printf("%c ",p->tr_data);
						push(&sta,p);
						p = p->tr_lc;
				}
				p = pop(&sta);
				p = p->tr_rc;
		}

}

void mid_tree(pTree root)
{
#if 0
	 	if(root->tr_lc!=NULL)
		{
				mid_tree(root->tr_lc);
		}
		printf("%c",root->tr_data);
		if(root->tr_rc!=NULL)
		{
				mid_tree(root->tr_rc);
		}
#endif
		sStack sta;
		init_stack(&sta);
		pTree p = root;
		while(p!=NULL || EMPTY!=is_empty(&sta))
		{
				while(p!=NULL)
				{
						push(&sta,p);
						p = p->tr_lc;
				}
				p = pop(&sta);
				printf("%c ",p->tr_data);
				p = p->tr_rc;
		}
}
void last_tree(pTree root)
{
#if 0
		if(root->tr_lc!=NULL)
		{
				last_tree(root->tr_lc);
		}
		if(root->tr_rc!=NULL)
		{
				last_tree(root->tr_rc);
		}
		printf("%c",root->tr_data);
#endif
#if 1
		sStack sta;
		init_stack(&sta);
		pTree p = root;
		pTree have_visited = NULL;
		while(p!=NULL || EMPTY!=is_empty(&sta))
		{
				while(p!=NULL)
				{
						push(&sta,p);
						p = p->tr_lc;
				}
				p = get_stack_top(&sta);
				if(NULL==p->tr_rc || have_visited==p->tr_rc)
				{
						p = pop(&sta);
						printf("%c ",p->tr_data);
						have_visited = p;
						p = NULL;
				}
			   else
			   {
						p = p->tr_rc;
			   }
		}
#endif
}
void show_tree(pTree pHead)
{
		prev_tree(pHead);
		printf("\n*************\n");
		mid_tree(pHead);
		printf("\n&&&&&&&&&&&&&&&&&&&\n");
		last_tree(pHead);
}

int main()
{
		char str[]="ABD  E  C FG   ";
	//	char *str=NULL;
	//	int longth;
	//	printf("请输入字符串长度.\n");
	//	scanf("%d",&longth);
	//	getchar();
	//	str = (char *)malloc(longth*sizeof(char)); 
		pTree pHead=NULL;
	//	printf("请输入一个字符串.\n");
	//	gets(str);
		init_tree(&pHead); 
		creat_tree(pHead,str,strlen(str));
		show_tree(pHead);
		printf("\n");
	//	my_free(&pHead);
		return 0;
}

