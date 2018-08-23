#include<stdio.h>
#include<string.h>
void input(char *a);
void str_rank(char *a,char *b);
int main()
{
		char a[100];
		char b[100];
		input(a);
		input(b);
		str_rank(a,b);
}
void input(char *a)
{
		scanf("%s",a);
}
void str_rank(char *a,char *b)
{
		int i,j,k,l,m;
		char med[100]={};
		char end[100]={};
		for(i=0;i<strlen(a);i++)
		{
				for(j=0;j<strlen(b);j++)
				{
							for(k=i,m=j,l=0;a[k]==b[m];k++,m++,l++)
									med[l]=b[m];
							med[l]='\0';
							
//							printf("%s\n",med);
							if(strlen(med)>strlen(end))
							{
									strcpy(end,med);
							}
				}
				j=0;
		}
		printf("%s\n",end);



}
