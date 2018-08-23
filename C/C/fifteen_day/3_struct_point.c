#include<stdio.h>
#include<string.h>

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
	printf("name:%s gender:%c age:%d addr:%s score:%d\n",
					p->name,p->gender,p->age,p->addr,p->score);
}
int main()
{
	int *p;	
	*p  = 78;

	struct Student s1;
	struct Student * p = &s1;
	p = (struct Student *)malloc(sizeof(struct Student));


	p->name = (char*)malloc(20*sizeof(char));
	printf("please input name gender age addr socre:\n");
	scanf("%s",p->name);//结构体指针(一级)->成员
	//(&s1)->name   s1.name
	getchar();
	scanf("%c%d%s%d",&p->gender,&p->age,p->addr,&p->score);
	
	show(p);//&s1
	return 0;

}






