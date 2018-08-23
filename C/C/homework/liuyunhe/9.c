#include<stdio.h>
int main()
{
		int a=20,i=0,n=20;
		while(a>0)
		{
				a--;
				i++;
				if(i==2)
				{
						a=a+1;
						i=0;
						n=n+1;
				}

		}
		printf("共喝到%d瓶\n",n);
		return 0;
}
