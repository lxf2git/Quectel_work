#include"main.h"

void arithmetic(char str[])
{
		
	int	i,j;
	i = strlen(str);
	for(j=0;j<i;j++)
	{
			if(str[j]==' ')
					word++;
			else if(str[j]=='.')
			{
					line++;
					word++;
			}
			else
					character++;

	}
}
