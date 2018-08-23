#include<stdio.h>
int main()
{
	int r,f1,f2,f5,z;
	z=0;
for(f5=0;f5<=20;f5++)
{
		for(f2=0;f2<=50;f2++)
		{
				for(f1=0;f1<=100;f1++)
				{
					r=f1+2*f2+5*f5;
					if(r==100)
					{
					printf("f1=%d,f2=%d,f5=%d\n",f1,f2,f5);
					z=z+1;
					}
				}
		}
}
					
					printf("方法总数为:z=%d\n",z);
						return 0;
}
