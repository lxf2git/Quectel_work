#include<stdio.h>
#include<stdlib.h>
#define EMPTY -1

typedef struct tree
{

	int tr_data;
	int tr_parent;//结构体_成员在结构体中的作用
	int tr_lc;
	int tr_rc;	
}sTree,*pTree;

void init_tree(pTree p,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		p[i].tr_data = -1;
		p[i].tr_lc = -1;
		p[i].tr_rc = -1;
		p[i].tr_parent = -1;
	}
}

void add_node(pTree root,int *parr,int start_index,int insert_index)
{

		if(root[insert_index].tr_data<=root[start_index].tr_data)
		{
			if(root[start_index].tr_lc==EMPTY)
			{
				root[start_index].tr_lc = insert_index;
				root[insert_index].tr_parent = start_index;
			}
			else
			{
			add_node(root,parr,root[start_index].tr_lc,insert_index);		
			}
		}
		
	else
	{
			if(root[start_index].tr_rc==EMPTY)
			{
				root[start_index].tr_rc = insert_index;
				root[insert_index].tr_parent = start_index;
			}
			else
			{
			add_node(root,parr,root[start_index].tr_rc,insert_index);		
			}
	}

}

void create_tree(pTree root,int *arr,int num)
{
	int i;
	root[0].tr_data = arr[0];
	for(i=1;i<num;i++)
	{	
		root[i].tr_data = arr[i];
		add_node(root,arr,0,i);
	}
}

void mid_tree(pTree root,int num)
{

		if(root[num].tr_lc!=EMPTY)
		{
			mid_tree(root,root[num].tr_lc);
		}
		printf("%d ",root[num].tr_data);
	
		if(root[num].tr_rc!=EMPTY)
		{
			mid_tree(root,root[num].tr_rc);
		}
}

void show_tree(pTree root,int num)
{
	//prev_tree();
	mid_tree(root,0);
	//last_tree();
}
int main()
{

	int arr[]={22,7,12,34,30,45,23};
	sTree tr_arr[7];
	init_tree(tr_arr,7);//初始化-1
	create_tree(tr_arr,arr,7);//赋数据 比较 下标改变
	show_tree(tr_arr,7);//中序遍历
		
	return 0;

}
