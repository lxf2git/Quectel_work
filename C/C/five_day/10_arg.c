#include<stdio.h>

void input(int arr[5])//arr=0x12345678
{
	
	int i;	
	printf("input\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}

}

void output(int brr[5])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d\n",brr[i]);
	}
}

int main()
{
	int a[5];
	input(a);//&a[0]
	output(a);
	

/*	
*/		
	return 0;
}
