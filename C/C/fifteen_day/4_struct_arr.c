#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

/*	int char float... int *p int arr[3] 
	结构体：可以有不同类型数据的集合--组装新的数据类型
组装关键字：struct

struct 结构体名
{
	成员类型 成员名;
	成员类型 成员名;
	...........
};
*/
// 1 声明  2  typedef+声明

 struct Student
{
	char *name;
	char gender;
	int age;
	char addr[20];
	int score;
};

void show(struct Student * p)
{
	int i;
	for(i=0;i<N;i++)
	{	
		printf("name:%s gender:%c age:%d addr:%s score:%d\n",
					p[i].name,p[i].gender,p[i].age,
					p[i].addr,p[i].score);
	}
}
int main()
{
	struct Student st_arr[N];
	for(i=0;i<N;i++)
	{
		st_arr[i].name = (char*)malloc(sizeof(char)*20);	
		printf("please input name gender age addr socre:\n");
		scanf("%s",st_arr[i].name);//结构体指针(一级)->成员
		getchar();
		scanf("%c%d%s%d",&st_arr[i].gender,&st_arr[i].age,
						st_arr[i].addr,&st_arr[i].score);
		
	}
	
	show(st_arr);//&s1
	return 0;

}






