#include<stdio.h>
#include<string.h>
#define N 10

void order(char arr[N]);
void in_put(char bn[N]);
void clear(char arr[N]);

int main()
{
	char a1[N]={};
	char a2[N]={};
	in_put(a1);
	order(a1);
//	printf("a1---->\n");
//	puts(a1);
	in_put(a2);
	order(a2);
//	printf("a2---->\n");
//	puts(a2);
	strcat(a1,a2);

	order(a1);
	clear(a1);
	return 0;
}

void clear(char arr[N])
{
		/****************************
	int i,j,m,l;
	for(i=0;i<N;i++)
	{
		l = strlen(arr);
			if(arr[i] == arr[i+1])
			{
				for(j=i;j<l;j++)
				{
					for(m=j;m<l;m++)
					{
						arr[m+1] = arr[m+2];
					}
					m--;
				}
				j--;
			}
			
	}
	printf("clear\n");
	puts(arr);
	*********************************************/
		int i,j,k,m;
			m=strlen(arr);
		for(i=0;i<m;i++)
		{
			m=strlen(arr);
			if(arr[i] == arr[i+1])
			{
				for(j=i;j<m;j++)
				{
					arr[j+1] = arr[j+2];
				}
				i--;
			}
		}
	printf("clear\n");
		printf("%s\n",arr);
}

void order(char brr[N])
{
	int n;
//	printf("brr-1--->\n");
	puts(brr);
	n = strlen(brr);
	int i,j;
	char k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(brr[i] > brr[j])
			{
				k = brr[i];
				brr[i] = brr[j];
				brr[j] = k;
		//	printf("k:%c\n",k);
			}
		}
	}
//			printf("k:%c\n",k);
//	printf("brr-2--->\n");
	for(i=0;i<n;i++)
	{
		putchar(brr[i]);
	}
	printf("\n");
}

void in_put(char bn[N])
{
	int n;
	printf("请输入一个字符串：");
	/*
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%c",&bn[i]);
	}
	*/
	scanf("%s",bn);
//	printf("输入字符串：");
//	puts(bn);
}
