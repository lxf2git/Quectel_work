#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 30
#define N 5
void change(char *p[N]);
void fuzhi(int *pa,char *p_1[N],char *p[N]);
void input(char *p[N]);
void output(char *p[N]);
void cmp(void **p);
/***********创建空间**************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!");
		exit(-1);
	}
}
/***********主函数**************/
int main()
{
	int i;
	char *p[N];
	printf("input %d string:\n",N);
	input(p);
	change(p);
	cmp((void **)&p);
	output(p);
	for(i=0;i<N;i++)
	{
		if(p[i]!=NULL)
		{
			free(p[i]);
			p[i]=NULL;
		}
	}
	return 0;

}
/***********输入函数*************/
void input(char *p[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		getmemory((void **)&p[i],M*sizeof(char));
		printf("number%d: ",i+1);
		scanf("%s",p[i]);
	}
}
/**********输出函数************/
void output(char *p[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%s\n",p[i]);
	}
}
/**********赋值函数 1*********************/
void change(char *p[N])
{
	int i,j,m=0,k;
	int *pa;
	char *p_1[N];
	getmemory((void **)&pa,N*sizeof(int));
	for(i=0;i<N;i++)
	{
		getmemory((void **)&p_1[i],M*sizeof(char));
		*(pa+i)=strlen(p[i]);
	}
	for(j=0;j<N;j++)
	{
		m=0;
		for(k=*(pa+j)-1;k>=(*(pa+j))/2;k--)
		{
			*(p_1[j]+m)=*(p[j]+k);		//将字符串后一半赋值给新的空间
			m++;
		}
	}
	fuzhi(pa,p_1,p);
}
/***************赋值函数2**************/
void fuzhi(int *pa,char *p_1[N],char *p[N])
{
	int i,j=0,k,m;
	for(;j<N;j++)
	{
		for(k=0;k<*(pa+j);k++)
		{
			*(p[j]+k)=*(p_1[j]+k);		//将字符串后一半赋值给前一半
		}
	}
	for(m=0;m<N;m++)
	{
		printf("len[%d]:%d\n",m+1,*(pa+m));
	}		
}
/**************比较函数**************/
void cmp(void **p)
{
	int i,j;
	char *min;
	getmemory((void **)&min,M*sizeof(char));	//比较函数大小并排序
	for(i=0;i<N;i++)
	{	
		for(j=0;j<N;j++)
		{
			min=p[j];
			if(strcmp(p[j],p[j+1])==1)
			{
				*(p+j)=*(p+j+1);
				*(p+j+1)=min;
			}
		}
	}
}

