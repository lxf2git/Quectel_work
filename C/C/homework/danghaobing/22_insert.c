#include<stdio.h>
int main()
{	char a[100]={};
	char p[100]={};
	int i,m,w;
	for(i=0;i<100;i++)
	{
		scanf("%c",&a[i]);
			if(a[i]=='\n')
			{
					a[i]='\0';
					break;
			}
			w=i;
			for(;w>0;w--)
			{
				if(a[w-1]>=a[w])
				{
					m=a[w];
					a[w]=a[w-1];
					a[w-1]=m;
				}
			}
	}
	for(i=0;;i++)
	{
			if(a[i]=='\0')
					break;
			p[i]=a[i];
	}
	puts(p);
	char b;
	printf("请输入要插入的字符：\n");
	scanf("%c",&b);
	getchar();
	for(i=0;i<50;i++)
	{
			if(b>=a[i]&&b<a[i+1]||a[i+1]=='\0')
			{
					printf("%d\n",i);
					m=i+1;
					a[m]=b;
					for(;;)
					{
							m++;
							a[m]=p[m-1];
							if(p[m]=='\0')
							break;
					}
					break;	
			}
			if(b<a[i]&&i==0)
			{
					m=i;
					a[m]=b;
					for(;;)
					{
							m++;
							a[m]=p[m-1];
							if(p[m]=='\0')
							break;

					}
					break;
			}
	}
	puts(a);
}
