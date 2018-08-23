#include"del.h"

pStu DelPosition(pStu pNode,int age)
{
	if(pNode->next->age==age)
	{
		return pNode;
	}
	return NULL;
}

void del_(pStu p_Del)
{
	printf("del-bf:%d\n",p_Del->num);
	pStu ptmp;
	ptmp = p_Del->next;
	p_Del->next=p_Del->next->next;
	printf("del:%d\n",ptmp->num);
	if(ptmp!=NULL)
	{
		free(ptmp);
		ptmp = NULL;
	}
}

int Del(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age))
{
	int Del_age;
	char c;
	printf("please choose please choose Age for Delete!\n ");
	scanf("%d",&Del_age);		
	pStu p_Del=NULL;
	init_memory(&p_Del);
	pStu ptmp=NULL;

	for(ptmp=pHead;ptmp->next!=NULL;)
	{
		printf("Del_age:%d\n",Del_age);
		p_Del = (*pDelPosition)(ptmp,Del_age);
		if(p_Del!=NULL)
		{
			printf("===num:%d  age:%d===\n",p_Del->next->num,p_Del->next->age);
			printf("please Delete Y/N?\n");
			getchar();
			scanf("%c",&c);
			printf("***%c\n",c);
			switch(c)
			{
				case 'Y':
						del_(p_Del);
						ptmp=pHead;
						printf("Delete success!^_^\n");
						break;
				case 'N':
						printf("Delete fail!-_-\n");
						break;
				default:
						printf("please choose Y/N!!!\n");
						break;
			}
		}
		if(ptmp->next==NULL)
		{
			ptmp = ptmp;
		}
		else{
					ptmp=ptmp->next;
				}
	}
return 0;	
}


void s_del(pStu pHead)
{
	pList p_list;
	init_memory_list(&p_list);

	p_list->pDel=Del;
	p_list->pDel(pHead,DelPosition);

}
