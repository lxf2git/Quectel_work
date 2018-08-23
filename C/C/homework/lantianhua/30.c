#include<stdio.h>
#include<string.h>

void subtract(char string[]);
void rank(char string[]);
int main()
{
	char string1[100]={};
	char string2[100]={};
	printf("please input string1\n");
	gets(string1);
	printf("please input string2\n");
	gets(string2);
	rank(string1);
	rank(string2);
	rank(strcat(string1,string2));
	subtract(string1);
	return 0;
}
void rank(char string[])

{	int a,i,j,tmp;
	a=strlen(string);
	for(i=0;i<a-1;i++)
	{
		for(j=i+1;j<a;j++)
		{
			if(string[i]>string[j])
			{
				tmp=string[j];
				string[j]=string[i];
				string[i]=tmp;
			}
		}
	}
	printf("%s\n",string);
}

void subtract(char string[])
{
	int i,a,j;
	a=strlen(string);
	for(i=0;i<a;i++)
	{		
		
	a=strlen(string);
		if(string[i]==string[i+1])
		{	
			for(j=i;j<a;j++)
			{
				string[j+1]=string[j+2];
			}
				
			i--;		
               		}
			
				
			

	}	
	printf("%s\n",string);
}

