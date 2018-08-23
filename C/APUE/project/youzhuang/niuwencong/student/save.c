#include"main.h"

int save_stu(pStu phead,FILE *fp)
{
	pStu ptmp=phead->next;
	while(ptmp!=NULL)
	{
		fwrite(ptmp,sizeof(sStu),1,fp);
		ptmp=ptmp->next;
	}
return 0;
}
void save_chain(pStu phead,sList pl)
{		
	FILE *fp;	
	if((fp=fopen("save.txt","w+"))==NULL)
	{
		printf("文件保存失败!\n");
		exit (-1);
	}
	pl.pStu_Save=save_stu;
	pl.pStu_Save(phead,fp);
	fclose(fp);
}
