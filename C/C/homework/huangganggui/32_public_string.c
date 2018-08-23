#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void input(char *str,int n);
void compare(char str1[],char str2[],char string[]);

int main()
{
	char str1[50]={0},str2[50]={0};
	char string[50]={0};

	input(str1,50);
	input(str2,50);
	
	compare(str1,str2,string);
	puts(string);
	return 0;

}

void input(char *str,int n)
{
	int i=0;

	printf("input a string:");
	for(i=0;scanf("%c",&str[i])&&(10 != str[i]);i++)
	{
		if(i == n-1)
			{
				printf("error ! string is to large !\n");
				exit(0);
			}
	}
	str[i]=0;
}

void compare(char str1[],char str2[],char string[])
{
	int i=0,j=0,n=0;
	for(i=0;str1[i] != 0;i++)
		for(j=0;str2[j] != 0;j++)
		{
			if (str1[i]==str2[j])
			{
				n=0;
				while( (str1[i+n]!=0)&&(str2[j+n]!= 0)
								&&(str1[i+n]==str2[j+n]) )
				{
					n++;              //count how many the same character
				}
				if(n > strlen(string))
				{
					string[n]=0;                  // n is count , so n-1
					for(;n>=1;n--)
					{
						string[n-1]=str1[i+n-1];   //  the same of above notes
					}
				}
			}
		}
}
