#include<stdio.h>
char * mystrcpy(char *dest,char *src);

int main()
{   
		int n;
		char str_a[100];
		char str_b[100];
		printf("please input in str_a :\n");
		gets(str_a);
		printf("please input in str_b : \n");
		gets(str_b);
		mystrcpy(str_a,str_b);
		printf("str_a : %s\n",str_a);
		return 0;
}
char *mystrcpy(char *dest,char *src)
{
		char ch;
		ch=*src;
		if(ch=='\0')
		{
				return(src);
		} 
		else
		{
				for(;ch!='\0';)
				{
				
						*dest=*src;
						dest++;
						src++;
						ch=*src;
				}
				*dest=ch;
				return(dest);
		}
}

