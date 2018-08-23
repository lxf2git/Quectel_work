#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void creat_memory(void **p,int size)
{
		 *p=malloc(size);
}

int main()
{
       int i,j=0,n=1;
	   int max=0;
       char *str;
	   int *initial;
	   int *length;
       creat_memory((void **)&str,100*sizeof(char));
	   creat_memory((void **)&initial,100*sizeof(int));
	   creat_memory((void **)&length,100*sizeof(int));
       printf("输入一句英文（找最长单词）\n");
       gets(str);
	    *(initial+0)=0;

	   for(i=0;i<strlen(str);i++)
	   {
			if(*(str+i)!=32&&*(str+i)!='.')
			{
					*(length+j)=n;
					n++;
					//printf("length%d=%d\n",j,*(length+j));
			}
			else
			{
					j++;
					*(initial+j)=i+1;
					//printf("initial%d=%d\n",j,*(initial+j));
					n=1;
			}
	   }

	   for(j=0;j<100;j++)
	   {
			   if(max<*(length+j))
			   {
					   max=*(length+j);
			   }
	   }

	   for(j=0;j<100;j++)
	   {
	   		if(*(length+j)==max)
	   		{
	   			for(i= *(initial+j);i< (*(initial+j)+*(length+j));i++)
	   			{
			   			printf("%c",*(str+i));
	   			}
	   			printf("\n");
	   		}
	   }

	   free(str);
	   str=NULL;
	   free(initial);
	   initial=NULL;
	   free(length);
	   length=NULL;
	   return 0;
}
