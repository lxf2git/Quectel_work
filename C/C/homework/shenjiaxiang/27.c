#include<stdio.h>
void combine(int a,int b);

int main()
{
		int a,b;
		printf("input a b\n");
		scanf("%d%d",&a,&b);
		combine(a,b);
		return 0;
}
void combine(int a,int b)
{
		int c;
		int arr[2][2]={a/10,a%10,b/10,b%10};
		c=arr[0][0]*100+arr[0][1]+arr[1][0]*1000+arr[1][1]*10;
		printf("%d\n",c);

}
