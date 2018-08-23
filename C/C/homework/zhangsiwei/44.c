#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void output(char str_old[],char *str_new,int n,int j)
{
	int k,i,m;
	strcpy(str_new,str_old);
	printf("this is output\n");
	for(i=0,k=0;i<n;i++)
	{
		k++;
		if(k==4)
		{
			for(m=j;m>i-1;m--)
			{
				*(str_new+m+1)=*(str_new+m);
			}
			*(str_new+i)=' ';
			j+=1;
			k=0;
		}
	}
	printf("%s\n",str_new);

}
void create_memory(char **str_new,int n)
{
	*str_new = (char *)malloc(n*sizeof(char));
	if(NULL==str_new)
	{
		printf("memory error\n");
		exit(-1);
	}
}
void input(char str_old[])
{
	printf("please input char\n");
	scanf("%s",str_old);
}
int main()
{
	char str_old[1024];
	char *str_new;
	int i,n;
	input(str_old);
	i=strlen(str_old);
	printf("i=%d\n",i);
	if(n%3!=0)
		n=i+i/3;
	else
		n=i+i/3-1;	
	printf("n=%d\n",n);
	create_memory(&str_new,n);	
	output(str_old,str_new,n,i);
	if(str_new!=NULL)
	{
		free(str_new);
		str_new = NULL;
	}

	return 0;
}
