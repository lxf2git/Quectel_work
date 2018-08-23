#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}sNode,*pNode;

void create_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}	
}

init_node(pNode *p,int size)
{
	create_memory(p,size);
	(*p)->next = *p;
}

void delete(pNode pHead,int m)
{
	pNode pdel = pHead;
	pNode pTrav;
	int i;
	int k = 1;
	for(i=1;;)
	{		
		i++;
		pTrav = pdel;  //pTrav要删除的前一个节点
		pdel = pdel->next;  
		if(i%3==0)
		{	
			pTrav->next = pdel->next;		
			printf("淘汰的人是：%d\n",pdel->num);
			k++;	
		}	
		if(k == m)
		{
			printf("剩下的人是：%d\n",pTrav->num);
			break;
		}
	}
}

void create_chain(pNode pHead,int n,int m)
{
	pNode pnew;
	pNode ptmp = pHead;
	int i;
	for(i=0;i<m-1;i++)
	{
		init_node(&pnew,sizeof(sNode));
		scanf("%d",&pnew->num);
		ptmp->next = pnew;
		pnew->next = pHead;
		ptmp = pnew;		
	}
	printf("\n");
}

int main()
{
	pNode pnew;
	int n,i;
	init_node(&pnew,sizeof(sNode));
	printf("请输入约瑟夫环的个数:");
	scanf("%d",&n);
	printf("请输入数字：\n");
	scanf("%d",&pnew->num);
	create_chain(pnew,pnew->num,n);	
	delete(pnew,n);
	return 0;
}

