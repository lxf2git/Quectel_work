#include"main.h"

int main()
{
		FILE *fp=fopen("a.txt","r");
		char *pstring=NULL;
		size_t n=0;
		pstring=(char *)malloc(n);
		printf("mygetline:\n");
		
		fseek(fp,0,SEEK_SET);
		while(mygetline(&pstring, &n, fp)!=-1)
		{
				printf("%s",pstring);
				printf("%d\n",n);
		}
		printf("%d\n",mygetline(&pstring, &n, fp));

	//	pstring=NULL;
		n=61;
		fseek(fp,0,SEEK_SET);

		printf("getline:\n");
		while(getline(&pstring, &n, fp)!=-1)
		{
				printf("%s",pstring);
				printf("%d\n",n);
		}
		printf("%d\n",getline(&pstring, &n, fp));
		return 0;
}

ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{
		char ch;
		int i=0;
		ch=fgetc(stream);
		if(ch==-1)
		{
				return -1;
		}
		if(*lineptr==NULL)
		{
				*n=120;
				create_memory((void **)lineptr,*n);
		}
		else
		{
				if(*n<60)
				{
						*n=120;
				}
				*lineptr=(char *)realloc(*lineptr, *n);
		}
		while(ch!='\n')
		{
				(*lineptr)[i]=ch;
				i++;
				if(i+1>=480&&i+1>=*n)
				{
						(*n)++;
						*lineptr=(char *)realloc(*lineptr, *n);
				}
				else
				{
						if(i+1==*n)
						{
								*n*=2;
								*lineptr=(char *)realloc(*lineptr, *n);
						}
				}
				ch=fgetc(stream);
		}
		(*lineptr)[i]='\n';
		i++;
		(*lineptr)[i]='\0';
		return i;
}

void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}
