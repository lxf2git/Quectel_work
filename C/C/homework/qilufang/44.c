#include<stdio.h>
#include<stdlib.h>
void assign(char *p_1,char *p_2);
void Memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("Memory_error!");
		exit(-1);
	}
}
int main()
{
	char *str_1=NULL;
	char *str_2=NULL;
	Memory((void **)&str_1,30*sizeof(char));
	Memory((void **)&str_2,30*sizeof(char));
	printf("输入一个字符串：\n");
	scanf("%s",str_1);
	assign(str_1,str_2);
	printf("赋值后输出：\n");
	printf("%s\n",str_2);

}
void assign(char *p_1,char *p_2)
{
	int i,j=0,k=0;
	for(i=0;i<30||*(p_1+i)!='\0';i++)
	{	k++;
		 if(i==0)
		{
			
			*(p_2+i)=*(p_1+j);
		}
		else if(k%4!=0&&i!=0)
		{
			j++;
			*(p_2+i)=*(p_1+j);
		}
		else if(k%4==0&&i!=0)
		{
			*(p_2+i)=32;
		}

	}
}
