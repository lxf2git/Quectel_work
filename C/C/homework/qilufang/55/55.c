#include<stdio.h>
#include<stdlib.h>
#define N 2
#define M 10
/************结构体声明***********/
struct Student
{
	char name[20];
	int age;
	int sex;
	int id;
}sStu[N],sStu_1[N];

/**************函数声明****************/
void input_file(struct Student *sStu);
void output(struct Student *sStu);

/**************主函数*****************/
int main()
{
	int i,j;
	for(j=0;j<N;j++)
	{
		printf("请输入第%d学生的Name Age Sex Id:\n",j+1);
		scanf("%s%d%d%d",sStu[j].name,&sStu[j].age,&sStu[j].sex,&
						sStu[j].id);
	}
	input_file(sStu);
	output(sStu);	
	return 0;

}

/*************输入函数******************/
void input_file(struct Student *sStu)
{
	char ch[2]={'\n','\0'};
	FILE *fp=fopen("file","a+");
	int i;
	for(i=0;i<N;i++)
	{
		fwrite(sStu[i].name,M,1,fp);
		fwrite((void *)&(sStu[i].age),sizeof(int),1,fp);
		fwrite((void *)&(sStu[i].sex),sizeof(int),1,fp);
		fwrite((void *)&(sStu[i].id),sizeof(int),1,fp);
	}
	fclose(fp);
}

/**************读取函数*******************/
void output(struct Student *sStu)
{
	int i,j,ret=0;
	FILE *fp_1=fopen("file","r");
	for(j=0;j<N;j++)
	{
		fread((void *)sStu_1[j].name,M*sizeof(char),1,fp_1);
		ret=fread(&sStu_1[j].age,sizeof(int),1,fp_1);
		fread((void *)&sStu_1[j].sex,sizeof(int),1,fp_1);
		fread((void *)&sStu_1[j].id,sizeof(int),1,fp_1);
	}
	printf("RET:%d\n",ret);
	for(j=0;j<N;j++)
	{
		printf("Name:%s Age:%d Sex:%d Id:%d\n",sStu_1[j].name,
						sStu_1[j].age,sStu_1[j].sex,sStu_1[j].id);
	}
	fclose(fp_1);
}
