#include<stdio.h>
void input();

int main()
{
	input();
	return 0;
}

void input()
{
	int i,n,suma=0,sumb=0;
	float a=0,b=0;
	for(i=0;scanf("%d",&n)&&n !=0;i++)
	{
		if(n/2==0)
		{
			a++;
			suma += a;
		}else
		{
			b++;
			sumb += b;
		}
	}
		if(i==0)
		{
			printf("err");
			return;
		}
		printf("suma:%d avera:%f aumb:%d b:%f",suma,suma/a,sumb,sumb/b);
	
}
