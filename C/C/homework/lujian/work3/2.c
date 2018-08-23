#include<stdio.h>
int max(int a, int b, int c);
int min(int a, int b, int c);
int main()
{
		int a, b, c;
		printf("please input a b c:\n");
		scanf("%d%d%d",&a,&b,&c);
		printf("the MAX=%d\n", max(a, b, c));
		printf("the MIN=%d\n", min(a, b, c));
		printf("the MAX-MIN=%d\n",max(a, b, c)-min(a, b, c));
		return 0;
}
int max(int a,int b,int c)
{
		return (c > (a > b ? a : b))? c : (a > b ? a : b);
}


int min(int a, int b, int c)
{
		return (c < (a < b ? a : b)) ? c : (a < b ? a : b);
}
