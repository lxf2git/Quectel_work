#include<stdio.h>
int main()
{
	char a[100]={};
	char x;
	int i,n,min,j;
	printf("输入一个字符：");
	scanf("%c",&x);
	getchar();
	printf("输入一串字符：");
	for(i=0;i<100;i++)
	{  	
	scanf("%c",&a[i]);
		if(a[i]=='\n')
			break;
	}

	
	  for(j=0;j<100;j++)
	{	n=i;
		for( ;n>=0;n--)
			{
				if(a[n-1]>a[n])
				{ 
					min=a[n];
					a[n]=a[n-1];
					a[n-1]=min;
				}
			}
	}	
	puts(a);
	return 0;
}
