#include<stdio.h>

int main()
{
int word,space,s,other;
char a;
printf("请输入一段字符串\n");
word=0,space=0,s=0,other=0;
while((a=getchar())!=10)
 	if ((a>=65&&a<=90)||(a>=97&&a<=122))
{	
	word=word+1;
}	
else if(a==32)
{
	space=space+1;
}
else if(a>=48&&a<=57)
{
	s=s+1;
}
else 
	other=other+1;
	
	printf("word:%d\nspace:%d\ns:%d\nother:%d\n",word,space,s,other);
	return 0;
	}
