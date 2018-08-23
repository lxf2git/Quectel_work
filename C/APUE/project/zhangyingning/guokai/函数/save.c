#include"save.h"

int save(pStu pHead, FILE *fp)
{
	fp = fopen("student.txt","w+");	
	while(pHead->next!=NULL)
	{	
		fwrite(pHead->next,sizeof(struct student),1,fp);
		pHead = pHead->next;
	}
	fclose(fp);
}
