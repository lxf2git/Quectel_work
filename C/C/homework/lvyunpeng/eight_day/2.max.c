#include<stdio.h> 
#define max(a,b) if(a>b){m=a;} else{m=b;}
int main()
{ 
	int a,b,m;
	printf("请输入两个数\n");
	scanf("%d%d",&a,&b);
	max(a,b);
	printf("%d\n",m);
}
