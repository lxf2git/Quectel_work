#include<stdio.h>
#define N 10
int main()
{
	char a[N],b[N];
	int i,n=0,m=0;
	for(i=0;i<N;i++){
			scanf("%c",&a[i]);
			getchar();
	}
	for(i=0;i<N;i++){
			if(a[i]!='c'){
					b[n]=a[i];
					n+=1;
					m+=1;
			}
	}
	for(n=0;n<=m-1;n++)
	printf("%c",b[n]);
	return 0;
}
