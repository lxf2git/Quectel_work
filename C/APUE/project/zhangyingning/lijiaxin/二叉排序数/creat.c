#include"tree_sort.h"

int i;
void get_memory(void **p,int size)
{
		*p = malloc(size);
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
void init_tree(pTree *p)
{
		get_memory((void **)p,sizeof(sTree));
		(*p)->tr_data = ' ';
		(*p)->tr_lc = NULL;
		(*p)->tr_rc = NULL;
		
}
void creat_tree_chain(pTree root,pTree pnew)
{
		if(root->tr_data >= pnew->tr_data)
		{
				if(root->tr_lc!=NULL)
				{
						creat_tree_chain(root->tr_lc,pnew);
				}
				else
				{
						root->tr_lc = pnew;
						return ;
				}
		}
		if(root->tr_data < pnew->tr_data)
		{
				if(root->tr_rc!=NULL)
				{
						creat_tree_chain(root->tr_rc,pnew);
				}
				else
				{
						root->tr_rc = pnew;
						return ;
				}
		}
}
void creat_tree(pTree pHead,char *str,int n)
{
		int i;
		pTree ptmp = NULL;
		if(str[0]==' ')
		{
				printf("error!\n");
				exit(-1);
		}
		pHead->tr_data = str[0];
		for(i=1;i<n;i++)
		{
				init_tree(&ptmp);
				ptmp->tr_data = str[i];
				creat_tree_chain(pHead,ptmp);
				ptmp = NULL;			
		}
}
int creat_(pTree pHead)
{
		char *str=NULL;
		str = (char *)malloc(SIZE*sizeof(char));
		printf("请输入需要建树的字符串(长度小于50)\n");
		getchar();
		gets(str);
		creat_tree(pHead,str,strlen(str));
}
