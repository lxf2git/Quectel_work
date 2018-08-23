#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
		int tr_data;
		struct tree *tr_parent;
		struct tree *tr_lc;
		struct tree *tr_rc; 
}sd,*pd;
void create_memory(pd *pnode)
{
		*pnode=(pd)malloc(sizeof(sd));
		if(NULL==*pnode)
		{
				printf("maloc fail");
				exit(-1);
		}

}
void init_node(pd *pnode)
{
		create_memory(pnode);
		(*pnode)->tr_parent=*pnode;
		(*pnode)->tr_lc=*pnode;
		(*pnode)->tr_rc=*pnode;
}
void dd(pd pnew,pd root)
{
		if(pnew->tr_data>root->tr_data)
		{
				if(root->tr_lc==root)
				{
					root->tr_lc=pnew;
					pnew->tr_parent=root;
				}
				else
				{
						dd(pnew,root->tr_lc);
				}

		}
		else
		{
				if(root->tr_rc==root)
				{
					root->tr_rc=pnew;
					pnew->tr_parent=root;

				}
				else
				{
						dd(pnew,root->tr_rc);
				}
		}
}
void creat(pd root,int num,int *parr)
{
		int i;
		root->tr_data=parr[0];
		pd pnew=NULL;
		for(i=1;i<num;i++)
		{
				init_node(&pnew);
			pnew->tr_data=parr[i];
			dd(pnew,root);
		}	
}
void mid(pd root)
{
		if(root->tr_lc!=root)
		{
				mid(root->tr_lc);
		}
		printf("=========%d \n",root->tr_data);
		if(root->tr_rc!=root)
		{
				mid(root->tr_rc);
		}
}
void show(pd root)
{
		mid(root);
}
int main()
{
		pd root=NULL;
		
	int arr[10],a,i=0,m,k,l;
	for(;;)
	{
			printf("1-----4\n");
	scanf("%d",&a);
	switch (a)
	{
			case 1:
	//	for(i=0;i<10;i++)
			scanf("%d",&arr[i]);
			i++;
			break;
			case 2:
			scanf("%d",&m);
			for(k=0;k<i;k++)
			{
					if(m==arr[k])
					{
					for(l=k;l<i-1;l++)
							arr[l]=arr[l+1];
					}
			}
			i--;
			break;
			case 4:
	//	exit(0);
			break;
			
	}
	if(a==4)
			break;
	
	printf("%d",i);
//	for(k=0;k<i;k++)
//			printf("%d ",arr[k]);
//	printf("\n");
	init_node(&root);
	creat(root,i,arr);
	show(root);
	}
}
