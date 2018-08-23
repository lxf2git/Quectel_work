#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void scan(char *str)       //输入字符串
{
		printf("请输入字符串:\n");
		scanf("%s",str);
}

void creat_memory(void **p,int s)   //开空间
{
		s=s+s/3;
		*p=malloc(s*sizeof(char));
}

void transmit(char *str_old,char *str_new,int n)   //传送
{
		int i,j=0,m=0;
		for(i=0;i<n;i++)
		{
				*(str_new+j) = *(str_old+i);
				j++;
				m++;
				if(m==3)
				{
						*(str_new+j) = 32;
						m=0;
						j++;
				}
		}
}

int main()             //主函数
{
		char str_old[1024];
		char *str_new;
		scan(str_old);
		//printf("%s",str_old);

		creat_memory((void **)&str_new,strlen(str_old));

		transmit(str_old,str_new,strlen(str_old));

		printf("%s\n",str_new);

		free(str_new);
		str_new=NULL;
		return 0;
}
