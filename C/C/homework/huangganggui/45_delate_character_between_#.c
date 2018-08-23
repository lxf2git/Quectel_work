#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void create_memory(char **string);
void deal(char *string);

int main()
{
	char *string=NULL	;
	create_memory(&string);
	scanf("%s",string);
	
	
	deal(string);

	puts(string);
	

	return 0;
}

void create_memory(char **string)
{
	*string=(char *)malloc(100*sizeof(int));
	if(NULL == *string)
	{
		printf("Memory Create Error!\n");
		exit(-1);
	}
}

void deal(char *string)
{
	int i,k;
	while(0 != *(string))
	{
		if('#' == *string)
		{	
			int flog = 0;
			for(i = 1;0 != *(string+i);i++)
			{
				if('#' == *(string+i))
				{
					for(k=0;;k++)
					{	
						flog=1;
						*(string+k)=*(string+k+i+1);
						if(0==*(string+k+1))
						{
							break;
						}
					}
					string--;
				
					
					
					
					break;
					
				}
			}

			if(0 ==flog)
			{
				*string =0;
				return ;
			}

		
		}
	string++;
	}
}
