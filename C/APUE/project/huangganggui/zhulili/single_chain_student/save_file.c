#include"save_file.h"

void save_file(pNode ptmp)
{
	FILE *fp;
	fp = fopen("student.txt","w+");
	if(fp == NULL)
	{
		printf("fopen error");
		exit(-1);
	}
	while(ptmp != NULL)
	{
		fwrite(ptmp,sizeof(sNode),1,fp);
	
		ptmp = ptmp->next;	
	}
	fclose(fp);
	printf("保存成功\n");
}