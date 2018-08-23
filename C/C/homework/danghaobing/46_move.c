#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fun(char *p,int n)
{
	char q[100]={};
	int m=strlen(p)-n;
	strcpy(q,p+m);
	*(p+m)='\0';
	strcat(q,p);
	printf("%s\n",q);

}
int main() 
{
		char *p=NULL;
		int n;
		p=(char *)malloc(100*sizeof(char));
		printf("请输入字符串\n");
		scanf("%s",p);
		printf("右移位数:\n");
		scanf("%d",&n);
		fun(p,n);
		return 0;
		
}
