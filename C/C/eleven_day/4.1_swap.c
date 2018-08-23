#include<stdio.h>

void swap(int *pa,int *pb)//m=8 n=9
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int a=8,b=9;
	printf("bf-a:%d b:%d\n",a,b);	
	swap(&a,&b);//改变变量的值 要传变量的地址 
	printf("af-a:%d b:%d\n",a,b);	
	return 0;

}




