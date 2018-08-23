#include"tree_sort.h"
pTree mid_find(pTree root,char ch,pTree *parent,int *flag)
{
		while(1)
		{
				if(ch > root->tr_data)
				{
						*flag = 2;
						*parent = root;
						root = root->tr_rc;
				}
		   else
				if
				(ch < root->tr_data)
				{
						*flag = 1;
						*parent = root;
						root = root->tr_lc;
				}
				else
				{
						return root;
				}
		}
}
pTree remake_tree_chain(pTree root,pTree *parent1,int *flag1)
{
		while(1)
		{
				if(root->tr_lc!=NULL)
				{
						*parent1 = root;
						*flag1 = 1;
						root = root->tr_lc;
				}
				else
				{
						return root;
				}
		}
}
void remake_tree(pTree root,pTree parent,int flag)
{
		pTree ptmp = NULL;
		if((root->tr_lc==NULL)&&(root->tr_rc==NULL))
		{
				if(flag == 1)
				{
						parent->tr_lc = NULL;
				}
				if(flag == 2)
				{
						parent->tr_rc = NULL;
				}
				free(root);
				root = NULL;
		}
		else	
			if((root->tr_lc==NULL&&root->tr_rc!=NULL)||(root->tr_lc!=NULL&&root->tr_rc==NULL))
		{
				if(root->tr_lc==NULL)
				{
						ptmp = root->tr_rc;
				}
				else
				{
						ptmp = root->tr_lc;
				}
				if(flag == 1)
				{
						parent->tr_lc = ptmp;
				}
				if(flag == 2)
				{
						parent->tr_rc = ptmp;
				}

				free(root);
		}
		else
		{
				pTree parent1=NULL;
				int flag1=0;
				ptmp = remake_tree_chain(root->tr_rc,&parent1,&flag1);
				printf("   ptmp:%c \n",ptmp->tr_data);
				if(parent==NULL)
				{
						if(flag1==0)
						{	
								ptmp->tr_lc = root->tr_lc;
						}
						else
						{
								parent1->tr_lc = ptmp->tr_rc;
								ptmp->tr_lc = root->tr_lc;
								ptmp->tr_rc = root->tr_rc;
								*p = ptmp;
						}
				}
				else
				{
						if(flag==1)
						{
								parent->tr_lc = ptmp;
								if(flag1==0)
								{
										ptmp->tr_lc = root->tr_lc;
								//		ptmp->tr_rc = root->tr_rc;
								}
								else
								{
										parent1->tr_lc = ptmp->tr_rc;
										ptmp->tr_lc = root->tr_lc;
										ptmp->tr_rc = root->tr_rc;
								}
						}
						if(flag==2)
						{
								parent->tr_rc = ptmp;
								if(flag1==0)
								{
										ptmp->tr_lc = root->tr_lc;
								//		ptmp->tr_rc = root->tr_rc;
								}
								else
								{
										parent1->tr_lc = ptmp->tr_rc;
										ptmp->tr_lc = root->tr_lc;
										ptmp->tr_rc = root->tr_rc;
								}
						}

				}
				free(root);
				root=NULL;
		}

}
int delete_(pTree pHead)
{
		printf("请输入需要删除的字符\n");
		getchar();
		char ch;
		scanf("%c",&ch);
		pTree pfind = NULL;
		pTree pf = NULL;
		int flag=0;
		pfind = mid_find(pHead,ch,&pf,&flag);
		printf("pfind:%c ",pfind->tr_data);
		remake_tree(pfind,pf,flag);
}
