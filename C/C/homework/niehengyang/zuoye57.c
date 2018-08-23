#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct student 
{
	char *name;
	int age;
	char sex;
}stu_s[10];


int main()
{
	int i;
	FILE *fp;
	fp=fopen("stu_dat","r");
	if(fp==NULL)
	{
		printf("file open error!");
		exit(0);
	for(i=0;i<10;i+=2)
	{
		fseek(fp,i*sizeof(struct student),0);
		fread(&stu_s[i],sizeof(struct student),1,fp);
		printf("%s,%d,%c",stu_s[i].name,stu_s[i].age,stu_s[i].sex);
	}
	}
	fclose(fp);
}
