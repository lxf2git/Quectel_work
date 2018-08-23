#include<stdio.h>
#include<stdlib.h>
#define N 4
struct Student
{
		char *name;
		int age;
	   	char sex;
   		int id;	   
}*sStu;
int main()
{
		int i;
	//	char en[2]={'\n','\0'};
		sStu=malloc(N*sizeof(struct Student));
		for(i=0;i<N;i++)
		{
				(sStu+i)->name=malloc(10*sizeof(char));		
			//	(sStu+i)->age=malloc(10*sizeof(char));		
			//	(sStu+i)->id=malloc(10*sizeof(char));		
				printf("输入学生的姓名 年龄 性别 id\n");
				scanf("%s%d",(sStu+i)->name,&(sStu+i)->age);
				getchar();
				scanf("%c%d",&(sStu+i)->sex,&(sStu+i)->id);
		}
		FILE *fp;
		fp=fopen("b.txt","w+");
		for(i=0;i<N;i++)
		{
			fwrite((sStu+i)->name,10*sizeof(char),1,fp);
			fwrite(&(sStu+i)->age,sizeof(int),1,fp);
			fwrite(&((sStu+i)->sex),sizeof(char),1,fp);
			fwrite(&(sStu+i)->id,sizeof(int),1,fp);
	//		fputs(en,fp);
		}
		for(i=0;i<N;i++)
		  {
		    free((sStu+i)->name);
		  }
		return 0;
}
