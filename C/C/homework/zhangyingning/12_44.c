#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void malloc_(char **p,int lenght)
{
	*p = (char *)malloc(lenght * sizeof(char ));
}
void out_put(char str_old[1024],char *str_new,int lenght)
{
	int a ,b = 0;
	*str_new = str_old[0];
	for(a = 1;a <= lenght;a++)
	{
		if((a + 1) % 4 == 0)
		{
			*(str_new + a) = ' ';
		}
		else
		{
			b++;
			*(str_new + a) = str_old[b];
		}
	}
	printf("%s\n",str_new);
}

int main()
{
	int lenght = 0;
	char str_old[1024]= {'0'};
	char *str_new;
	printf("请输入一串字符");
	scanf("%s",str_old);
	lenght = strlen(str_old);
	lenght += lenght / 3;
	malloc_(&str_new,lenght);
	out_put(str_old,str_new,lenght);
	if(str_new != NULL)
	{
		free(str_new);
		str_new = NULL;
	}
	return 0;
}
