#include<stdio.h> 

#define  N (100)
int mystrcmp(char* s1, char* s2 );
int input(char* a, int n);

int main() 
{
	char str1[N], str2[N];
	int re_mystrcmp;

	input(str1,0);
	input(str2,1);

	re_mystrcmp = mystrcmp(str1,str2);
	
	puts("After mystrcmp\n");
	printf("re_mystrcmp = %d\n",re_mystrcmp); 

	 return 0; 
}

int input(char* a, int n)
{
	if (n==0)
	{
		printf("please input str1\n");
	   gets(a);	
	
	}
	else 
	{
		printf("please input str2\n");
		gets(a);
		
	}
	 return 0; 
}

int mystrcmp(char* s1, char* s2 )
{
		int i, j, flag = 0;

		for (i=0; *(s1+i) != '\0'; i++);
		for (j=0; *(s2+j) != '\0'; j++);
		if (i >j)
				return (*(s1+j) - *(s2+j));

		else if (i<j)

				return (*(s1+i) - *(s2+i));

		else
		{
				for (i = 0 ; *(s1+i) != '\0'; i++)
				{
						if (*(s1+i) != (*(s2+i)))
								return (*(s1+i) - *(s2+i));
				}	
		}

		return 0;

}
