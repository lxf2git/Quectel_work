#include<stdio.h>

typedef struct Student//默认4字节对齐
{//结构体类型中占空间最大的字节数和默认比较 按最小的对齐
	int id;	
	char gender;
	char ch;
	char grade;
}sStu,*pStu;

int main()
{	sStu s1;
	printf("size:%d\n",sizeof(struct Student));
	printf("&s1.gender:%p\n",&s1.gender);
	printf("&s1.ch:%p\n",&s1.ch);
	printf("&s1.grade:%p\n",&s1.grade);
}
