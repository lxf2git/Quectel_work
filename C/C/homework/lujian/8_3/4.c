#include<stdio.h>
#define N (100)
int delet_c(char a[]);
int main()
{
	char a[N];

	gets(a);	

	delet_c(a);
		
	puts(a);
	return 0;
}

int delet_c(char a[])
{	
	int i, j;

	for (i = 0, j = 0 ; a[i] !='\0'; i++)
	{
		if (a[i] != 'c')
		{
			a[j++] = a[i];
		}
	
	}
		
	a[j] = '\0';


 return 0;

}
