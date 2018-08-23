#include<stdio.h>
int main()
{
	int n,m,i,j,x,h,flag,k=0,l=0,max=0;
	int c[100];
	int d[100];
	char a[100];
	char b[100];
	printf("输入一个字符串:\n");
	scanf("%s",a);
	m=(int)strlen(a);
	printf("再输入一个字符串:\n");
	scanf("%s",b);
	n=(int)strlen(b);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				x=i;
				k=0;
				l++;
				while(a[i]==b[j])
				{	k++;
					i++;
					j++;

				}
				c[l]=k;//计算串长度
				d[l]=x;//记录位置
			}
		}
	}
	for(i=0;i<l;i++)
	{
		if(max<c[i])
		{
			max=c[i];//最大串长
			flag=i;
		}
	}
	h=d[flag];//
	i=d[flag];//最大长度对应a的位置
	for(i;i<h+max;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");

	return 0;
}
