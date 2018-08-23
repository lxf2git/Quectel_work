#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j,m;
	char str_old[1024]={};
	printf("输入一个字符串");
	for(i=0;;i++)
	{
	scanf("%c",&str_old[i]);
		if(str_old[i]=='\n')
			break;
	}
	m=strlen(str_old)+strlen(str_old)/3;
	char *str_new;
	str_new=(char*)malloc(m*sizeof(char));
	if(str_new==NULL)
	{
		printf("malloc error!");
		exit(0);
	}


	for(i=0,j=0;;i++,j++)
	{
		if(str_old[i]=='\n')
		{	break;}
			*(str_new+j)=str_old[i];
		if((i+1)%3==0)
		{
			j++;
			*(str_new+j)=' ';
		}
	}
		
		printf("%s",str_new);
	return 0;
}
