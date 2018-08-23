#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000

void change(char *p,int n);
int main()
{
	int i,n;
	char *p;
	p = malloc(N*sizeof(char));
	printf("please input char:\n");
	for(i=0;i<N;i++)
	{
			scanf("%c",p+i);
			if(*(p+i)=='\n')
			{
					*(p+i)='\0';
					break;
			}
	}	
	n=strlen(p);
	printf("n=%d\n",n);
/*	for(i=0;i<N;i+=j+1)
	{
		static j=1;
		if(*(p+i)!='#')
		{
			for(k=n;n>i;n--)
			{
				*(p+n+j)=*(p+n);
			}	
			for(m=0;m<j;m++)
			{
				*(p+i+m)='#';
			}

			n+=j;
			j+=2;
		}
		
	}   */
	change(p,n);
	puts(p);
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}
	
	return 0;
}

void change(char *p,int n)
{
	int i,m,j,k;
	for(i=0;i<N;i++)
	{
		static j=1;
		if(*(p+i)!='#')
		{
			if(*(p+i+1)=='\0')
					break;
			for(k=n;k>i;k--)
			{
				*(p+k+j)=*(p+k);
			}	
			for(m=1;m<=j;m++)
			{
				*(p+i+m)='#';
			}

			n+=j;
			j+=2;
		}
		
	}
	
}
