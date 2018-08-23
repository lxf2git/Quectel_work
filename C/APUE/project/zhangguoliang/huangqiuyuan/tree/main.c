#include<stdio.h>
#include<stdlib.h>
#define N -1
typedef struct tree
{
	int tr_data;
	int tr_parent;
	int tr_lc;
	int tr_rc;
}sTree,*pTree;

void add_node(pTree root,int *parr,int start_index,int insert_index)
{
	if(root[insert_index].tr_data<=root[start_index].tr_data)
	{
		if(root[start_index].tr_lc==N)
		{
			root[start_index].tr_lc=insert_index;
			root[insert_index].tr_parent=start_index;
		}
		else
		{
			add_node(root,parr,root[start_index].tr_lc,insert_index);
		}
	}
	else
	{
		if(root[start_index].tr_rc==N)
		{
			root[start_index].tr_rc=insert_index;
			root[insert_index].tr_parent=start_index;
		}
		else
		{
			add_node(root,parr,root[start_index].tr_rc,insert_index);
		}
	
	}
}
void creat_tree(pTree root,int *arr,int num)
{
	int i;
	root[0].tr_data=arr[0];
	for(i=1;i<num;i++)
	{
		root[i].tr_data=arr[i];
		add_node(root,arr,0,i);	
	}

}
init_tree(pTree arr,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		(arr+i)->tr_parent=N;
		arr[i].tr_lc=N;
		arr[i].tr_rc=N;
	}
}


void mid_tree(pTree root,int num)
{
	if(root[num].tr_lc!=N)
	{
		mid_tree(root,root[num].tr_lc);
	}
		printf("%d \n",root[num].tr_data);
	if(root[num].tr_rc!=N)
	{
		mid_tree(root,root[num].tr_rc);
	}
}
void show_tree(pTree root,int num)
{
	mid_tree(root,0);
}
int main()
{
	int arr[]={22,7,12,34,30,45,23};
	sTree tr_arr[7];
	init_tree(tr_arr,7);// 
	creat_tree(tr_arr,arr,7);
	show_tree(tr_arr,7);

	return 0;
}







