#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	char *name;
	int age;
	int id;
	struct Student *next;
}*pStu,sStu;


int load_num()
{
	FILE *fp;
	fp = fopen("save.txt","r");
	int n;
	fseek(fp,-4,SEEK_END);
	fread(&n,4,1,fp);
	printf("n:%d",n);
	return n;
}



int main()
{
	pStu pHead=NULL,ptmp;
	pHead=(pStu)malloc(sizeof(sStu));
	ptmp=pHead;
	FILE *fp;
	fp = fopen("save.txt","r");
	if(NULL==fp)
	{
		printf("fopen error\n");
		exit(-1);
	}
	
	int i,n;
	n = load_num();
	for(i=0;i<n;i++)
	{
		pStu pnew;
		pnew =(pStu)malloc(sizeof(sStu));
		ptmp->next=pnew;
		ptmp->next->name=malloc(20*sizeof(char));
		fgets(pnew->name,21*sizeof(char),fp);
		fread(&pnew->age,sizeof(int),1,fp);
		fread(&pnew->id,sizeof(int),1,fp);
		fseek(fp,1,SEEK_CUR);
		ptmp=pnew;
	}
	
	ptmp=pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("%s %d %d\n",ptmp->name,ptmp->age,ptmp->id);
	}

}
