#include"save.h"

int Stu_Save(pStu pHead,FILE *fp)
{
		fp = fopen("student.txt","w+");
		pStu pTra = pHead->next;
		while(pTra!=NULL)
		{
				fwrite(pTra,sizeof(sStu),1,fp);
				pTra = pTra->next;
		}
		fclose(fp);
		return 0;
}
