#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{

	char data;
	int tr_parent;//结构体_成员在结构体中的作用
	struct tree *prev;
	struct tree *plc;
	struct tree *prc;	
}sTree,*pTree;

void create_tree(pTree *pRoot);
void create_memory(pTree *p);
void init_tree(pTree p);
void fill_tree(pTree pRoot,pTree p);
void mid_tree(pTree pRoot);
void show_tree(pTree pRoot);
int main()
{
	

//	int arr[]={22,7,12,34,30,45,23};
	pTree pRoot;
	create_tree(&pRoot);
	show_tree(pRoot);                                //中序遍历 
		
	return 0;

}
void create_memory(pTree *p)
{
		*p = malloc(sizeof(struct tree));
}
void init_tree(pTree p)
{
				 p->data = 0;
				(p)->prev = p;
				(p)->plc =  p;
				(p)->prc =  p;
}
void create_tree(pTree *pRoot)
{
		char ch;
		printf("root:");
		scanf("%c",&ch);
		getchar();
		if(ch != ' ')
		{
				create_memory(pRoot);
				init_tree(*pRoot);
				(*pRoot)->data = ch;
				fill_tree(*pRoot,*pRoot);
		}
		
		else
		{
				*pRoot = NULL;
				exit(-1);
		}

}
void fill_tree(pTree pRoot,pTree p)
{
		pTree pTemp;
		pTree pTemp1;
		create_memory(&pTemp);
		init_tree(pTemp);
		pTemp->prev = pRoot;
		printf("%c l:",pRoot->data);
		scanf("%c",&pTemp->data);
		getchar();
		if((pTemp->prev->plc == pTemp->prev))
		{
				if( pTemp->data != ' ')
				{
						pTemp->prev->plc = pTemp;
						fill_tree(pTemp,p);
						printf("%c l :%c\n",pTemp->prev->data,pTemp->data);
				}
				else
				{
						pTemp->prev->plc = NULL;
						printf("%c l:NULL\n",pTemp->prev->data);
				}
		}
		create_memory(&pTemp1);
		init_tree(pTemp1);
		pTemp1->prev = pRoot;
		printf("%c r:",pRoot->data);
		scanf("%c",&pTemp1->data);
		getchar();
		if((pTemp1->prev->prc == pTemp1->prev))
		{
				if((pTemp1->data != ' ') )
				{
						pTemp1->prev->prc = pTemp1;
						fill_tree(pTemp1,p);
						printf("%c r :%c\n",pTemp1->prev->data,pTemp1->data);

				}


				else
				{
						pTemp1->prev->prc = NULL;
						printf("%c r:NULL\n",pTemp->prev->data);

				}
		}

}
/*
void fill(pTree p,pTree pRoot)
{
		if(p->data > pRoot->data)
		{
				if(pRoot->prc == NULL)
				{

						pRoot->prc = p;
						p->prev = pRoot;
					
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


}*/
void mid_tree(pTree pRoot)
{

		if(pRoot->plc != NULL)
		{
			mid_tree(pRoot->plc);
		}
	
		printf("%c ",pRoot->data);
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
/*
void delete_tree(pTree pRoot)
{
		int data;
		printf("input you delete data\n");
		scanf("%d",&data);

}
void find_point(pTree pRoot,int data)
{
		if(pRoot->data > data)
		{
				if(pRoot->prc == NULL)
				{
						printf("dont find\n");
						return;
				}
				else
						find_point(pRoot->prc,data);

		}
		if(pRoot->data < data)
		{
				if(pRoot->prc == NULL)
				{
						printf("dont find\n");
						return;
				}
				else
						find_point(pRoot->plc,data);
		}
		if(pRoot->data = data)
				delete_point(pRoot);

}
void delete_point(pTree p)
{
		pTree pTemp;
		if(p->prev->data < p->data)
		{
				 pTree = ergodic_left(p);

		}
		if(p->prev->data > p->data)
		{
				 pTree = ergodic_right(p);
		}
		
}

pTree ergodic_left(pTree p)
{
		if(p->plc != NULL)
		{
				ergodic_left(p->plc)
		}
		else
				return p;
}

pTree ergodic_right(pTree p)
{
		if(p->prc != NULL)
		{
				ergodic_left(p->prc)
		}
		else
				return p;

}*/
