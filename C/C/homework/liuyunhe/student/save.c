#include"save.h"

int psave(pStu pHead,FILE *fd)
{
		int i=0;
		fd = fopen("b.txt","w+");
		pStu palit;
		palit=pHead->next;
		while(palit!=NULL)
		{
				fwrite(&palit->num,sizeof(int),1,fd);
				fwrite(&palit->age,sizeof(int),1,fd);
				palit=palit->next;
				i++;
		}
		fwrite(&i,sizeof(int),1,fd);
		printf("****save succeed***\n");
		fclose(fd);
}

void save(pStu pHead,sList slist)
{
	FILE *fp;
	slist.pStu_Save = psave;
	slist.pStu_Save(pHead,fp);
}
