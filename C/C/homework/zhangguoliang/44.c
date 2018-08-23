#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str_old[1024];
	char *str_new;
	int n,m,i,j;
	printf("输入字符串a:\n");
	scanf("%s",str_old);
	m=strlen(str_old);
	n=m/3+m;
	str_new=(char *)malloc(n*sizeof(char));
	for(i=0,j=0;i<n;i++,j++)
	{
		*(str_new+i)=str_old[j];
		if((j+1)%3==0)
		{
			i++;
			*(str_new+i)=' ';
		}
		if(*(str_new+n-1)==' ')
			*(str_new+n-1)='\0';

	}
	printf("%s\n",str_new);
	if(str_new!=NULL)
	{
		free(str_new);
		str_new=NULL;
	}
	return 0;
}

