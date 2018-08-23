#include"str_sort.h"

void  str_input(char str[])
{
		int i,j,k;
		char exchange;//init;
		gets(str);
		i=strlen(str);
		//init=str[0];
		for(j=0;j<i;j++)
		{
				for(k=j;k<i;k++)
				{

						if(str[j]>str[k])
						{
								exchange= str[j];
						 		str[j] = str[k];
								str[k] = exchange;
						}
				}
		}
		//puts(str);


}
