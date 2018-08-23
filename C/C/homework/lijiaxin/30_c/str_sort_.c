#include"str_sort.h"

void str_sort(char str[],char str1[])
{
		int i,j,k,l;
		char exchange;
		strcat(str,str1);
	//	puts(str);
		i = strlen(str);
		for(j=0;j<i;j++)
		{
				for(k=j;k<i;k++)
				{
						if(str[j]>str[k])
						{
								exchange = str[j];
								str[j] = str[k];
								str[k] = exchange;
						}
				}
		}
		puts(str);
		for(j=0;j<i;j++)
		{
			for(l=j;l<i;l++)
			{
					if(str[j] == str[j+1])
					{
							for(k=j;k<i;k++)
							{
									str[k] = str[k+1];		
							}				
					}
			}
			//	puts(str);
			//	printf("%d\n",j);
			//	break;
			
		}
		puts(str);
}
