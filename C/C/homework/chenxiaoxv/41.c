#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *fan(char *a,char *b,int i)
{
	char *ret=NULL;
	if(i==0)
	{
		strcat(a,b);
		ret=a;
	}
	else if(i==1)
	{
		strcat(b,a);
		ret=b;
	}
	return ret;

}
int main()
{
	char a[500];
	char b[500];
	char *ret=NULL;
	int flag=0;
	printf("inputA:");
	scanf("%s",&a);
	printf("inputB:");
	scanf("%s",&b);
	printf("flag:");
	scanf("%d",&flag);
	ret=fan(a,b,flag);
	printf("%s",ret);

	return 0;
}




