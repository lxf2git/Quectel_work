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
					pf = add;
					break;
			case '-':
					pf = sub;
					break;
			case '*':
					pf = mul;
					break;
			case '/':
					if(0==b)
					{
						printf("bcs is 0\n");	
							exit(-1);
					}
					pf = div_;
					break;
			default:
					exit(0);
					break;
		
		}
		getchar();
		(*pf)(a,b);
	}		
	
	return 0;

}
