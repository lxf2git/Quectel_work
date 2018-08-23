#include<stdio.h>
#include<string.h>
#define N 100

void count1(char arr[N]);
//void in_put(char bn[N]);

void in_put(char bn[N])
{
	int n;
	printf("请输入一个字符串：");
	int i;
	/*
	for(i=0;i<N;i++)
	{
		scanf("%c",&bn[i]);
		if(bn[i] == 10)
		{
			bn[i]='\0';
		}
	printf("字符串i%c\n：",bn[i]);
	}
	*/
	gets(bn);
	n = strlen(bn);
	printf("字符串：");
	puts(bn);
	for(i=0;i<n;i++)
	{
		printf("%c",bn[i]);
		if(bn[i] == '.')
		{
			printf("\n");
		}
	}
}

int main()
{
	char a1[N]={};
	in_put(a1);
//	puts(a1);
	count1(a1);
	return 0;
}

void count1(char brr[N])
{
	int n;
	int num_ch=0,num_w=0,num_l=0;
//	puts(brr);
	n = strlen(brr);
	int i,j;
	char k;
	for(i=0;i<n;i++)
	{
		if((brr[i]>='A'&&brr[i]<='Z') 
						|| (brr[i]>='a'&&brr[i]<='z'))
		{
			num_ch++;
		}

		if(brr[i] == '.')
		{
			num_l++;
			if(brr[i-1] != ' ')
				num_w++;
		}
			if((brr[i] == ' ')&&(brr[i-1] != '.'))
			{
				num_w++;
			}
	}

	printf("character:%d\n",num_ch);
	printf("word:%d\n",num_w);
	printf("line:%d\n",num_l);
}

