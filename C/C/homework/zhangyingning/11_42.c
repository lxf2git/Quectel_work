#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

char *malloc_()
{
	char *p;
	p = (char *)malloc(N * sizeof(char));
	return p;

}
char in_put(char *p)
{
	printf("请输入一句话");
	gets(p);
	return *p;
}
int compare(char *p)
{
	int max = 0,max1 = 0;
	int i, j,ii;
	j = strlen(p);
	for(i = 0;i < j;i++)
	{
		if(*(p + i) == ' ' || *(p + i) == '.')
		{
			max1 = 0;
		}
		max1++;
		if(max < max1)
		{
			max = max1;
		}
	}
	return max;
}
void uot_put(char *p,int max)
{
	printf("最长数组\n");
	char *p_max = NULL;
	p_max = malloc_();
	int b = 0, j, i;
	j = strlen(p);
	for(i = 0;i < j;i++)
	{
		if(*(p + i) == ' ' || *(p + i) == '.')
		{
			b = 0;
		}
		else	
		{
			*(p_max + b) = *(p + i);
			b++;
			if(max - 1 == b)
			{
				*(p_max + b) = '\0';
				printf("%s\n",p_max);
			}
		}
	}
	if(NULL != p_max)
	{
		free(p_max);
		p_max = NULL;
	}
}



int main()
{
	char *p = NULL;
	int max;
	p =  malloc_();
	*p = in_put(p);
	max = compare(p);
	uot_put(p,max);
//	printf("\n%d  %s",max-1,p);
	if(NULL != p)
	{
		free(p);
		p = NULL;
	}


}
