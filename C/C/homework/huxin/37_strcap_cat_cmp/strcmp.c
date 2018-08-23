#include<stdio.h>
int mystrcmp(char *s1,char *s2);

int main()
{
		int n;
		char str_a[100];
		char str_b[100];
		printf("please input in str_a :\n");
		gets(str_a);
		printf("please input in str_b : \n");
		gets(str_b);
		n=mystrcmp(str_a,str_b);

		printf("%d\n",n);
		return 0;
}
int mystrcmp(char *s1,char *s2)
{
		char ch,ch1;
		do
		{
				ch=*s1;
				ch1=*s2;
				s1++;
				s2++;

		}while(ch==ch1&&ch!='\0'&&ch1!='\0');
		if(ch>ch1)
		{
				return(1);
		}
		else 
		{
				if(ch==ch1)
		        {
				return(0);
		        }
		        else
		        {
				return(-1);
		         }  
          }  
}

