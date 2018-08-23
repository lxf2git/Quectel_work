#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 2
#define M 20

typedef struct Student
{
	char *name;
	char sex;
	char id[5];
	int age;
}sStu;

void creat_memory(void **p,int size);
void input(sStu *p);
void store(sStu *p,FILE *fp);
void i_free(void **p);

int main()
{
	sStu stu[N];
	FILE *fp=NULL;
	char *pch;
	creat_memory((void **)&pch,M*sizeof(char));
	printf("请输入存入学生信息的文件名\n");
	scanf("%s",pch);
	fp=fopen(pch,"w+");
	input(stu);
	store(stu,fp);
	i_free((void**)&pch);
	fclose(fp);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入学生姓名 年龄id 性别\n");
		creat_memory((void **)&p[i].name,M*sizeof(char));
		getchar();
		scanf("%s",p[i].name);
		getchar();
		scanf("%d",&p[i].age);
		getchar();
		scanf("%s",p[i].id);
		getchar();
		scanf("%c",&p[i].sex);
	}
}

void store(sStu *p,FILE *fp)
{
	int i;
	char str[3];
	char str1[10]="姓名：";
	char str2[10]=" 年龄：";
	char str3[10]=" 性别：";
	char str4[6]=" id:";
	char str5='\n';
	for(i=0;i<N;i++)
	{
		fwrite(str1,9,1,fp);
		fputs(p[i].name,fp);
		str[1]=p[i].age%10+48;
		str[0]=p[i].age/10+48;
		fwrite(str2,10,1,fp);
		fputs(str,fp);
		fwrite(str3,10,1,fp);
		fputc(p[i].sex,fp);
		fwrite(str4,4,1,fp);
		fputs(p[i].id,fp);
		fputc(str5,fp);
		i_free((void **)&p[i].name);
	}
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
