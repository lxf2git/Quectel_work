#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count(char *string);

int main()
{
	char *string;
	string=(char *)malloc(100*sizeof(char));
	if(NULL == string)
	{
		printf("ERR!\n");
		exit(-1);
	}
	gets(string);
//	*(string+strlen(string)-1)=0;
	puts(string);
//	printf("%d\n",strlen(string));
	count(string);
	return 0;
}

void count(char *string)
{
	int i=0,n=0,k;
	int max=0,maxi=0;
	while('\0'!= *(string + i))
	{
		
		n = 0;
		for(k=0;;k++)
		{
			if(' ' == *(string+i+k)||'.' == *(string+i+k))
			{
				
				break;
			}
			n++;
		}
			if(max < n)
			{
				maxi = i;
				max = n;

				
			}
		i++;
	}
//	printf("i:%d\n",i);
//	printf("max:%d,maxi:%d\n",max,maxi);
	for(i=maxi;' ' != *(string+i)&&'.' != *(string+i);i++)
	{
//		printf("here\n");
		printf("%c",*(string+i));
	}
	printf("\n");
}

