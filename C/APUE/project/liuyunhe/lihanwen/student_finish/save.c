#include"save.h"

int _save(pStu pHead,FILE *fd)
{
	if(NULL==fd)
	{
		printf("fopen error!\n");
		return ;
	}
	pStu ptmp;
	int i=0;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		fwrite(&ptmp->num,sizeof(int),1,fd);
		fwrite(&ptmp->age,sizeof(int),1,fd);
		i++;
	}
	fwrite(&i,sizeof(int),1,fd);
	printf("save succeed!\n");
}

void s_save(pStu pHead)
{
	pList p_list;
	FILE *fd=fopen("save.txt","w+");
	p_list->pStu_Save=_save;
	p_list->pStu_Save(pHead,fd);
	fclose(fd);
}
