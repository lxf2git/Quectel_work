#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void deal_rank(char *p);
int main()
{
		char a[100]={};
		printf("input string of char\n");
		scanf("%s",a);
		deal_rank(a);

		return 0;
}
void deal_rank(char *p)
{
		int j,i;
//		char m;
		for(j=0;j<strlen(p);j++)
//		for(i=j;i<strlen(p);i++)
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
