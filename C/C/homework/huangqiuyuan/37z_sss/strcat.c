#include<stdio.h>
#include<string.h>
void mystrcat( char *p,char *q);
int len;
int main()
{
	char a[100],b[100];
	printf("输入一串字符");
	scanf("%s",a);
	printf("再输入一串字符");
	scanf("%s",b);
	len=strlen(a);
	mystrcat(a,b);	
	puts(a);


	return 0;
}


void mystrcat(char *p,char *q)
{
	for(;;p++,q++)
	
	{	*(p+len)=*q;
		if(*(p+len)=='\0')
			break;
	}
}
