#include<stdio.h>
int main()
{      
		int i;
		float l=10.0,f=0.0,n=10.0,h=0.0;
		for(i=1;i<10;i++)
		{
				f=l/2.0;
				l=f;
				n=l+f+n;
		}
		h=l/2.0;
		printf("共%f米，反弹%f米",n,h);
		return 0;
}
