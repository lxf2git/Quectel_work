#include"load.h"

void load(pStu pHead)
{
	pStu ptmp=pHead;
	pStu pNew=NULL;
	int i=0;
	FILE *fp;
	fp=fopen("save.txt","r+");
	if(NULL==fp)
	{
		printf("fopen error!\n");
		exit(-1);
	}
	fseek(fp,-4,SEEK_END);
	fread(&i,sizeof(int),1,fp);
	fseek(fp,0,SEEK_SET);
	for(i;i>0;i--)
	{
		init_memory(&pNew);
		fread(&pNew->num,sizeof(int),1,fp);
		fread(&pNew->age,sizeof(int),1,fp);
		ptmp->next=pNew;
		ptmp=pNew;
	}
	fclose(fp);
}
