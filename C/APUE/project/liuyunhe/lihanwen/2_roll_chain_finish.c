#include<stdio.h>	
#include<stdlib.h>
#include<string.h>

typedef struct People
{
	int data;
	struct People * next;
}sPeo,*pPeo;


void creat_memory(pPeo *p,int size)
{
	*p = (pPeo)malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_memory(pPeo *p,int size)
{
	creat_memory(p,size);
	(*p)->next = NULL;	
}

pPeo input_chain(pPeo pHead,int num)
{
	pPeo ptail=pHead,pnew=NULL;
	int i;
		printf("请输入序号\n");
		scanf("%d",&pHead->data);
	for(i=0;i<num-1;i++)
	{
		init_memory(&pnew,sizeof(sPeo));
		scanf("%d",&pnew->data);

		ptail->next = pnew;
		pnew->next = pHead;
		ptail = pnew;
	}

}

void show_chain(pPeo pHead)
{
	pPeo ptmp=pHead;
	int i;
	for(i=0;i<10;i++)//(ptmp=pHead;ptmp->next!=pHead;)
	{
		printf("%d",ptmp->data);
		ptmp = ptmp->next;
		printf("\n");
	}
}
#if 1
pPeo kill_member(pPeo pHead)
{
	pPeo last = NULL,ptmp;
	int num=0;
	for(ptmp=pHead;ptmp->next!=ptmp;)
	{
			num++;
			if(num==2)
			{
				last=ptmp;
				ptmp=ptmp->next;
			}
			else if(num==3)
			{
				last->next=ptmp->next;
				ptmp->next=NULL;
				if(ptmp!=NULL)
				{
					free(ptmp);
					ptmp=NULL;
				}
				ptmp=last->next;
				num=0;
			}
			else
			{
				ptmp=ptmp->next;
			}		
	}
	last = ptmp;
	return last;
}
#endif

#if 0
void  kill_member(pPeo pHead,int n)
{
	int i;
	pPeo ptmp,ptail=NULL;
	for(i=0;n=1;i++)
	{
		if(i==3)
		{
			n--;

		}
		ptmp=ptmp->next;

	}

}
#endif

void distroy_chain(pPeo last)
{
	last->next=NULL;
	if(last!=NULL)
	{
	free(last);
	last=NULL;
	}
}

int main()
{
		pPeo pHead = NULL;
		init_memory(&pHead,sizeof(sPeo));
		printf("请输入圆环范围n\n");
		int n;
		scanf("%d",&n);
		input_chain(pHead,n);
		//show_chain(pHead);
		pPeo last=NULL;
		last = kill_member(pHead);
		printf("剩下%d号人员\n",last->data);
		distroy_chain(last);
} 

