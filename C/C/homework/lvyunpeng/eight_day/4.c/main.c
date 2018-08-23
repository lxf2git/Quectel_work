#include<stdio.h>
int main()
{
	int i,j,size1,size2,k,l=0,h,flag,x,c[100]={0},d[100]={0},max=0;
	char a[100]={0},b[100]={0};
	printf("输入两个字符串:");
	scanf("%s",a);
	getchar();
	scanf("%s",b);
	size1=(int)strlen(a);
	size2=(int)strlen(b);
	i=size1;
	j=size2;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			x=i;
			k=0;
			l++;
			if(a[i]==b[j])
			{
				k++;
				i++;
				j++;

			}
			c[l]=k;
			d[l]=x;
		}

	}
	for(i=0;i<l;i++)
	{
		if(max<c[i])
		{
			max=c[i];
			flag=i;
		}

	}
	h=d[flag];
	i=d[flag];
	for(i;i<h+max;i++)
	{
		printf("%c",a[i]);

	}
	printf("\n");

	return 0;
}
