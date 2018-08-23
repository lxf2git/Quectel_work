
#include"queue.h"
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
				pbefore->tr_lc = ptmp;
				creat_tree_chain(str,ptmp);
				
		}
		if(str[++i]!=' ')
		{
				pTree ptmp = NULL;
				init_tree(&ptmp);
				ptmp->tr_data = str[i];
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

void paixu(pTree root)
{
		pQueue ppp=init_queue(sizeof(sQueue));
		push(ppp,root);
		pTree pdel=pop(ppp);
		int i=5;
		while(pdel!=NULL)
		{
			printf("%c ",pdel->tr_data);
			push(ppp,pdel->tr_lc);
			push(ppp,pdel->tr_rc);
			pdel=pop(ppp);
		}
}	
void show_tree(pTree pHead)
{
		paixu(pHead);			
}
int main()
{
//		char str[]="ABD  E  C FG   ";
		char *str=NULL;
		int longth;
		printf("请输入字符串长度.\n");
		scanf("%d",&longth);
		getchar();
		str = (char *)malloc(longth*sizeof(char)); 
		pTree pHead=NULL;
	    printf("请输入一个字符串.\n");
		gets(str);
		init_tree(&pHead); 
		creat_tree(pHead,str,strlen(str));
		show_tree(pHead);
		printf("\n");
		free(pHead);
		return 0;
}

