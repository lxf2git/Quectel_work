#include<stdio.h>
#include<string.h>

void input (char str[]);

int main()
{	
	char str[300]={0};
	input(str);
	puts(str);
	
	return 0;
}

void input (char str[])
{
	char ch;
	int i=0,j=0;
	gets(str);
//	while(str[i] != 0)
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='c')
		{
			for(j=i;j<strlen(str);j++)
			{
				str[j]=str[j+1];
//				i--;
			}
			i--;
		}
//		i++;
	}

}
