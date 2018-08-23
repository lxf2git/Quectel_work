#include<stdio.h>
void shuzu(int num);

int main()
{
	shuzu(1000);
	return 0;
}
void shuzu(int num)
{
	int n=0;
	for(num=1000;num>0;num--)
	{
		if(num%3==2)
		{
			if(num%5==3)
			{
				if(num%7==1)
				{
					printf("%d,",num);
					n++;
					if(n%6==0)
					{
						printf("\n");
					}
				}
				else continue;
			}
			else continue;
		}		
		else continue;
	}
}
