#include"main.h"



void create_link_tree(pTree *pht,int *parr,int num)
{
	int i;
	init_node(pht);
	(*pht)->tr_data = parr[0];
	pTree pnew;
	for(i=1;i<num;i++)
	{
		init_node(&pnew);
		pnew->tr_data = parr[i];
		add_link_node(*pht,pnew);
	}
}

void add_link_node(pTree ptr,pTree pnew)
{
	if(pnew->tr_data >= ptr->tr_data)
	{
		if(NULL == ptr->tr_rt)
		{
			ptr->tr_rt = pnew;
			pnew->tr_parent = ptr;
		}
		else
		{
			ptr = ptr->tr_rt;
			add_link_node(ptr,pnew);
		}
	}
	else
	{
		if(NULL == ptr->tr_lt)
		{
			ptr->tr_lt = pnew;
			pnew->tr_parent = ptr;
		}
		else
		{
			ptr = ptr->tr_lt;
			add_link_node(ptr,pnew);
		}
	}
}	
//---delete_link------
void delete_link_node(pTree pht,int da)
{
	pTree pnew;
	pTree pchange=pht;
	init_node(&pnew);
	pnew->tr_data = da;
	printf("de:da:%d\n",da);
	printf("de:pnew:%d\n",pnew->tr_data);
	int ret;
	printf("delete_link_node before--->!\n");
	ret = search_link(pht,pchange,pnew);
	printf("delete_link_node after--->!\n");
	if(ret == SUC)
	{
		printf("delete success!\n");
	}
	else
	{
		printf("no find!\n");
	}
}
//---search_link------
int  search_link(pTree phead,pTree pht,pTree pnew)
{
	int ret;
	int b=0;//b为1时，删除节点是该节点父亲节点的左节点，否则为右节点
	printf("pht:%d\n",pht->tr_data);
	printf("phead:%d\n",phead->tr_data);
	printf("pnew:%d\n",pnew->tr_data);
	if(pnew->tr_data == pht->tr_data)
	{
		if(NULL != pht->tr_parent)
		{
		if(pht->tr_parent->tr_lt == pht)
		{
			b=1;
		}
		else
		{
			b=2;
		}
		}
		printf("该链表中有%d的数！\n",pnew->tr_data);
		if(pnew != pht)
		{
			delete_node(pht,pnew,b);
			printf("delete_node after-->!2222\n");
		}
		else
		{
//			pTree pHnt;
//			pHnt = pht;
//			delete_node(pHnt,pnew,b);
//			解决删除头节点：定义一个节点让其子节点指向头节点后，按删除节点
//			不是头节点的处理
		}
		return SUC;
	}
	if(pnew->tr_data > pht->tr_data)
	{
		if(pht->tr_rt != NULL)
		{
			pht = pht->tr_rt;
			ret = search_link(phead,pht,pnew);
			return ret;
		}
		else
		{
			return EMPTY;
		}
	}
	else if(pnew->tr_data < pht->tr_data)
	{
		if(pht->tr_lt != NULL)
		{
			pht = pht->tr_lt;
			ret = search_link(phead,pht,pnew);
			return ret;
		}
		else
		{
			return EMPTY;
		}
	}
	if((pht->tr_data!=pnew->tr_data)
					&&(pht->tr_lt==NULL)&&(pht->tr_rt==NULL))
	{
		printf("link no find!\n");
		return EMPTY;
	}
}

int  delete_node(pTree pht,pTree pnew,int b)
{
	pTree pdelh,pdel_l,pdel_new;
	init_node(&pdel_new);
	pdelh = pht;
	int a=0;//1代表代替删除的点是左子树的点，2表示右子数的节点
	int ret=5;
		if(pht->tr_lt != NULL)
		{
			printf("main  delete 1step!\n");
			if(pht->tr_lt->tr_lt != NULL)
			{
				pdelh = pht->tr_lt;
			}
			else
			{
				pdelh = pht;
			}

		
			printf("main  delete 2 step!\n");
			while(pdelh->tr_rt != NULL)
			{
				pdelh = pdelh->tr_rt;
			}
			if(pdelh->tr_lt == NULL)
			{
			//	pdelh->tr_rt = NULL;
			printf("main  delete 3 step!\n");
				if(pht->tr_parent != NULL)
				{
					pdelh->tr_parent = pht->tr_parent;
					pdel_new = pdelh;
					pht->tr_rt->tr_parent = pdelh;
				}
				else
				{
				///删除头节点的程序，但是不能成功；
					printf("pht->parent is null!\n");
					printf("b:%d\n",b);
					pdelh->tr_parent = NULL;
					pdel_new = pdelh;
					pdel_new->tr_rt = pht->tr_rt;
					pdel_new->tr_lt = pht->tr_lt;
				}
				if(1 == b)
				{
					pdel_new->tr_parent->tr_lt =  pdel_new;
				}
				if(2 == b)
				{
					pdel_new->tr_parent->tr_rt = pdel_new;
				}
			
				printf("pdel_new--->l->R:%d\n",pdel_new->tr_data);
				printf("pdel_new--->l->R.l:%d\n",pdel_new->tr_lt->tr_data);
				printf("pdel_new--->l->R:%d\n",pdel_new->tr_rt->tr_data);
				printf("pht--->l->R:%d\n",pht->tr_data);
				a=1;
			}
			else
			{
				pdel_l = pdelh;
				if(pdelh->tr_lt != NULL)
				{
					pdelh->tr_parent = pht->tr_parent;
					if(pht->tr_rt != NULL)
					{
						pdelh->tr_rt = pht->tr_rt;
						pht->tr_rt->tr_parent = pdelh;
						pdel_new = pdelh;
					pdelh = pdelh->tr_parent;
					}
					else
					{
						pdel_new = pdelh->tr_lt;
						pdel_new->tr_parent = pht->tr_parent;
					}
				if(1 == b)
				{
					pdel_new->tr_parent->tr_lt =  pdel_new;
				}
				if(2 == b)
				{
					pdel_new->tr_parent->tr_rt = pdel_new;
				}
			//		pdel_new->tr_lt = NULL;
				printf("pdel_new--->l->R->l:%d\n",pdel_new->tr_data);
	//			printf("pdel_new--->parent:%d\n",pdel_new->tr_parent->tr_data);
	//			printf("pdel_new--->rt:%d\n",pdel_new->tr_rt->tr_data);
					a=1;
				}
			}
			ret = SUC;
	//			return ret;
		}
		else{ 
		if(pht->tr_rt !=NULL)
		{
			if(pht->tr_rt->tr_lt != NULL)
			{
				pdelh = pht->tr_rt;
			}
			else
			{
				pdelh = pht;
			}
			while(pdelh->tr_lt != NULL)
			{
				pdelh = pdelh->tr_lt;
			}
			if(pdelh->tr_rt == NULL)
			{
				printf("pdelh:%d\n",pdelh->tr_data);
				pdelh->tr_parent->tr_lt = NULL;
				pht->tr_parent = NULL;
				pdel_new = pdelh;
				printf("pdel_new--->r->L:%d\n",pdel_new->tr_data);
				a=1;
			}
			else
			{
				pdel_l = pdelh;
				printf("pdelh->rt:%d\n",pdelh->tr_rt->tr_data);
					pdelh->tr_rt->tr_parent = pdel_l->tr_parent;
					pdel_l->tr_parent->tr_lt = pdel_l->tr_rt;
					pdel_new = pdelh;
					pdelh = pdelh->tr_parent;
					pdel_new->tr_parent = NULL;
			//		pdel_new->tr_rt = NULL;
				printf("pdel_new--->r->L->r:%d\n",pdel_new->tr_data);
					a=2;
			}

			ret = SUC;
	//			return ret;
		}
		}
			if((pht->tr_lt==NULL)&&(NULL==pht->tr_rt))
			{
				printf("l:null,r:null->pht:%d\n",pht->tr_data);
				printf("l:null,r:null->pht->parent:%d\n",pht->tr_parent->tr_data);
				pdelh = pht;
				pht = pht->tr_parent;
				if(1 == b)
				{
					pht->tr_lt = NULL;
					pdelh->tr_parent = NULL;
					free_memory(&pdelh);
				}
				if(2 == b)
				{
					pht->tr_rt = NULL;
					pdelh->tr_parent = NULL;
					free_memory(&pdelh);
				}
			}
			else
			{
				replace_node(&pht,pdel_new,b);
				printf("b:%d\n",b);
			}
//		pht = pdel_new;
		//------------------delete,stand----
	//	replace_node(&pht,pdel_new,a);
	return ret;
}

void replace_node(pTree *pdelh,pTree pdel_new,int a)
{
//	int a=0;//1代表代替删除的点是左子树的点，2表示右子数的节点
		pTree pdel_l;
		int c=6;//0代表删除点无父亲节点，否则为1；
		if(NULL != (*pdelh)->tr_parent)
		{
			c=1;
		}
		else
		{
			c=0;
		}
		if(NULL != (*pdelh)->tr_lt)
		{
			if(1 == c)
			{
				(*pdelh)->tr_lt->tr_parent = (*pdelh)->tr_parent;
			}
			if(0 == c)
			{
				(*pdelh)->tr_lt->tr_parent = pdel_new;
			}
		}
		if(NULL != (*pdelh)->tr_rt)
		{
			if(1 == c)
			{
				(*pdelh)->tr_rt->tr_parent = (*pdelh)->tr_parent;
			}
			if(0 == c)
			{
				(*pdelh)->tr_rt->tr_parent = pdel_new;
			}
		}
		if(NULL != (*pdelh)->tr_parent)
		{
			if(1 == a)
			{
				if(NULL != (*pdelh)->tr_parent)
				{
					(*pdelh)->tr_parent->tr_lt = pdel_new;
					pdel_new->tr_parent = (*pdelh)->tr_parent;
					(*pdelh)->tr_parent = (*pdelh);
				}
			}
			if(2 == a)
			{
				if(NULL != (*pdelh)->tr_parent)
				{
					(*pdelh)->tr_parent->tr_rt = pdel_new;
					pdel_new->tr_parent = (*pdelh)->tr_parent;
					(*pdelh)->tr_parent = NULL;
				}
			}
		}
		printf("pdel_new---->hhh:%d\n",pdel_new->tr_data);
//		pdel_new->tr_lt = (*pdelh)->tr_lt;
//		pdel_new->tr_rt = (*pdelh)->tr_rt;
//		pht = pdel_new;
		(*pdelh)->tr_lt = NULL;
		(*pdelh)->tr_rt = NULL;
					free_memory(pdelh);
}

//----show_link----------------
void show_link_tree(pTree pht)
{
	//mid_show();
	if(pht->tr_lt != NULL)
	{
		show_link_tree(pht->tr_lt);
	}
	printf("%d ",pht->tr_data);
	if(pht->tr_rt != NULL)
	{
		show_link_tree(pht->tr_rt);
	}
}

void free_memory(pTree *p)
{
	free(*p);
	if(NULL != *p)
	{
		*p = NULL;
	}
}
