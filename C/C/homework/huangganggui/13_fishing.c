#include<stdio.h>

int main()
{
	int i,j=0,temp=0;
	while(!temp)
	{
		j++;
		temp=j;
		for(i=0;i<5;i++)
		{
			temp=dis(temp);  			//分鱼			
		}
		
		
	}
	printf("total:%d\n",j);

	return 0;
}

int dis(int j)
{
	j=(j-1)/5;
	return j;
}
