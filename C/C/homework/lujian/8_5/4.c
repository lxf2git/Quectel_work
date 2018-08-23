#include<stdio.h> 
#include<string.h> 

int input(char a[]);
#define  N  (100)

int main()
{
	char str1[N], str2[N], str3[N];
	int i, j, k = 0,d1 = 0;
	input(str1);
	input(str2);
	if (strlen(str1)<strlen(str2))
	{
			for (i = 0; i<strlen(str1); i++)
			{
					d1 = str1[i+1] - str1[i]; 

					for (j =0; j<strlen(str2); j++)
					{
							if (d1==str2[j+1] -str2[j])
							{
									str3[k] = str1[i];
									k++;	
									break;
							}

					}
			}
			str3[k] = '\0';
	}
	else
	{
			for (i = 0; i<strlen(str2); i++)
			{
					d1 = str1[i+1] - str1[i]; 

					for (j =0; j<strlen(str1); j++)
					{
							if (d1==str1[j+1] -str1[j])
							{
									str3[k] = str2[i];
									k++;	
									break;
							}

					}
			}
			str3[k] = '\0';
	}

	
	puts(str3);


	 return 0; 
}

int input(char a[])
{
	printf("please \n");
   	gets(a);	

	return 0; 
}
