#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{

	int data;
	int tr_parent;//结构体_成员在结构体中的作用
	int tr_lc;
	int tr_rc;	
}sTree,*pTree;
void init_tree(pTree tr_arr,int num);
void create_tree(pTree tr_arr,int *arr,int num);
void fill(pTree tr_arr,int num,int i);
void mid_tree(pTree root,int num);
void show_tree(pTree root,int num);

int main()
{

	int arr[]={22,7,12,34,30,45,23};
	sTree tr_arr[7];
	init_tree(tr_arr,7);//初始化-1
	create_tree(tr_arr,arr,7);//赋数据 比较 下标改变
	show_tree(tr_arr,7);//中序遍历
		
	return 0;

}
void init_tree(pTree tr_arr,int num)
{
		int i;
		for(i=0;i < num;i++)
		{
				tr_arr[i].tr_lc = -1;
				tr_arr[i].tr_rc = -1;
				tr_arr[i].tr_parent = -1;
		}
}

void create_tree(pTree tr_arr,int *arr,int num)
{
		int i;
		for(i=0;i<num;i++)
		{
				tr_arr[i].data = arr[i];
				fill(tr_arr,i,0);

		}
		for(i=0;i<num;i++)
		{
				printf("l:%2d Pa:%2d  r:%2d data:%2d\n",tr_arr[i].tr_lc, tr_arr[i].tr_parent,tr_arr[i].tr_rc,tr_arr[i].data);
		}
}
void fill(pTree tr_arr,int num,int i)
{
		if(tr_arr[num].data > tr_arr[i].data)
		{
				if(tr_arr[i].tr_rc < 0)
				{

						tr_arr[i].tr_rc = num;
						tr_arr[num].tr_parent = i;
					
				}
				else
				{
						fill(tr_arr,num,tr_arr[i].tr_rc);
				}
		}
		if(tr_arr[num].data < tr_arr[i].data)
		{
				if(tr_arr[i].tr_lc < 0)
				{
						tr_arr[i].tr_lc = num;
						tr_arr[num].tr_parent = i;
				}
				else
				{
						fill(tr_arr,num,tr_arr[i].tr_lc);
				}
		}


}
void mid_tree(pTree root,int num)
{

		if(root[num].tr_lc != -1)
		{
			mid_tree(root,root[num].tr_lc);
		}
	
		printf("%d ",root[num].data);
		if(root[num].tr_rc != -1)
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
