#include<stdio.h> 

#define  N (100)

char * mystrcat(char* dest, char* src);
int input(char* a, int n);

int main() 
{

	char str1[N], str2[N];
	char* dest;

	input(str1, 0);
	input(str2, 1);

	dest = mystrcat(str1, str2);


	puts("After mystrcat :");
	puts(dest);

	 return 0; 
}

int input(char* a, int n)
{
	if (n == 0)
	{
		printf("please input dest string \n"); 
		gets(a);
	
	}

	else
		{
		 printf("please input src string\n"); 
			gets(a);
		}
	
     return 0; 
}

char * mystrcat(char* dest, char* src)
{
	int i, j;
	
		for (i=0; *(dest+i) != '\0'; i++ );

		
		for (j = 0; *(src+j) != '\0'; i++, j++)
		{
		
			*(dest+i) = *(src+j);
		
		}
		
		*(dest+i) = '\0';


	 return dest; 
}







































