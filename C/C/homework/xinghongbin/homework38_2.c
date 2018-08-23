#include<stdio.h>
int remainder_test(int a);
int power(int a,int i);
int main()
{

		int a,i,s;

		scanf("%d",&a);
		scanf("%d",&i);

		s=power(a,i);
		remainder_test(s);
		return 0;
}

int power(int a,int i)
{
		if(i>0)
		{
				return a*power(a,--i);
		}
		return 1;

}
int remainder_test(int a)
{
		int b;
		if(a==0)
			return 0;
		b=a%10;
		a/=10;
		remainder_test(a);
		printf("%d\n",b);

}
