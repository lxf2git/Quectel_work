#include"huffman.h"

void creat_chain(pNode pHead,FILE * fp)
{
	char ch;
	pNode pnew = NULL;
	pNode ptmp = NULL;
	int con = 0;
	ch = fgetc(fp);
	while(!feof(fp))
	{
		for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
		{
			if(ptmp->data == ch)	//遇到重复权值++
			{
				ptmp->weight++;
				con =1;				//有重复con=1
			}
		}	
		if(con == 0)	//无重复建立新节点
		{
			init_node(&pnew);
			pnew->data = ch;
			pnew->weight++;
			insert_back_chain(pHead,pnew);
		}
		ch = fgetc(fp);
		con = 0;
	}
}

void sort_chain(pNode *proot,pNode pHead)
{
	pNode ptmp = NULL;
//	pNode pgrand = NULL;	//让根的parent指向它

//	init_node(&pgrand);
	ptmp = pHead->next;
	while(ptmp != pHead)		//建立排序树
	{
		head_del(pHead,ptmp);	//摘除链上节点（头删）
		if(*proot == NULL)
		{
			*proot = ptmp;
//			(*proot)->parent = pgrand;
//			pgrand->lc = *proot;
		}
		else
		{
			insert_sort_tree(*proot,ptmp);	//插入排序树
		}
		ptmp = pHead->next;	
	}
	
	mid_sort_tree(*proot,pHead);	//中序遍历排序树
}
void insert_sort_tree(pNode pnode,pNode pin)
{
	if(pin->weight < pnode->weight)
	{
		if(pnode->lc == NULL)
		{
			pnode->lc = pin;
	//		pin->parent = pnode;
		}
		else
		{
			insert_sort_tree(pnode->lc,pin);
		}
	}
	else
	{
		if(pnode->rc == NULL)
		{
			pnode->rc = pin;
	//		pin->parent = pnode;
		}
		else
		{
			insert_sort_tree(pnode->rc,pin);
		}
	}
}
void mid_sort_tree(pNode pnode,pNode pHead)
{
	if(pnode->lc != NULL)
	{									
		mid_sort_tree(pnode->lc,pHead);
	}
//	printf("ch:%c weight:%d\n",pnode->data,pnode->weight);
	break_chain(pnode,pHead);	//插回链（按weight有序）
//	if(pnode->rc != NULL)
//	{
//		mid_tree(pnode->rc);
//	}
}
void break_chain(pNode pnode,pNode pHead)
{
	pNode ptmp = NULL;
	ptmp = pnode->rc;
	insert_back_chain(pHead,pnode);
	if(pnode->rc != NULL)
	{
		mid_sort_tree(ptmp,pHead);
	}
	pnode->lc = NULL;
	pnode->rc = NULL;
}
