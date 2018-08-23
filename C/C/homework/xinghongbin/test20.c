#include<stdio.h>
void display(int a,char c,int b);
int main()
{
		display(3,'c',5);
		return 0;
}

void display(int a,char c,int b)
{
		int i,j;
		for(i=0;i<a;i++)
		{
				for(j=0;j<b;j++)
						printf(" %c",c);
				printf("\n");
		}
}
