#include<stdio.h>
#include<string.h>
int main()
{
	int nu=0,nu_f=0,num_f=1,size;
	char first[100]={},second[500]={};
	printf("请输入一个字符串\n");
	scanf("%s",first);
	size=strlen(first);
	if(size==1)
	{
		printf("%s\n",first);
		return 0;
	}
	for(;nu<size;nu++)
	{
		if(nu+1==size)
		{
			printf("%c\n",first[nu]);
			break;
		}
		else
		{
			printf("%c",first[nu]);
			nu_f=num_f;
			for(;nu_f>0;nu_f--)
			{
				printf("#");
			}
			num_f=num_f+2;
		}
	}
}
