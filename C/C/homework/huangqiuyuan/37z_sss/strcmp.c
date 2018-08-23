#include<stdio.h>
int i;
char mystrcmp(char *p1,char *p2);
char *input(char a[])
{
	
	for(i=0;;i++)
	{	
		scanf("%c",&a[i]);
			if(a[i]=='\n')
			break;
	}
		return (a);
}

int main()
{
	char a[100],b[100];
	printf("输入一串字符");
	char *p1=input(a);
	printf("再输入一串字符进行比较");
	char *p2=input(b);
//	if(strlen(a)==strlen(b))
//	printf
	mystrcmp(p1,p2);
 //	puts(a);


	return 0;
}

char mystrcmp(char *p1,char *p2)
{
	for(;;p1++,p2++)
	{
		if(*p1!=*p2)
			break;
				if(*p1=='\0'||*p2=='\0')
					break;
	}	
		if(*p1=='\0'||*p2=='\0')
			{
				printf("0\n");
				return 0;
			}

		if(*p1>*p2)
	 		printf("1\n");
		
		if(*p1<*p2)
			printf("-1\n");
}

