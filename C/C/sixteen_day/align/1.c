#include<stdio.h>

typedef struct Student
{
	int age;
	char ch;
	int id;
}sStu,*pStu;

int main()
{	sStu s1;
	printf("size:%d\n",sizeof(struct Student));
	printf("&s1.age:%p\n",&s1.age);
	printf("&s1.ch:%p\n",&s1.ch);
	printf("&s1.id:%p\n",&s1.id);
}
