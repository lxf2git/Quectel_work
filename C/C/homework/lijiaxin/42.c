#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void choice(char *p,int length);
void creat_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q == NULL)
		{
				printf("malloc err!\n");
				exit(-1);
		}
}
int main()
{
		char *str=NULL;
		int length;
		printf("请输入你需要的字符空间:\n");
		scanf("%d",&length);
		getchar();
		 creat_memory((void **)&str,length*sizeof(char)); 
		printf("请输入英语句子:\n");
		gets(str);
		choice(str,length);
		return 0;

}
void choice(char *p,int length1)
{
		int i,j,count1=0,count2=0;
	    char *str2=NULL,*str1=NULL;
		 creat_memory((void **)&str1,length1*sizeof(char)); 
		 creat_memory((void **)&str2,length1*sizeof(char)); 
		char *q;
		char ch[]=" ";
		q = ch;
		puts(p);
		puts(q);
		i = strlen(p);
		for(j=0;j<i;j++)
		{
				if(p[j]!=' ' && p[j]!='.')
				{
						printf("count1:%2d\n",count1);
						str1[count1] = p[j];
						count1++;
						printf("count1:%2d\n",count1);
				}
				else //if(p[j]==' ')
				{ 
						if(count1>count2)
						{
							count2 = count1;
							strcpy(str2,str1);  
							count1 = 0;
						printf("str2:%s\n",str2);
						}
						
						 if(count1 == count2)
						{
							strcat(str2,q);
							strcat(str2,str1);
							count1 = 0;
						printf("str2:%s\n",str2);
						}
						 else
								 count1 = 0;
						printf("count2:%2d\n",count2);


				}
		}
		puts(str2);
}
