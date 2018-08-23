#include"student.h"

int Stu_Save(pStu pHead,FILE *fp)
{
	fp=fopen("data.txt","w");
	if(NULL == fp)
	{
		return -1;
	}
	Save_write(pHead,fp);
	fclose(fp);
	return 0;
}


void Save_write(pStu pHead ,FILE *fp)
{
	pStu ptmp = pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->num != 0)
		{
			fwrite(ptmp,sizeof(sStu),1,fp);	 
		}
	}
}

int Stu_Load(pStu pHead,FILE *fp)
{
	fp = fopen("data.txt","r");
	if(NULL == fp)
	{
		return -1;
	}
	Load_read(pHead,fp);
	fclose(fp);
	return 0;
}

void Load_read(pStu pHead,FILE *fp)
{
	pStu pnew = NULL;
	while(!feof(fp))
	{	
		Init_Stu(&pnew);
		fread(pnew,sizeof(sStu),1,fp);
		if(pnew->num != 0)
		{
			Insert(pHead,pnew,IDFind,InsertPos);
		}
	}
}
