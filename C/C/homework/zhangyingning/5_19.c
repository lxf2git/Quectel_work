#include<stdio.h>

int in_put(int a[11]);
int put_(int a[11]);
int main()
{
	int a[11];
	in_put(a);
	put_(a);
	return 0;
}

int in_put(int a[11])
{
	int w;
printf("请输入十个数\n");
	for(w = 0;w < 10;w++)
	{
		scanf("%d",&a[w]);
	}
	printf("请输入一个要寻找的数\n");
	scanf("%d",&a[10]);
}

int put_(int a[11])
{
	
	int w;
	for(w = 0;w < 10;w++)
	{
		if(a[10] == a[w])
		{
			printf("与%d相等的下标是%d",a[10],a[w]-1);
			return 0;
		}
	}
	printf("sorry, not found!");

}
