#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct student
{
	char name[20];
	char sex;
	int id;
	int age;
}stu_s[5];

void save();


int main()
{
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%s%c%d%d",stu_s[i].name,&stu_s[i].sex,&stu_s[i].id,&stu_s[i].age);
		save();
	}
}

void save()
{
	int i;
	FILE *fp;
	fp=fopen("stu_std","w+");
	if(fp==NULL)
	{
		printf("file open error!\n");
		return;
	}
	for(i=0;i<5;i++)
	{
		if(fwrite(&stu_s[i],sizeof(struct student),1,fp)!=1)
			printf("fwrite error!\n");
	}
	fclose(fp);
}
