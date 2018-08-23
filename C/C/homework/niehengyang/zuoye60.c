#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct People
{
	int id;
	struct People *next;
}sPeo,*pPeo;
void input_people_id(pPeo,int);
void create_memory(pPeo *p,int size);
void kill_people(pPeo,int);

int main()
{
	int nu;
	pPeo pHead=NULL;
	create_memory(&pHead,sizeof(sPeo));
	printf("please input the number of people:\n");
	scanf("%d",&nu);
	input_people_id(pHead,nu);
	kill_people(pHead,nu);
}

void create_memory(pPeo *p,int size)
{
	*p=(pPeo)malloc(size);
	if(NULL==*p)
	{
		printf("create memory error!\n");
	}
	(*p)->next=*p;
}

void input_people_id(pPeo pHead,int nu)
{
	int i;
	pPeo ptmp=pHead;
	pPeo pnew=NULL;
	for(i=1;i<=nu;i++)
	{
		create_memory(&pnew,sizeof(sPeo));
		pnew->id=i;
		ptmp->next=pnew;
		ptmp=ptmp->next;
		pnew->next=pHead;
		printf("%d",pnew->id);	
	}
	printf("\n");
}	

void kill_people(pPeo pHead,int nu)
{
	int life,j=1;
	int count=0;
	pPeo ptmp=pHead;
	for(;;ptmp=ptmp->next)
	{
		//count=count+1;
		if(ptmp->id!=0)
		{
			count=count+1;
			if(count%3==0)
			{
				printf("kill_people:%d\n",ptmp->id);
				ptmp->id=0;
				j=j+1;
			}
		}
		//printf("%d",ptmp->id);
		/*if(count%3==0)
		{
			printf("kill_people:%d\n",ptmp->id);
			ptmp->id=0;
			j=j+1;
		}*/
			if(j==nu&&ptmp->id!=0)
			{
				printf("life_people:%d\n",ptmp->id);
				break;
			}
		
	}
}
