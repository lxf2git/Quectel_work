#include<stdio.h>
#include<stdlib.h>

void add(int m,int n)
{
	printf("%d\n",m+n);
}
void sub(int m,int n)
{
	printf("%d\n",m-n);
}
void mul(int m,int n)
{
	printf("%d\n",m*n);
}
void div_(int m,int n)
{
	printf("%d\n",m/n);
}

void func(void (*p)(int,int),int m,int n)
{
	(*p)(m,n);
}

int main()
{
	void (*pf)(int,int)=NULL;	
	int a,b;
	char op;
	for(;;)
	{
		printf("please input :+ - * / \n");	
		scanf("%c",&op);
		printf("please input two inter:\n");
		scanf("%d%d",&a,&b);
		switch(op)
		{
			case '+':
					func(add,a,b);
					break;
			case '-':
					func(sub,a,b);
					break;
			case '*':
					func(mul,a,b);
					break;
			case '/':
					if(0==b)
					{
						printf("bcs is 0\n");	
							exit(-1);
					}
					func(div_,a,b);
					break;
			default:
					exit(0);
					break;
		
		}
		getchar();
	
	}		
	
	return 0;

}
