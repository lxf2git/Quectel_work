#include<stdio.h>

int main()
{
	int  od,ev,nu,d,i=0,j=0;
	float sum1=0,sum2=0;
	printf("please input in number : \n");
	do
	{
		scanf("%d",&nu);
		d=nu%2;
	    if(d==0)
		{
			i++;
			sum1+=nu;
		}
		else
		{
			j++;
		   sum2+=nu;
		}

	}while(nu!=0);
    printf("even number :%d\n",i-1);
	if(i!=0)
	{ 
		if(i==1)
		{
			printf("mean value :%5.2f\n",sum1);
		}
		else
		{
			printf("mean value :%5.2f\n",sum1/(i-1));
		}
	}
    printf("odd number :%d\n",j);
	if(j!=0)
	{ 
		if(j==1)
		{
			printf("mean value :%5.2f\n",sum2);
		}
		else
		{
			printf("mean value :%5.2f\n",((sum2)/(j)));
		}
	}
    return 0;
}
