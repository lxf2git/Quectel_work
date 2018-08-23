#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUC 0
#define FAIL -1
#define N 1000
int change_nb(long *nb,long i)
{
	if(i+2<120&&*nb<120)
	{
		*nb=120;
		return 120;
	}
	else if(i+2>=120&&i+2<240&&*nb<240)
	{
		*nb=240;
		return 240;
	}
	else if(i+2>=240&&i+2<480&&*nb<480)
	{
		*nb=480;
		return 480;
	}
	else if(*nb<i+2)
	{
		*nb=i+2;
		return i+2;
	}
	else
	{
		return *nb;
	}
}
void change_arr(char **arr,char *arr_1)
{
	strcpy(*arr,arr_1);
}
int mygetline(char **arr,long *nb,FILE *fp)
{
	long i=0;
	long ret=0;
	char ch;
	char arr_1[N]={'0'};
	while((ch=fgetc(fp))!=10)
	{
		arr_1[i]=ch;	
		if(ch==-1)
		{
			return FAIL;
		}
		i++;
	}
	arr_1[i]='\n';
	ret=change_nb(nb,i);
	*arr=malloc(sizeof(char)*ret);
	change_arr(arr,arr_1);
	return SUC;
}
void destory(char **arr)
{
	if(*arr!=NULL)
	{
		free(*arr);
		*arr=NULL;
	}
}
int main()
{
	long len=0;
	int ret=0;
	char *arr=NULL;
	FILE *fp;
	if((fp=fopen("./file","r"))==NULL)
	{
		perror("open");
		return FAIL;
	}
	while(1)
	{
		ret=mygetline(&arr,&len,fp);
		printf("Len:%d\n",len);
		if(ret<0)
		{
			break;
		}
		fwrite(arr,strlen(arr),1,stdout);
	}
	destory(&arr);
	fclose(fp);
	return 0;
}
