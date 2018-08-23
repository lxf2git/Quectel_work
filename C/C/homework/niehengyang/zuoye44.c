#include<stdio.h>
#include<string.h>
int len(int);
char add(char str_old[1024],int ret);

int main()
{
	int ret,t;
	char str_old[1024];
	printf("please input str_old:");
	scanf("%s",&str_old);
	t=strlen(str_old);
	ret=len(t);
	 add(str_old,ret);
	
}

int len(int t)
{
	int ret;
	ret=t/3+t;
	return ret;
}

char add(char str_old[1024],int ret)
{
	printf("%s\n",str_old);
	printf("%d\n",ret);
	char *str_new;
	str_new=(char *)malloc(ret*sizeof(char));
	int i,count=0;
	int j=0;
	for(i=0;i<ret;i++)
	{
		count++;
		str_new[i]=str_old[j];
		j++;
	//printf("%s\n",str_new);
	//printf("%d %d",i,j);
		if(count%4==0)
		{
			str_new[i]=32;
			count=0;
			j=j-1;
		}
	}
	printf("%s\n",str_new);
}
