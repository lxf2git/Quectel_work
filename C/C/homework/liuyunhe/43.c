#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void creat_memory(void **p,int size)
{
		        *p=malloc(size);
}

int main()
{
		int i,j=0,n;
		char *str;
		char *str2;
		creat_memory((void **)&str,100*sizeof(char));
		creat_memory((void **)&str2,100*sizeof(char));
		printf("输入字符串\n");
		gets(str);
		if(strlen(str)==1)
		{
				*str2=*str;
		}
		else
		{
			for(i=0;i<strlen(str);i++)
			{
				*(str2+j)=*(str+i);
				j++;
				n=0;
				if(i!=strlen(str)-1)
				while(n<(i*2+1))
				{
						*(str2+j)='#';
						n++;
						j++;
				}
			
			}
		}
		printf("%s\n",str2);
		free(str);
		str=NULL;
		free(str2);
		str2=NULL;
		return 0;
				
}
