#include<stdio.h>
#define N 20
int main()
{
	char  a[100]={'\0'},b[100]={0};
	int i,j,k;;
	printf("请输入20个以内的字符串\n");
	gets(a);
	for(j=0;j<N;j++)
	for(i=0;i<N;i++)
		if(a[i]=='c')
		{
			for(k=i;k<N-1;k++)
			a[k]=a[k+1];
		}
	printf("删除c后的字符串：%s",a);
	return 0;
}
