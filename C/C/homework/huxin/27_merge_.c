#include<stdio.h>

int main()
{
	int a,b,c;
	int un,hu,de,ma;
	printf("please input in :\n");
	scanf("%d%d",&a,&b);
    un=a%10;
    hu=a/10%10;
    de=b%10;
    ma=b/10%10;
	c=ma*1000+hu*100+de*10+un;
 	printf("%d\n",c);	
	return 0;
}
