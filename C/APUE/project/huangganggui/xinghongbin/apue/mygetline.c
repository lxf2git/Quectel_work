#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 120
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream);
int main()
{
		FILE *fp;
		fp = fopen("a","r");
		if(fp == NULL)
		{
				perror("a");
				return(-1);
		}
		char *str = NULL;
		int len = 0;
		int ret = 0;
		do
		{
				ret = mygetline(&str,&len,fp);
//				ret = getline(&str,&len,fp);
				if(ret != -1)
						fwrite(str,1,ret,stdout);
				printf("mainlen:%d\n",len);

		}while(ret != -1);
		return 0;

}
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{
		int size = 0;
		int ret = 0;
		int count = 0;
		if(*lineptr == NULL)
		{
				*lineptr=(char *)malloc(SIZE);
				size = SIZE;
				*n = size;
		}
		else
		{
				size = *n;
		}

		if(!fgets(*lineptr,size,stream))
				return -1;
		ret = strlen(*lineptr);
		
//		printf("getlineret:%d\n",ret);
		
		while((*lineptr)[ret-1] != 10)
		{

				count ++;
//				if(size %120 !=0)
//						size = 120 -size%120;
//				else
//				{
						if(size >=480)
								size +=1;
						else
								size = 2*size;
//				}
				*lineptr = (char *)realloc(*lineptr,size);
				*n = size;
//		printf("size:%d\n",size);

				fgets(&(*lineptr)[ret],size-ret,stream);
				ret =strlen(*lineptr);
//		printf("getlineret:%d\n",ret);
//		printf("%d %d\n",(*lineptr)[ret-1],(*lineptr)[ret]);

		}
		
		return ret;
}

