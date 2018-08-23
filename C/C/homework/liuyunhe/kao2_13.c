#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
struct Student
{
		char *name;
		int age;
		char sex;
		int id;
}*pStu;
int main()
{
		int i;
		FILE *pf;
		pf=fopen("b.txt","r+");
		pStu=malloc(N*sizeof(struct Student));
		for(i=0;i<N;i++)
		{
		(pStu+i)->name=malloc(10*sizeof(char));
		fread((pStu+i)->name,10*sizeof(char),1,pf);
		fread(&(pStu+i)->age,sizeof(int),1,pf);
		fread(&(pStu+i)->sex,sizeof(char),1,pf);
		fread(&(pStu+i)->id,sizeof(int),1,pf);
		}
		for(i=0;i<N;i++)
		{
				if(i==0||i==2||i==4||i==8)
				{
						printf("name:%s age:%d sex:%c id:%d\n",
				(pStu+i)->name,(pStu+i)->age,(pStu+i)->sex,(pStu+i)->id);
				}
		}
		return 0;
}
