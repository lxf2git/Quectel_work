#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

void create_memory(int m)
{
	char *p[m];
	char *a[m];
	char *c;
	int i,j,b,s,g,k=0,l[m];
	for(i=0;i<m;i++)
	{
		p[i]=(char *)malloc(N*sizeof(char));
		printf("输入第%d字符串\n",i+1);
		scanf("%s",p[i]);
		l[i]=strlen(p[i]);
		b=l[i];
		a[i]=(char *)malloc(b*sizeof(char));
		for(j=b-1;j>b/2-1;j--)
		{
			*(a[i]+k)=*(p[i]+j);
			k++;
		}
		j=0;
		k=0;
	}
	g=0;
	for(s=0;s<m;s++)
	{		
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				k=strcmp(a[i],a[j]);
				if(k>=0)
				{
					g++;
					if(g==m&&a[j]!="zzzzzzz")
					{	printf("%s ",p[j]);
						g=0;
						a[j]="zzzzzzz";
					}
				}
			}
		}
	}
}

int main()
{
	int m;
	printf("输入字符串个数:\n");
	scanf("%d",&m);
	create_memory(m);
	printf("\n");
	return 0;
}
