#include<stdio.h>
#include<stdlib.h>


typedef struct tree
{
	int data;
	struct tree *parent;
	struct tree *lc;
	struct tree *rc;
}sTree,*pTree;

void create_memory(pTree *p)
{
	(*p)=(pTree)malloc(sizeof(sTree));
	if(*p==NULL)
	{
		printf("malloc error\n");
	}
}

void init_tree(pTree *p)
{
	create_memory(p);
	(*p)->parent=NULL;
	(*p)->lc=NULL;
	(*p)->rc=NULL;	
}

void compare(pTree root,pTree pnew)
{
	if(root->data>pnew->data)
	{
		if(root->lc!=NULL)
		{
			compare(root->lc,pnew);
		}
		else
		{
			root->lc=pnew;
			pnew->parent=root;
		}
	}
	else
	{
		if(root->rc!=NULL)
		{
			compare(root->rc,pnew);
		}
		else
		{
			root->rc=pnew;
			pnew->parent=root;
		}
	}
}

void creat_tree(pTree tr_root,pTree pnew)
{
	compare(tr_root,pnew);
}

void input(pTree tr_root)
{
	pTree pnew=NULL;
	init_tree(&pnew);
	printf("please input\n");
	scanf("%d",&pnew->data);
	creat_tree(tr_root,pnew);
}

void mid_tree(pTree root)
{
	if(root->lc!=NULL)
	{
		mid_tree(root->lc);
	}
	printf("%d ",root->data);
	if(root->rc!=NULL)
	{
		mid_tree(root->rc);
	}
}

void show(pTree root)
{
	mid_tree(root);
	printf("\n");
}

int remove_tree(pTree root,pTree ptmp,int i)
{
//	printf("%d ",i);
	if(ptmp->lc==NULL&&ptmp->rc==NULL)
	{
		if(ptmp->data<ptmp->parent->data)
		{
			ptmp->parent->lc=NULL;
		}
		else
		{
			ptmp->parent->rc=NULL;
		}
		return 1;
	}
	if(ptmp->lc!=NULL&&ptmp->rc==NULL)
	{
		if(i==1)
		{
			root=root->lc;
		}
		else
		{
			if(ptmp->data<ptmp->parent->data)
			{
				root->parent->lc=ptmp->lc;
			}
			else
			{
				root->parent->rc=ptmp->lc;
			}
		}
		return 1;
	}
	if(ptmp->rc!=NULL&&ptmp->lc==NULL)
	{
		if(i==1)
		{
			root=root->rc;
		}
		else
		{
			if(ptmp->data<ptmp->parent->data)
			{
				root->parent->lc=ptmp->rc;
			}
			else
			{
				root->parent->rc=ptmp->rc;
			}
		}
		return 1;
	}
	if(ptmp->lc!=NULL&&ptmp->rc!=NULL)
	{
		if(i==1)
		{
			ptmp=root->lc;
			while(ptmp->rc!=NULL)
			{
				ptmp=ptmp->rc;
			}
		//	printf("last:%d ",ptmp->data);
			ptmp->rc=root->rc;
			root->data=root->lc->data;
			root->rc=root->lc->rc;
			root->lc=root->lc->lc;
		}
		else
		{
			if(root->data<root->parent->data)
			{
				ptmp=root->lc;
				while(ptmp->rc!=NULL)
				{
					ptmp=ptmp->rc;
				}
				ptmp->rc=root->rc;
				root->data=root->lc->data;
				root->rc=root->lc->rc;
				root->lc=root->lc->lc;
			}
			if(root->data>root->parent->data)
			{
				ptmp=root->lc;
				while(ptmp->rc!=NULL)
				{
					ptmp=ptmp->rc;
				}
				ptmp->rc=root->rc;
				root->data=root->lc->data;
				root->rc=root->lc->rc;
				root->lc=root->lc->lc;
				
			}
		}
	}
}

void free_tree(pTree *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void find(pTree root,int num,int head)
{
	int i=0;
	if(num==head)
	{
		i=1;
	}
	if(num<root->data)
	{
		if(root->lc!=NULL)
		{
			find(root->lc,num,head);
		}

	}
	else if(num>root->data)
	{
		if(root->rc!=NULL)
		{
			find(root->rc,num,head);
		}
	}
	else
	{
		pTree pdel=root;
		pTree ptmp=root;
		if(1==remove_tree(root,ptmp,i))
		{
			if(i!=1)
			free_tree(&pdel);
		}
	}
}

void delete(pTree root,int head)
{
	printf("please input number:\n");
	int num;
	scanf("%d",&num);
	find(root,num,head);
}

void menu(pTree tr_root)
{
	int choose;
	for(;;)
	{
		printf("please input your choose:\n");
		printf("1  input 2  delete   3  show   0  exit\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				input(tr_root);
				break;
			case 2:
				delete(tr_root,tr_root->data);
				break;
			case 3:
				show(tr_root);
				break;
			case 0:
				exit(0);
		}
	}
}

int main()
{
	int n;
//	printf("how many number:\n");
//	scanf("%d",&n);
	pTree tr_root=NULL;
	init_tree(&tr_root);
	printf("please input root:\n");
	scanf("%d",&(tr_root->data));
	menu(tr_root);
//	input_number(tr_root,n);
//	create_tree(tr_arr,arr,n);
	return 0;
}

