#include"main.h"
int main()
{
	int a[10];
	int i,m,n,sum=0;
	float y;
	printf("请十位老师打分:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	cp(a);
	ava(a);
	return 0;
}
