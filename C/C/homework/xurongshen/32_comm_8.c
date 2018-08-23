#include<stdio.h>
#include<string.h>
#define N 10

void look(char arr[N],char brr[N]);
void in_put(char bn[N]);
void output1(int *p1, int n);
void move1(char a1[N],char a2[N],int a,int b,int count,int l);

int main()
{
	char a1[N]={};
	char a2[N]={};
	in_put(a1);
	in_put(a2);
	look(a1,a2);
	return 0;
}

void look(char arr[N],char brr[N])
{
	puts(arr);
	puts(brr);
	int m,n,t=0,l=0;//t标志第一个相同，l-a是相同的步长
	m=strlen(arr);
	n=strlen(brr);
	int i=0,j=0,a,b;
	char * pa,pb;
	int count=0;
	int max;
	int c[N]={},t;
	int max,mstart,mlast;
	int c[N]={},t;
	int max,mstart,mlast;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if((t == 0)&&(arr[i] == brr[j]))
			{
				a=i;//arr数组的首地址
				l = i;//arr数组的尾地址
				b=j;//brr数组的首地址
				pa = &arr[i];
				pb = &brr[j];
				t=1;//标志确定首地址
				count=1;//计数
			}
			if(arr[i] == brr[j])
			{
				printf("a=%d,b=%d,pa=%d,pb=%c\n",a,b,i,brr[j]);
	for(i=a,j=b;i<m;i++,j++)
	{
		if((a1[i+k] == a2[j+k])
			&& (i+k)<m && (j+k)<strlen(a2))
		{
			count++;
			l = i+k;
		}
		else
		{break;}
		k++;
	}
	if(max<count)
	{
		t=0;
		max=count;
		mstart = a;
		mlast = l;
	}

			}
		}
	for(i=mstart,j=0;i<=mlast;i++)
	{
		c[j] = a1[i];
		j++;
	}
	c[j]='\0';
	printf("\n");
		printf("%s\n",c);
	}
}
#if 0
void move1(char a1[N],char a2[N],int a,int b,int count,int l)
{
	int i,j,m,k=1;
	m=strlen(a1);
	int c[N]={},t;
	int max,mstart,mlast;

	printf("count:%d  lend:%d\n",count,l);
	printf("相同的个数t:%d\n",count);
}
#endif
void output1(int *p1, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c",*p1);
		p1++;
	}
	exit(0);
}

void in_put(char bn[N])
{
	int n;
	printf("请输入一个字符串：");
	scanf("%s",bn);
}
