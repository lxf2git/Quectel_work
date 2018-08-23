#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
#define M 20
void count(char *p);
void put(int max,char *str,int *arr,int *len);
int Max(int *p,int len);
/***********创建空间函数************/

void Memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("ERROR!\n");
		exit(-1);
	}
}
/************主函数******************/

int main()
{
	char *str=NULL;
	printf("输入一个句子以'.'结尾\n");
	Memory((void **)&str,N*sizeof(char));
	gets(str);
	count(str);
	if(str!=NULL)
	{
		free(str);
		str=NULL;
	}
	return 0;

}
/***********执行函数*******************/
void count(char *p)
{
	int *arr=NULL;
	int *len=NULL;
	int i=0,j=0,n=1,max=0,k,l,count=0;
	Memory((void **)&arr,M*sizeof(int));
	Memory((void **)&len,M*sizeof(int));
	do{
				i++;
				if(*(p+i)!=32&&*(p+i)!='.')
				{
					n++;
					*(len+j)=n;				//记住没个单词的长度
				}
				else if(*(p+i)==32)
				{
					j++;
					*(arr+j)=i+1;			//记住每个单词首字母的地址
					n=0;
					count=j;				//共多少个单词
				}
			
		}while(*(p+i)!='.'&&i<strlen(p));
		for(k=0;k<=count;k++)
		{
			printf("len[%d]:%d\n",k+1,*(len+k));  //输出每个单词的长度
		}
		max=Max(len,strlen(p));					//得出最长单词长度
		put(max,p,arr,len);
		if(len!=NULL||arr!=NULL)
		{
			free(len);
			free(arr);
			len=NULL;
			arr=NULL;
		}	
}
/****************比较单词长度函数****************/

int Max(int *p,int len)
{
	int max=0,i;
	for(i=0;i<len;i++)
	{
		if(*(p+i)>max)
		{
			max=*(p+i);
		}
	}	
	return max;
}
/***************输出函数************************/

void put(int max,char *str,int *arr,int *len)
{
	int i,j=0,k;
	for(i=0;i<strlen(str);i++)
	{
		if(*(len+i)==max)				//当字母最长时的首字母地址
		{
			j=*(arr+i);
		}
	}
	printf("首地址:%d  最长单词长度:%d\n",j,max);
	printf("输出最长字母：");
	for(k=j;k<j+max;k++)
	{
		printf("%c",*(str+k));
	}		
	printf("\n");
}
