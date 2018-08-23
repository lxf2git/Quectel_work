#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int create_memory(char **point,int size)
{
	int space;
	space=size/3;
	if(size%3==0)
		space--;
	*point=(char*)malloc((size+space)*sizeof(char));
	if(NULL==*point)
	{
		printf("malloc error");
		exit(-1);
	}
	return size+space;
}
int main()
{
	char str_old[1024]={};
	char *str_new;
	int size,new_size,nu_old=0,nu_new,i_old;
	printf("请输入字符串。");
	scanf("%s",str_old);
//	printf("%s",str_old);
	size=strlen(str_old);
	new_size=create_memory(&str_new,size);
	for(nu_new=0;nu_new<new_size;nu_new++)
	{
		for(i_old=0;i_old<3;i_old++)
		{
			*(str_new+nu_new)=str_old[nu_old];
//			printf("nu_new:%c\n",*(str_new+nu_new));
			nu_old++;
			nu_new++;
		}
		if(nu_new+1!=new_size)
			*(str_new+nu_new)=' ';
//		printf("nu_new:%c\n",*(str_new+nu_new));
		i_old=0;
	}
	printf("str_new:%s",str_new);
	printf("\n");
}
