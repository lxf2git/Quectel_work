#include"main.h"

void show_age(int i)
{
	FILE*fp=NULL;
	fp=fopen("message.txt","r");
	int ret;
		while(1)
		{
		pStu pnew=(pStu)malloc(sizeof(struct student));
		ret=fread(pnew,sizeof(struct student),1,fp);
			if(i == pnew->age)
				{
				printf("ID:%d 年龄:%d 名字:%s \n",pnew->id,pnew->age,pnew->name);
				}
				if(ret==0)
					break;
		}
					fclose(fp);
						
}
void show_all(pStu pHead)
{
	FILE*fp=NULL;
		fp=fopen("message.txt","r");
	int ret;
		while(1)
		{
		pStu pnew=(pStu)malloc(sizeof(Stu));
		ret=fread(pnew,sizeof(Stu),1,fp);
			if(ret==0)
			{break;}
		printf("ID:%d 年龄:%d 名字:%s \n",pnew->id,pnew->age,pnew->name);
		}
			fclose(fp);
}
