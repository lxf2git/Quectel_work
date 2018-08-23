#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str_input(char **a);
void creat_memory(char **p,int size);
void str_output(char **p,int j);
int main()
{
		int j;
		int i;
		char **p;
		creat_memory((char **)&p,100);
		for(i=0;i<10;i++)
				creat_memory((char **)p+i,2);				
//		printf("输入字符串长度\n");
//		scanf("%d",&j);
		j=str_input(p);
		str_output(p,j);
}
void creat_memory(char **p,int size)
{
		*p=malloc(size);
}
int str_input(char **a)
{
		int i,j;
		printf("输入字符串用空格分开 回车结束输入\n");
		for(i=0;;i++)
		{
				scanf("%s",a[i]);
				if(getchar()=='\n')
						break;
				for(j=2*i+1;j>0;j--)
						strcat(a[i],"#");
		}
		
		return i+1;

}
void str_output(char **p,int j)
{
		int i;
		for(i=1;i<j;i++)
				strcat(*p,*(p+i));
		printf("%s\n",*p);

}
