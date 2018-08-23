#include"mygetline.h"

void create_memory(void **p,int size)
{
		*p = malloc(sizeof(char)*size);
		if(*p==NULL)
		{
				perror("malloc");
		}
}
void build_memory(char **lineptr,int n)
{
			if(*lineptr==NULL)
				create_memory((void **)lineptr,n);
			else
			{
					*lineptr = realloc(*lineptr,sizeof(char)*n);
					if(*lineptr==NULL)
					{
							perror("relloc");
					}
			}

}
int mygetline(char **lineptr,int *n,FILE *fp)
{
		char ch;
		char *arr;
		int i;
		create_memory((void **)(&arr),1);
		for(i=0;(ch=fgetc(fp))!=EOF;i++)
		{
				arr = realloc(arr,i+2);
				arr[i] = ch;
				if('\n'==arr[i])
				{
						arr[i+1] = '\0';
						//printf("size:%d\n",i+2);
						if(*n>=i+2)
						{
								if(*lineptr==NULL)
									create_memory((void **)lineptr,*n);
						}
						else if((i+2)<120&&*n<120)
						{
								*n=120;
								build_memory(lineptr,*n);
						}
						else if((i+2)<=240&&(i+2)>120&&*n<240)
						{
								*n=240;
								build_memory(lineptr,*n);
						}
						else if((i+2)<=480&&(i+2)>240&&*n<480)
						{
								*n=480;
								build_memory(lineptr,*n);
						}
						else
						{
								*n=i+2;
								build_memory(lineptr,*n);
						}
						strcpy(*lineptr,arr);
						return i+1;
				}
		}
		return ch;
}
