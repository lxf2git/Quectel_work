#include<stdio.h>
#include<string.h>
void smm();
int main()
{
		smm();
		return 0;
}

void smm()
{
		int a[100]={0},b[100]={0};
		char s1[100]={'\0'},s2[100]={'\0'};
		gets(s1);
		gets(s2);
		int N=strlen(s1);
		int M=strlen(s2);
		int i,j,n,m=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
					if(s1[i]==s2[j])
					{
							n=1;
						while(s1[i+n]==s2[j+n])
						{
							n++;
						}
						if(n>1)
						{
						a[m]=i;
						b[m]=n;
						//printf("b[m]=%d\n",b[m]);
						m++;
						}
					}
			}
		}
		int max=b[0];
		int p=0;
		for(i=0;i<100;i++)
		{

				if(b[i]>max)
				{
						max=b[i];
						p=i;
				}
		}
		for(i=a[p];i<(a[p]+max);i++)
		{
				printf("%c",s1[i]);
		}
}
