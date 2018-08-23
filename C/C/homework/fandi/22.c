#include<stdio.h>
#define N 6
int main()
{
	char a[N],t;
	int i;
	for(i=0;i<N;i++){
			scanf("%c",&a[i]);
			getchar();
	}
	for(i=5;i>=0;i--){
			if(a[i]<a[i-1]){
				t=a[i-1];
				a[i-1]=a[i];
				a[i]=t;
			}
	}
	for(i=0;i<N;i++)
			printf("%c",a[i]);
	return 0;
}
