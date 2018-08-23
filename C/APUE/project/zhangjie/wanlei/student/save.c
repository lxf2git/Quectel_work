#include"save.h"

int pStu_Save(pStu pHead,FILE *fd)
{
	fd=fopen("stu.txt","w+");
	if(fd==NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	pStu p=pHead;
	while(p->next!=NULL)
	{
		fwrite(p->next,sizeof(sStu),1,fd);
		p=p->next;
	}
	printf("保存成功\n");
	fclose(fd);
	return 0;
}
