#include<stdio.h>
struct Student
{
	int id;	//0-3
	char a;//4
	short b;//6-7
	char c;//8
};
int main()
{
	struct Student s1;	
	printf("size:%d\n",sizeof(s1));
	printf("&s1.id:%p\n",&s1.id);
	printf("&s1.a:%p\n",&s1.a);
	printf("&s1.b:%p\n",&s1.b);
	printf("&s1.c:%p\n",&s1.c);
}
