#include<stdio.h>
int main()
{
	int a[]={33,44,55,66,77};
	int *p = a;
	p += 2;
	printf("%d\n",(*p)++);//a[2]++
	p = a;
	printf("%d\n",p[2]);//a[2]++
	printf("size:%d\n",sizeof(long));
}
