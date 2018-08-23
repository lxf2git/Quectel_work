#include<stdio.h> 
int main() 
{
		int a;
		int i=0,count=0,sum=0,bum=0,op,jp;
		for(;;)
		{
				scanf("%d",&a);
				if(a==0)
						break;
				if(a%2==0)
				{
						count++;
						sum+=a;
				}
				i++;
				bum+=a;
		}
		if(count==0)
		{
			op=0;
		}
		else
				op=sum/count;
		if(i-count==0)
		{
				jp=0;
		}
		else
				jp=(bum-sum)/(i-count);
		printf("o:%d op:%d j:%d jp:%d\n",count,op,i-count,jp);
}
