#include<stdio.h>
#include<stdlib.h>

/*void creat_merory(void **p,int size)
{
	*p=malloc(size);
}*/

void fan(char *p)
{
	int i,m=0,w[50],h=0,max=0,j;
	for(i=0;;i++)
	{
		if(p[i]>=65&&p[i]<=90||p[i]>=97&&p[i]<=122)
		{
			m++;
		}
		if(p[i]==32||p[i]==46)
		{
			if(max<m)
			{
				max=m;
			}
				m=0;
		}
			if(p[i]==46)
			{
			
					break;
			}
			
	}
	printf("max:%d\n",max);
}
int main ()
{
	char *p=NULL;
	int n=100,i;
	printf("N:");
	scanf("%d",&n);
	getchar();
	p = (char *)malloc(n*sizeof(char));		 //	creat_merory((void *)&p,n*sizeof(char));
	printf("input:");
	for(i=0;;i++)
	{
		scanf("%c",&p[i]);
		if(p[i]==10)
		{
			p[i]=0;
			break;
		}
	}
	fan(p);

	return 0;
}







