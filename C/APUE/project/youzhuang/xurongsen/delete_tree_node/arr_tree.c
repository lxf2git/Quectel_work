#include"main.h"

#if 0
void create_tree(pTree pstr, int *parr,int num)
{
	int i;
	sTree snew;
	pstr[0].tr_data = parr[0];
	for(i=1;i<num;i++)
	{
		init_node(&snew);
		snew.tr_data = parr[i];
	//	add_node(pstr,snew);
		add_link_node(pstr,snew);
	}
}
void add_node(pTree pstr,pTree pnew)
{
	pTree phead = pstr;
	if(phead->tr_data >= pnew->tr_data)
	{
		if(phead->tr_lt == NULL)
		{
			pnew->tr_parent = phead;
			phead->tr_lt = pnew;
		}
		else
		{
			add_node(pstr->tr_lt,pnew);
		}
	}
	else
	{
		if(phead->tr_rt == NULL)
		{
			pnew->tr_parent = phead;
			phead->tr_rt = pnew;
		}
		else
		{
			add_node(pstr->tr_rt,pnew);
		}
	}
}

void create_tree(sTree *pstr, int *parr, int num)
{
	int i,left,right,fa;
	char ch;
	int data;
	pstr[0].tr_data = parr[0];
	for(i=1;i<num;i++)
	{
		pstr[i].tr_data = parr[i];
		add_node_arr(pstr,parr,0,i);
	}
}
void init_tree(sTree str[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
//		create_memory((void **)&str[i],sizeof(sTree));
		str[i].tr_lt = -1;
		str[i].tr_data = -1;
		str[i].tr_parent = -1;
		str[i].tr_rt = -1;
	}
}

void add_node_arr(pTree pstr, int *parr,int root,int n)
{
	if(pstr[root].tr_data >= parr[n])
	{
		if(pstr[root].tr_lt == EMPTY)
		{
			pstr[n].tr_parent = root;
			pstr[root].tr_lt = n;
		}
		else
		{
			add_node_arr(pstr,parr,pstr[root].tr_lt,n);
		}
	}
	else
	{
		if(pstr[root].tr_rt == EMPTY)
		{
			pstr[n].tr_parent = root;
			pstr[root].tr_rt = n;
		}
		else
		{
			add_node_arr(pstr,parr,pstr[root].tr_rt,n);
		}
	}
}

void mid_tree(pTree proot,int num)
{
	if(proot[num].tr_lt != EMPTY)
	{
		mid_tree(proot,proot[num].tr_lt);
	}
	printf("%d  ",proot[num].tr_data);
	if(proot[num].tr_rt != EMPTY)
	{
		mid_tree(proot, proot[num].tr_rt);
	}
}

void show_tree(pTree proot,int num)
{
	//prev_tree
	mid_tree(proot, 0);//中序输出
	printf("\n");
	//next_tree
}
#endif
