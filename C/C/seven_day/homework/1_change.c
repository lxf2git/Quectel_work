#include<stdio.h>
#define N 5

void deal_negative(char a[],int number)
{
	a[0] = '-';
	number = -number;
	a[1] = number/100+'0';
	number%=100;
	a[2] = number/10+'0';
	a[3] = number%10+'0';
	if(a[1]=='0')
	{
		a[1] = a[2];
		a[2] = a[3];
		a[3] = '\0';
	}
	printf("a:%s\n",a);
}
void deal_positive(char a[],int number)
{
	if(number==0)
	{
		a[0]=number+'0';
	}
	a[0] = number/100+'0';
	number%=100;
	a[1] = number/10+'0';
	a[2] = number%10+'0';
	if(a[0]=='0')
	{
		a[0] = a[1];
		a[1] = a[2];
		a[2] = '\0';
	}

	printf("a:%s\n",a);
}

void deal(char a[],int number)
{
	if(number<0&&number>-1000)
	{
		deal_positive(a,number);
	}
	else if(number>=0&&number<1000)
	{
		deal_negative(a,number);
	}
}

int input()
{
	int number;
	puts("请输入一个整数x(|x|<1000)");
	do
	{
		scanf("%d",&number);
	}while((number<0&&number<=-1000)||(number>0&&number>=1000)&&printf("input again:\n"));
	
	printf("**%d\n",number);
	return number;
}

int main()
{
	char a[N]={'\0'};	

	int number = input();
	deal(a,number);
	return 0;

}
