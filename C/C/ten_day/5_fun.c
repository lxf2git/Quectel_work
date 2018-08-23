#include<stdio.h>

void fun(int *p,int n)//p=a 
{
	
	while(n>0)
	{
		//printf("%d ",*(p+i));//p[i]  a[i] *(a+i)
		printf("%d",*p);
		p++;//
		n--;
	}
	
}
int main()
{
	int i;	
	int a[5]={1,2,3,4,5};
	a++;

	fun(a,5);//
	
	return 0;

}
