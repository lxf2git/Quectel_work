#include"load.h"

void load(pStu pHead)
{
		pStu pNew;
		pStu palit=pHead;
		int i=0;
		FILE *fp1;
		fp1=fopen("b.txt","r+");
		fseek(fp1,-4,SEEK_END);
		fread(&i,sizeof(int),1,fp1);
		fseek(fp1,0,SEEK_SET);
		for(i;i>0;i--)
		{
		init_Node((void **)&pNew,sizeof(sStu));
				fread(&pNew->num,sizeof(int),1,fp1);
				fread(&pNew->age,sizeof(int),1,fp1);
				palit->next=pNew;
				palit=pNew;
		}
		fclose(fp1);
}
