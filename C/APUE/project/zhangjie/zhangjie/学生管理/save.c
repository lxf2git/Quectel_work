#include "main.h"
#include "init.h"
#include "save.h"


int save2(pStu p,FILE *fp)
{
	fp=fopen("stu.txt","w+");
	if(NULL==fp)
	{
		printf("fopen error\n");
		exit (-1);
	}
	pStu ptemp=NULL;
//	getmemory((void **)&ptemp,sizeof(sStu));
	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	{
		fwrite(ptemp,sizeof(sStu),1,fp);
	}
	fclose(fp);
	return 0;
}

void save(pStu p)
{
	FILE *fd;
	int (*pStu_save)(pStu pHead,FILE *fd);
	pStu_save=save2;
	pStu_save(p,fd);
}
