#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int input(char *str);
int regroup_str(char *str,char c);
void separate_str(char *str,int i,char c);
int main()
{
		int i;
		char c;
		char str[200];
		c=input( str );
		i=regroup_str( str , c );
		separate_str( str , i , c );
		
		return 0;
}
int input(char *str)
{
		char c;
		printf("input str min to max\n");
		scanf("%s",str);
		printf("input c\n");
		getchar();
		scanf("%c",&c);
		return c;
}

int regroup_str(char *str,char c)
{
		int i;
		for(i=0;i<strlen(str);i++)

			if(str[i]<=c && str[i+1]>c)

					return i+1;

}
void separate_str(char *str,int i,char c)
{
		char str1[100]={};
		char *p = (char*)malloc(100);
		p=&str[i];
		strcpy(str1,p);                          //相应位置的字符串 地址给指针
		 										// 复制字符串	

		str[i]=c;								//增加成员				
		str[i+1]='\0';



		strcat(str,str1);						//重新链接			
		printf("%s\n",str);

}


