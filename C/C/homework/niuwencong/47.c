#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char **p,char **p1);
char *my_change(char *p,int l);
char *my_change(char *p,int l)
{	
	printf("llll:%d\n",l);
	char temp;
	int n=l/2;
	int i;
	p=p+n;
	for(i=0;i<l/4;i++,n--)
	{	
		if(l%2!=0)
		{temp=*(p+n);}
		else
		{temp=*(p+n-1);}
		*(p+n-1)=*(p+i);
		*(p+i)=temp;
	}
//	printf("%s",p);
	printf("%s\n",p);
	return p;
}
void change(char **p,char **p1)
{	
	int i;
	int	l1=strlen(*p);
	int	l2=strlen(*(p+1));
	int	l3=strlen(*(p+2));
	*p=my_change(*p,l1);
	//*(p+1)=my_change(*(p+1),l2);
	//*(p+2)=my_change(*(p+2),l3);
	for(i=0;i<1;i++)
	{
	//printf("%s\n",*(p+i));
	printf("***%s\n",*(p1+i));
	printf("^^^%p %p",&p[0][2],&p1[0][2]);
	}
}
int main()
{
	char *p[3];
	char *p1[3];
	int i;
	p[0]=(char *)malloc(20*sizeof(char));
	p[1]=(char *)malloc(20*sizeof(char));
	p[2]=(char *)malloc(20*sizeof(char));
	p1[0]=(char *)malloc(20*sizeof(char));
	p1[1]=(char *)malloc(20*sizeof(char));
	p1[2]=(char *)malloc(20*sizeof(char));
	for(i=0;i<3;i++)
	{
	printf("输入字符串:\n");
	scanf("%s",p[i]);
	p1[i]=p[i];
	}
	for(i=0;i<3;i++)
	{
	printf("===%s\n",p1[i]);

	}
	change(p,p1);
}



