#include"huffman.h"

pNode creat_huffman_tree(pNode pHead)
{
	pNode pn1 = NULL;
	pNode pn2 = NULL;
	pNode proot = NULL;	//新建无数据节点
	pNode ptmp = NULL;
	while(pHead->next->next != pHead)
	{
		pn1 = pHead->next;
		head_del(pHead,pn1);
		pn2 = pHead->next;
		head_del(pHead,pn2);
		init_node(&proot);
		proot->lc = pn1;
		pn1->parent = proot;
		proot->rc = pn2;
		pn2->parent = proot;
		proot->weight = pn1->weight+pn2->weight;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
			if(ptmp->weight > proot->weight)
			{
				break;
			}
		}
		insert_back_chain(ptmp,proot);
	}
	proot = pHead->next;
		show_chain(pHead);
	head_del(pHead,proot);
//	printf("out\n");
	connect_leaf(pHead,proot);	//将数据连成单链表
	return proot;
}
void connect_leaf(pNode pHead,pNode pnode)
{
//	printf("in\n");
	if(pnode->lc == NULL && pnode->rc == NULL)
	{
		pHead->parent->next = pnode; 
		pnode->next = pHead;
		pHead->parent = pnode;
		show_chain(pHead);
	}
	else
	{
		if(pnode->lc != NULL)
		{
			connect_leaf(pHead,pnode->lc);
		}
		if(pnode->rc != NULL)
		{
			connect_leaf(pHead,pnode->rc);
		}
	}
}

