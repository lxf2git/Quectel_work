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
	char name[20];
	char gender;
	int age;
	char addr[20];
	int score;
};

void show(struct Student s)
{
	printf("这位 名叫%s,今年%d岁了，家住%s 考了%d 分 感谢关注\n",s.name,s.age,s.addr,s.score);//引用结构体成员：结构体变量名.成员名
}
int main()
{	
	struct Student s1;
	struct Student s2={"张杰",'M',18,"江苏",100};
	
	strcpy(s1.name,"高强");
	
	s1.age = 18;
    s1.score = 100;
	s1.gender = 'M';
	strcpy(s1.addr,"中国");
	show(s2);
	show(s1);
	return 0;

}






