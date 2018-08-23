#include"lode.h"

void lode(pStu pHead)
{
	int i=0;
	pStu pnew=NULL;
	pStu p = pHead;
	FILE *fp;
	fp = fopen("1.txt","r+");
	if(NULL== fp)
	{
		printf("fopen error\n");
		exit(-1);
	}
	fseek(fp,-4,SEEK_END);
	fread(&i,sizeof(int),1,fp);
	fseek(fp,0,SEEK_SET);
	printf("%d\n",i);
	for(i;i>0;i--)
	{
		init_node(&pnew,sizeof(sStu));
		fread(&pnew->num,sizeof(int),1,fp);
		fread(&pnew->age,sizeof(int),1,fp);
		p->next = pnew;
		p = pnew; 
	}
	fclose(fp);
	
	
}
