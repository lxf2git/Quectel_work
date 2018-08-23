#include<stdio.h>
int main()
{
	int num,i,j,temp;
	i=0,j=0;
	char string[50]={0};
    printf("输入一个数字\n");
	scanf("%d",&num);
	if(num<0)
	{
	num=0-num;
	i++;
    string[0]='-';
	j++;
	}
	temp=num;
	if(temp==0)
	{
	i=1;
	}
	for(;temp>0;i++)
		temp/=10;
	while(i-j)
	{
	string[i-1]=num%10+48;
	num/=10;
	i--;
	}
	puts(string);
return 0;
}
