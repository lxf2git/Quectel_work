#include"save.h"

int psave(pStu pHead,FILE*fd)
{
	int i=0;
	pStu ptv = pHead;
	fd = fopen("1.txt","w+");
	if(NULL==fd)
	{
	printf("fopen error\n");
	exit(-1);
	}
	while(ptv->next!=NULL)
	{
	fwrite(&ptv->next->num,sizeof(ptv->next->num),1,fd);
	fwrite(&ptv->next->age,sizeof(ptv->next->age),1,fd);
	ptv = ptv->next;
	i++;
	}
	fwrite(&i,sizeof(int),1,fd);
	fclose(fd);
	printf("保存成功\n");
}

void Save(sList slist,pStu pHead)
{
	FILE *fd;
	slist.pStu_save=psave;
	slist.pStu_save(pHead,fd);
}
