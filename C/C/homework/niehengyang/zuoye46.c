#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void move(char *p,int n);


int main()
{
	char *p=NULL;
	int n;
	p=(char *)malloc(50*sizeof(char));
	printf("please input str:\n");
	scanf("%s",p);
	printf("please input count:\n");
	scanf("%d",&n);
	move(p,n);
}


void move(char *p,int n)
{
	int t;
	int i,j;
	char a[50];
	t=strlen(p);
	//printf("%d\n",t);
	if(n>t)
	{
		n=n%t;	
	}
	for(i=0;i<t-n;i++)
	{
		a[i]=p[i];
	}
		a[t-n]='\0';
	//printf("%s\n",a);
	strcat(p+(t-n),a);
	printf("%s\n",p+(t-n));
	
}
