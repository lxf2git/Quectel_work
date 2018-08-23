#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{

	int data;
	int tr_parent;//结构体_成员在结构体中的作用
	struct tree *prev;
	struct tree *plc;
	struct tree *prc;	
}sTree,*pTree;

//void init_tree(pTree p,int num);
//void create_tree(pTree tree,int num);
void fill(pTree p,pTree pRoot);
void mid_tree(pTree pRoot);
void show_tree(pTree pRoot);
void delete_tree(pTree pRoot);
void find_point(pTree pRoot,int data);
void delete_point(pTree p);
pTree ergodic_left(pTree p);
pTree ergodic_right(pTree p);
void create_tree(pTree pRoot);
void init_tree(pTree *p);
void create_memory(pTree *p);
int main()
{

//	int arr[]={22,7,12,34,30,45,23};
//	sTree tree[7];
	pTree pRoot;
	init_tree(&pRoot);
	printf("input root\n");
	scanf("%d",&pRoot->data);
	create_tree(pRoot);
	delete_tree(pRoot);
	show_tree(pRoot);
//	init_tree(tree,7);                               //初始化-1
//	create_tree(tree,7);                        //赋数据 比较 下标改变
//	delete_tree(tree);
//	show_tree(tree);                                //中序遍历 
		
	return 0;

}
#if 0
void init_tree(pTree p,int num)
{
		int i;
		for(i=0;i < num;i++)
		{
				(p+i)->prev = (p+i);
				(p+i)->plc = NULL;
				(p+i)->prc = NULL;
		}
}

void create_tree(pTree tree,int num)
{
		int data;
		int i;
		for(i=0;i<num;i++)
		{
				scanf("%d",&data);
				tree[i].data = data;
				if(i>0)
				fill(tree+i,tree);

		}
}
# endif
void create_tree(pTree pRoot)
{
		int data;
		int ret=0;
		pTree p;
		do{
				init_tree(&p);
				printf("input c\n");
				ret = scanf("%d",&data);
				if(ret == 1)
				{
						p->data = data;
						fill(p,pRoot);
				}
		}while(ret != 0);

}
void init_tree(pTree *p)
{
		create_memory(p);
		(*p)->prev = (*p);
		(*p)->plc = NULL;
		(*p)->prc = NULL;
}
void create_memory(pTree *p)
{
		*p = malloc(sizeof(struct tree));
}
void fill(pTree p,pTree pRoot)
{
		if(p->data > pRoot->data)
		{
				if(pRoot->prc == NULL)
				{

						pRoot->prc = p;
						p->prev = pRoot;
	//					printf("prev:%d\n",p->prev->data);
					
				}
				else
				{
						fill(p,pRoot->prc);
				}
		}
		if(p->data <= pRoot->data)
		{
				if(pRoot->plc == NULL)
				{

						pRoot->plc = p;
						p->prev = pRoot;
					
				}
				else
				{
						fill(p,pRoot->plc);
				}
		}


}
void mid_tree(pTree pRoot)
{

		if(pRoot->plc != NULL)
		{
			mid_tree(pRoot->plc);
		}
	
		printf("%d ",pRoot->data);
		if(pRoot->prc != NULL)
		{
			mid_tree(pRoot->prc);
		}
}

void show_tree(pTree pRoot)
{
	//prev_tree();
	mid_tree(pRoot);
	//last_tree();
}

void delete_tree(pTree pRoot)
{
		int data;
		getchar();
		printf("input you delete data\n");
		scanf("%d",&data);
		find_point(pRoot,data);

}
void find_point(pTree pRoot,int data)
{
		pTree p = pRoot;
		while( (p != NULL) )
		{
				if((p != NULL) && (p->data > data) )
				{
						p = p->plc;
				//		printf("%d\n",p->data);
				}

				if((p != NULL) && (p->data < data))
				{
						p = p->prc;
				//		printf("%d\n",p->data);
				}
				if((p != NULL) && (p->data == data))
				{
						printf("finded\n");
						delete_point(p);
						if(p != NULL)
						{
								free(p);
								p =NULL;
						}
						p =pRoot;
//						return ;
				}

		}


}
void delete_point(pTree p)
{
		pTree pTemp;
//		printf("%d\n",p->data);
//		printf("%d\n",p->prev->data);
		if(p->prev->data < p->data)//用左孩子的最右边替换  它是右孩子
		{
				if(p->prc != NULL)
				{
						pTemp = ergodic_left(p->prc);
						if(pTemp == p->prc)//它右孩子没右左孩子
						{
								p->prev->prc = pTemp;
								pTemp->plc = p->plc;//接管删除点的左孩子								
								pTemp->prev = p->prev;//接管删除点的前节点
						}
						else
						{
								pTemp->prev->plc = pTemp->prc;//把右孩子转让上节点当右孩子
								pTemp->prc = p->prc;//接管删除点的右孩子
								pTemp->plc = p->plc;//接管删除点的左孩子
								pTemp->prev = p->prev;//接管删除点的前节点
								p->prev->prc = pTemp;//充当 新节点
						}
				}
				else
				{
						p->prev->prc = p->prc;
				}
					

		}
		if(p->prev->data > p->data)//右孩子的最右左  它是左孩子
		{		if(p->plc != NULL)
				{
						pTemp = ergodic_right(p->plc);
						if(pTemp == p->plc)//它左孩子没有右孩子
						{
								p->prev->plc = pTemp;                  
								pTemp->prc = p->prc; //接管删除点的右孩子
								pTemp->prev = p->prev;//接管删除点的前节点
						}
						else
						{
								pTemp->prev->prc = pTemp->plc;//把左孩子给上节点当右孩子        
								pTemp->prc = p->prc;//接管删除点的右孩子
								pTemp->plc = p->plc;//接管删除点的左孩子
								pTemp->prev = p->prev;//接管删除点的前节点
								p->prev->plc = pTemp;//充当 新节点
						}
				}
				else
				{
						p->prev->plc = p->prc;                          //一叶子节点
				}

		}
		
}

pTree ergodic_left(pTree p)
{
		if(p->plc != NULL)
		{
				ergodic_left(p->plc);
		} 
		else
				return p;
}

pTree ergodic_right(pTree p)
{
		if(p->prc != NULL)
		{
				ergodic_right(p->prc);
		}
		else
				return p;

}
