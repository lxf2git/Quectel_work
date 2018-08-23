#include<stdio.h>
void input(char a[]);
char *mystrcpy(char *p1,char *p2);
int main()
{
char a[100]={},b[100]={};
	printf("输入一个字符串");
	input(a);
//	puts(a);
	printf("再输入一串字符");
	input(b);
//	puts(b);
	*mystrcpy(a,b);
	printf("后一个将前一个字符串覆盖:");
	puts(a);

	return 0;
}




void input(char a[])
{
	int i;
	for(i=0;i<100;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		{
			i--;
			break;
		} 
	}
}	
	
char *mystrcpy(char *p1,char *p2)
{
	for(;;p1++,p2++)
	{
		*p1=*p2;
		if(*p1=='\0')
		break;
	}
}




