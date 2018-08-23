#include<stdio.h>

int main()
{
	int num,i=0,j=0,temp;
	char str[50]={0};

	scanf("%d",&num);
	if(num<0)
	{
		num=0 - num;
		i++;
		str[0]='-';
		j++;					//sign
	}
	temp=num;
	if(temp == 0)
		{
			i=1;
		}			
	for(;temp>0;i++)
		temp /= 10;
//	printf("%d",i);

	str[i]='\0';
	while(i-j)					
	{
		str[i-1] = num % 10 + 48;
		num = num / 10;
		i--;
	}


	puts(str);
	
	

	return 0;
}
