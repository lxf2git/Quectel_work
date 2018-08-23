#include<stdio.h> 
#define  N  (100)
int input(char* a, int n);
char * mystrcpy(char* dest, const char* src);
int main() 
{
	
	char str1[N],str2[N];
	char * dest;
	input(str1,0);
	input(str2,1);
	dest = mystrcpy(str1, str2);
	
	puts("Afetr mystrcpy");	
	puts(dest);

}	

int input(char* a, int n)
{	
		if(n == 0)
		{
				printf("plese input dest string\n"); 

				gets(a);
		}
		else
		{
				printf("please input src string\n"); 
				gets(a);

		}
		return 0; 
}



char * mystrcpy(char* dest,const char* src)
{
		int i;

	for (i = 0; src[i] !='\0'; i++)
	{
			*(dest+i) = *(src+i);
	}
 
		*(dest+i) = '\0';

		return dest; 
}
