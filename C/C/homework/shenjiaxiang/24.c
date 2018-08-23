#include<stdio.h>
#include<string.h>
void no(char *p);
int main()
{
		char a[100]={};
		printf("input string of char\n");
		scanf("%s",a);
		no(a);
		return 0;
}
void no(char *p)
{
		int j,i;
		for(j=0;j<strlen(p);j++)
		{
				if(*(p+j)=='c')
				{
						for(i=j;i<strlen(p);i++)
						*(p+i)=*(p+i+1);
						j--;

				}						
		}
		printf("%s",p);
}
