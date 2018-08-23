#include"mystrcpy.h"



char mystrcpy(char *str1,char *str2)
{
	int i;
	for(i=0;i<N;i++)
	{
		*(str1+i)=*(str2+i);
	}
	return *str1;
}



