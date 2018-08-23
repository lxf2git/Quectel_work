#include<stdio.h>
#include<string.h>
#define N 20

int main()
{
	int a,i,k,j;
	int num=456;
	char str1[N]={};
	char str2[2]="-";
	scanf("%d",&num);

	a=0;
	if(num<0)
	{
		num=num*(-1);
		a=1;
//		printf("-");
	}
	i=1;
	while(num%i != num)
	{
		i=i*10;
	}
	k=0;
	for(j=i/10;j!=0;j=j/10)
	{
		str1[k]=(num/j)+48;
//		printf("%c",(num/j)+48);
		num=num-((num/j)*j);
		k++;
	}
	str1[k]='\0';
	
	if(a==1)
	{
		printf("%s\n",strcat(str2,str1));
	}
	else
	{
		printf("%s\n",str1);
	}

	return 0;
}

