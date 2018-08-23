#include<stdio.h>
#include<stdlib.h>
#define N 10
#define M 20
void output(char **p_1,void **aver);
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
int main(int average,char *aver[])
{
	FILE *fp = fopen(aver[1],"r");
	char *p_1[N];
	int i=0;
	while(i<N)
	{
		i++;
		getmemory((void **)&p_1[i],sizeof(char)*M);
		fread(p_1[i],M,1,fp);
	}
	output(p_1,(void **)aver);
	fclose(fp);
	return 0;
}
void output(char **p_1,void **aver)
{
	FILE *fp=fopen(aver[0],"w");
	int i=0;
	while(i<N)
	{
		i++;
		fwrite(p_1[i],M,1,fp);
	}
	fclose(fp);
}
