#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	printf("输入一个字符串:\n");
	scanf("%s",a);
	printf("输入一个字符串:\n");
	scanf("%s",b);
	compare(a,b);
	return 0;
}

int compare(char *p,char *q)
{
	int m,n,i=0,j=0,k=0,h,max=0,l=0,f;
	int c[100],d[100];
	char *p1=p,*x;
	char *q1=q,*y;
	m=(int)strlen(p);
	n=(int)strlen(q);
	for(p=p1;i<m;i++)
	{
		p=p1+i;
		for(q=q1;j<n;j++)
		{
			q=q1+j;
			if(*p==*q)
			{
				l++;
				k=0;
				x=p;
				y=q;
				while((*p)==(*q))
				{
					p++;
					q++;
					k++;
				}
				c[l]=k;
				d[l]=x;
				p=x;
				q=y;
			}
		}
		j=0;
	}

	
	if(k==0)
	{
		printf("没有相同字符\n");
		return 0;
	}
	for(i=1;i<l+1;i++)
	{
		
		if(max<c[i])
		{
			max=c[i];
			f=i;
		}
	}
	i=d[f];
	h=d[f];

	for(i;i<h+max;i++)
	{
		p=i;
		printf("%c",*p);
	}
	printf("\n");
	return 0;
}


