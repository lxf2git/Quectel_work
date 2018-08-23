#include"mystrcmp.h"

void  mystrcmp(char *str1,char *str2)
{
	int i=0,k=0;
	int len1=strlen(str1);
	int len2=strlen(str2);	
	if(len1<len2)
		printf("-1\n");
	if(len1>len2)
		printf("1\n");

	if(len1==len2)
	{
		for(i=0;i<=len1-1;i++)
		{
			if(*(str1+i)!=*(str2+i))
				k=*(str1+i)-*(str2+i);break;				
			if(*(str1+i)==*(str2+i))
			{	
				k=*(str1+i)-*(str2+i);
				i++;	
			}			
		}
		if(*str1==*str2)
			printf("0\n");
		if(*str1<*str2)
			printf("-1\n");
		if(*str1>*str2)
			printf("1\n");
	}		
}


