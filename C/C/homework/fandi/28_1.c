#include<stdio.h>
#define N 5
int main()
{
	int a[N][N],i,j,t,min,n,b[N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);
			getchar();
		}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
				t=a[i][0];
				if(t<a[i][j]){
					n=a[i][j];
					a[i][j]=t;
					t=n;
					b[i]=t;
		}
				else
						b[i]=t;
			}
		
	t=b[0];
	for(i=0;i<N;i++){
			printf("各行最大数分别为:%d\n",b[i]);
			min=t<b[i]?t:b[i];
	}
	printf("各行最大数中最小数为:%d\n",min);
	return 0;
}
