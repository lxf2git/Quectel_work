#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1

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

/*
 *
 *int A;
 typedef int A;
 A b;  //int b

 
 * **/

 struct Student  
{
	char name[20];
	char gender;
	int age;
	char addr[20];
	int score;
}stu1,s1,s2;

int main()
{
	strcpy(stu1.name,"xinghongbin");
	printf("name:%s\n",stu1.name);	
	return 0;

}






