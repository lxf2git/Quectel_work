#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int creat_memory((char **)p,int *l);
void input(char *p,int l);
int main()
{
	char *str;
	int len;
	len=creat_memory(&str,&len);
	input(str,len);
	deal();
	return 0;
}

deal()
{
	for(i=0;i<l;i++)
	{
		if()
	}
}

void input(char *p,int l)
{
	printf("Sentence:\n");
	scanf("%s",p);
	*(p+l)=0;
}

int creat_memory((char **)p,int *l)
{
	printf("Len:\n");
	scanf("%d",l);
	*p=(char *)malloc((*l+1)*sizeof(char));
}
