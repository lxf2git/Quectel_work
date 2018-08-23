/************
 * 数组二叉查找树 
 *
 *
 *
 * ***********/

#include<stdio.h> 
#include<stdlib.h> 
#define  TURE   (1) 
#define  FALSE  (EOF) 
#define  N      7
typedef struct Tree
{

	int tr_data;
	int tr_pa;
	int tr_lc;
	int tr_rc;

}Stree, *Ptree;

void mid_tree(Ptree root, int num);
void show_tree(Ptree root);
void creat_lib(Ptree root, int num, int data,int i);
int creat_tree(Stree* tr_arr, int* arr);
int init_tree(Stree* tr_arr);
int main()
{
	int i =0;
	int arr[N];
	for (i=0; i<N; i++)
	{
		printf("please input \n"); 
		scanf("%d",&arr[i]); 
	}
	for (i=0; i<N; i++)
	{
	printf("%d ",arr[i]); 
	}
	printf("\n=================== \n"); 
	Stree tr_arr[N];
	init_tree(tr_arr);
	creat_tree(tr_arr, arr);
	show_tree(tr_arr);
	return TURE; 
}

int init_tree(Stree* tr_arr)
{
	int i =0;

	for (; i<N; i++)
	{
		tr_arr[i].tr_data =EOF;
		tr_arr[i].tr_pa = EOF;
		tr_arr[i].tr_lc = EOF;
	   	tr_arr[i].tr_rc = EOF;	
	}

	return TURE; 
}

int creat_tree(Stree* tr_arr, int* arr)
{
	int i =0; 
//	tr_arr[0].tr_data = arr[0];

	for (i=1; i<N; i++)
	{	
		tr_arr[i].tr_data = arr[i];

		creat_lib(tr_arr, 0,arr[i],i);
		

	}
}

void creat_lib(Ptree root, int num, int data,int i)
{
		if (data <= root[num].tr_data)
		{
				if (root[num].tr_lc !=EOF)
				{
					creat_lib(root,root[num].tr_lc,data, i);		
				}

				else
				{
				root[num].tr_lc = i;
				root[i].tr_pa =num; 
				}

		}
		else 
		{
				if(root[num].tr_rc  !=EOF)
				{
						creat_lib(root,root[num].tr_rc, data, i);
				}	
				else
				{
				root[num].tr_rc = i;
				root[i].tr_pa =num; 
				}
		}
}


void show_tree(Ptree root)
{
	mid_tree(root, 0);
	printf("\n"); 
	
}

void mid_tree(Ptree root, int num)
{
	if (root[num].tr_lc !=EOF)
	{
		mid_tree(root, root[num].tr_lc);
	}
	printf("%d ",root[num].tr_data); 
	
	if (root[num].tr_rc !=EOF)
	{
		mid_tree(root, root[num].tr_rc);
	}

}
	

	

