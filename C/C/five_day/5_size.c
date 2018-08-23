#include<stdio.h>

int main()
{
	int i;	
	int a[5];
	

	for(i=0;i<5;i++)
	{
		printf("a[%d]:%p\n",i,&a[i]);
	}

	printf("%d\n",sizeof(a));	
	printf("%d\n",sizeof(int[5]));
	printf("a:%p\n",a);//&a[0]
	return 0;
}
