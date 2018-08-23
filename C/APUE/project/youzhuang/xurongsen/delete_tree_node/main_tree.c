#include"main.h"
//---------------------------------------

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void init_node(pTree *pstr)
{
	create_memory((void**)pstr,sizeof(sTree));
	(*pstr)->tr_lt = NULL;
	(*pstr)->tr_rt = NULL;
	(*pstr)->tr_data = -1;
	(*pstr)->tr_parent = NULL;
}


int main()
{
	int arr[]={22,7,12,34,30,45,23};
//	sTree str[7];
//	init_tree(str,7);

//	create_tree(str,arr,7);
//	show_tree(str,7);

//	------link-------------
	pTree pht;
	int da;
	printf("please input your delete data:");
	scanf("%d",&da);
	create_link_tree(&pht,arr,7);
	printf("main---->a!\n");
	show_link_tree(pht);
	printf("\n");
	delete_link_node(pht,da);
	printf("main---->b!\n");
	show_link_tree(pht);
}

