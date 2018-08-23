#include"mystrcat.h"
#define N 5

char mystrcat(char *str1,char *str2)
{
	int i,j=0;
	for(i=N;i<2*N;i++)
	{
		str1[i]=str2[j];
		j++;
		
	}
	return *str1;
}
