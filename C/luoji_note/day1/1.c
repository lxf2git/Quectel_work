

#include <stdio.h>

int main()	
{
	char name[100];
	printf("hello world!\n");
	printf("please input name\n"); 
	scanf("%s",name); 
	getchar();
	int age;
	printf("please input age\n"); 
	scanf("%d",&age); 
	
	puts(name);
	printf("age: %d\n", age);

}
