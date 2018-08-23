#include<stdio.h>
int main()
{
	char a[2],b[2],c[4];
	int i,j;
	printf("输入2位数a：");
	for(i=0;i<2;i++)
		{scanf("%c",&a[i]);}
		getchar();
	printf("输入2位数b：");
	for(j=0;j<2;j++)
		{scanf("%c",&b[j]);}

 //  	c[0]=a[1];c[1]=b[0];c[2]=a[0];c[3]=b[1];
	printf("%c%c%c%c\n",a[1],b[0],a[0],b[1]);




	return 0;
}
