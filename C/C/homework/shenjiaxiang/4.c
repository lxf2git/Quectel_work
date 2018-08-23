#include<stdio.h>

int main()
{
	int a,b,op,s;
	printf("input int int:\n");
	scanf("%d%d",&a,&b);
        printf("input op\n"); 
        getchar();
	op=getchar();	
	//printf("%d",op);
	if(op=='+')
	s=a+b;
        if(op=='-')
        s=a-b;
	if(op=='*')
        s=a*b;
	if(op=='/')
	s=a/b;
	printf("%d %c %d等于%d\n",a,op,b,s);
	return 0;
}

