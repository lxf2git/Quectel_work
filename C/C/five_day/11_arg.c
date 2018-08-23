#include<stdio.h>

void change(int arr[100])
{
	printf("xxxxxxxxxxxxxxxxxxx\n");	
	printf("arr:%p\n",arr);	
	printf("size:%d\n",sizeof(arr));
	int i;	
	for(i=0;i<5;i++)
	{
		arr[i]+=6;	
	
	}
	
}

int main()
{
	int i;	
	int a[5]={10,20,30,40,50};
	printf("a:%p\n",a);
	change(a);
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
		
	return 0;
}
