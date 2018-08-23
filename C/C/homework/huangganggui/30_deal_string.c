#include<stdio.h>
#include<string.h>

void input(char *str,int n);
void rearrange(char *str);
void subtract(char *str);

int main()
{
	char str1[1000]={0},str2[200]={0};
	/*
	 *input string
	 * */
	input(str1,200);
	input(str2,200);
	/*
	 *	rearange string
	 * */
	rearrange(str1);
	rearrange(str2);

	strcat(str1,str2);
	/*
	 *subtract  char which is has been in 
	 **/
	rearrange(str1);
	subtract(str1);      

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
			}
	}
	str[i]=0;
}

void rearrange(char *str)
{
	int i,j;
	int temp;
	for(i=0;str[i] != 0;i++)
		for(j=i;str[j] != 0;j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	puts(str);
}

void subtract(char *str)
{
	int i,j,k;
	for(i=0;str[i] != 0;i++)
		for(j=i+1;str[j-1] != 0;j++)
		{
			if(str[i] == str[j])
			{
				for(k=j;str[k]!=0;k++)
				{
					str[k]=str[k+1];

				}
				j--;
			}
		}
	puts(str);	
}
