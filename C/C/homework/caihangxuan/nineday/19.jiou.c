#include<stdio.h> 
int main()
{
	int nu,sum_o=0,sum_j=0,nu_o=0,nu_j=0;
	for(;;)
	{
		scanf("%d",&nu);
		if(nu==0)
			break;
		else if(nu%2==0)
		{
			sum_o=sum_o+nu;
			nu_o++;
		}
		else if(nu%2!=0)
		{
			sum_j=sum_j+nu;
			nu_j++;
		}
	}
	printf("偶数有%d个，基数有%d个\n",nu_o,nu_j);
	printf("偶数平均：%d基数平均：%d\n",sum_o/nu_o,sum_j/nu_j);
}
