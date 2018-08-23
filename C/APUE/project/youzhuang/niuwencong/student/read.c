#include"main.h"




void read_fp(pStu phead)
{
	FILE *fp;
	if((fp=fopen("save.txt","r+"))==NULL)
	{
		printf("信息读取失败!\n");
		exit(-1);
	}
	pStu pnew=NULL;
	pStu ptmp=phead;
	
	while(!feof(fp))
	{	
		init_memory(&pnew);
		fread(pnew,sizeof(sStu),1,fp);
		ptmp->next=pnew;
		if(pnew->num==0&&pnew->age==0)
		{
			ptmp->next=NULL;
			free(pnew);
			break;	

		}
		else
			ptmp=ptmp->next;
		
	}
	fclose(fp);
}
