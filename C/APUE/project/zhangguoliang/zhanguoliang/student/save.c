#include"save.h"

void SAVE(pStu pHead,pList plist)
{
	FILE *fp=NULL;
	fp=fopen("student.txt","w");
	int a=plist->pStu_Save(pHead,fp);
	if(a==1)
	{
		printf("save successful\n");
	}
	fclose(fp);
}

int Save(pStu pHead,FILE*fd)
{
	pStu pnew=pHead->next;
	while(pnew!=NULL)
	{
		fwrite(pnew,sizeof(sStu),1,fd);
		pnew=pnew->next;
	}
	return 1;
}
