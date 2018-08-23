#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]={0},b[100]={0},c[127]={0};
	int size1,size2,n,m;
	int i,j,s;
	printf("请输入一个字符串:");
	scanf("%s",a);
	getchar();
	printf("在输入一个字符串:");
	scanf("%s",b);
	size1=(int)strlen(a);
	size2=(int)strlen(b);
	i=size1;
	j=size2;
	for(n=0;n<100;n++)
	{	
		size1=i-1;
		for(;size1>=0;size1--)
		{
			if(a[size1]<a[size1-1])
			{
				m=a[size1];
				a[size1]=a[size1-1];
				a[size1-1]=m;
			}
		}
	}

	printf("%s\n",a);

	for(n=0;n<100;n++)
	{	
		size2=j-1;
		for(;size2>=0;size2--)
		{
			if(b[size2]<b[size2-1])
			{
				m=b[size2];
				b[size2]=b[size2-1];
				b[size2-1]=m;
			}
		}
	}
	printf("%s\n",b);

	strcat(a,b);
	printf("%s\n",a);
	for(s=0;s<128;s++)
	{
		for(;i>=0;i--)
		{
			if(s=a[i])
			{
				c[s]=a[i];

			}


		}

	}
	for(s=0;s<128;s++)
	printf("%c",c[s]);
}

