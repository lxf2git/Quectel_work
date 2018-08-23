#include"save.h"
int Save(pStu phead,FILE *fd)
{
	size_t re;
	pStu pread = NULL;
	FILE *fp=NULL;
	if(phead->next == phead)
	{
		printf("no information to save\n");
		return -1;
	}
	pStu ptmp = phead->next;
	fd = fopen("save.txt","w+");
	while(ptmp!= phead)
	{
		fwrite(ptmp,sizeof(sStu),1,fd);
		ptmp = ptmp->next;
	
	}
	fclose(fd);
	fp = fopen("save.txt","r");
	while(1)
	{
		pread = (pStu)malloc(sizeof(sStu));
		re = fread(pread,sizeof(sStu),1,fp);
		if(re <= 0)
		{
			break;
		}
		printf("id:%d age:%d\n",pread->num,pread->age);
	
	}
	printf("save success \n");
}
