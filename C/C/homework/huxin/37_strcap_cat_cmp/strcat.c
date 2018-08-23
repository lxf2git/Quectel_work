#include<stdio.h>
char *mystrcat(char *dest,char *src);

int main()
{
		int n;
		char str_a[100];
		char str_b[100];
		printf("please input in str_a :\n");
		gets(str_a);
		printf("please input in str_b : \n");
		gets(str_b);
		mystrcat(str_a,str_b);
		puts(str_a);
		return 0;
}
char *mystrcat(char *dest,char *src)
{
		char ch,ch1;
		ch=*dest;
		ch1=*src;
		for(;ch!='\0';)
		{
				dest++;
				ch=*dest;
				if(ch=='\0')
				{
						for(;ch1!='\0';)
						{
								*dest=*src;
								dest++;
								src++;
								ch1=*src;
						}
				}
		}
		*dest='\0';
		return(dest);
}

