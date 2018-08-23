#include<stdio.h>

void shuchu(int n,int i);
int xuanshu();
int main()
{
	xuanshu();
	return 0;
}

int xuanshu()
{
	int a,i=0;
	for(a=1;a<=1000;a++)
		if((a%3==2)&&(a%5==3)&&(a%7==1))
		{
			i++;
			shuchu(a,i);
		}
		return 0;
}
void shuchu(int n,int i)
{ 
	
	printf("%d  ",n);
	if(i%6==0)
	{
		i=0;
		printf("\n");
	}
}
