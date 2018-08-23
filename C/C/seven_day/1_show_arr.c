#include<stdio.h>

void print(int arr[],int n)//
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("arr[%d]:%d ",i,arr[i]);
	}
	printf("\n");

}

int main()
{
	int a1[3]={2,4,6};
	int a2[5]={3,4,5,6,7};
	int a3[4]={1,3,5,7};

	print(&a1[0],3);//&a1[0]  a1	
	print(a2,5);//&a2[0]  a2	
	print(a3,4);//&a2[0]  a3	
	return 0;
}


