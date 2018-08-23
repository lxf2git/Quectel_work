#include<stdio.h>
#include<string.h>
int main()
{
		int no,d=0,n=10,i=0,b,j,l=10;
		char a[10]={};
	printf("please input in nober:\n");
	scanf("%d",&no);
	printf("%d\n",sizeof(no));
	do
	{
		d=no%n;
		n=n*10;
	    i++;
	}while(d!=no);
	for(j=i-1;j>=0;j--)
	{
	    b=no%10;
        no=no/10;
		a[j]=b+48;
	}
	printf("%s\n",a);
	printf("%d\n",strlen(a));

	return 0;

}
