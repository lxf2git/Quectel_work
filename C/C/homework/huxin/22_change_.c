#include<stdio.h>
#include<string.h>
#define N 12
void maopao(char a[]);

int main()
{   
	int l;	
	char a[N]="#19AZaz}";
    char b[2];
	puts(a);
	printf("please input in ch :\n");
    for(l=0;l<1;l++)
	{
	 scanf("%c",&b[l]);
    }
	strcat(a,b);
    maopao(a);
	puts(a);
	return 0;
}
void maopao(char a[])
{  
   int i,j;
   char t;

   for(j=0;j<N-4;j++)
   {
   		for(i=0;i<N-4-j;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
   }
}
