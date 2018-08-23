#include<stdio.h>
#define N 10
int main()
{
	int a[N];
	int i,start,stop,t;
	printf("请输入数组:\n");
	for(i=0;i<N;i++){
			scanf("%d",&a[i]);
			getchar();
	}
	printf("请输入倒序起始位与终止位：\n");
	scanf("%d,%d",&start,&stop);
	for(start;start<=start+(stop-start)/2;start++){
			if(stop-start==1){
			t=a[stop];
			a[stop]=a[start];
			a[start]=t;
			break;
			}
			t=a[stop];
			a[stop]=a[start];
			a[start]=t;
			stop-=1;
	}
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	return 0;
}
