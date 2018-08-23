#include<stdio.h>

int main()
{
		char a[100];
		int i,j,n,k;
		printf("请输入字符串\n");
		gets(a);
		n=strlen(a);
		for(i=0;i<n;i++)
		{
				if(a[i]=='c')
				{
						a[i]=1;
						for(j=i;j<n;j++)
						{
							k=a[j+1];
							a[j+1]=a[j];
							a[j]=k;
							printf("这里是for循环");
						}
						i--;
				}	
		}
		puts(a);

		return 0;
}
