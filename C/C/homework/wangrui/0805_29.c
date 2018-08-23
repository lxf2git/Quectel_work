#include<stdio.h>
#define N 100

void input();

int main()
{
	printf("输入两次回车退出输入！\n");
	input();	
	return 0;
}

void input()
{
	int i;
	int character, word, line;
	int	a[N]={};
	character=0;
	word=0;
	line=0;
	for(i=0;i<N;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]==32)
		{
			if(a[i-1]==46||a[i-1]==10||a[i-1]==32)continue;
			word++;
		}
		else if(a[i]==46)
		{
			if(a[i-1]==46||a[i-1]==10||a[i-1]==32)continue;
			line++;
			word++;
		}
		else if(a[i]==10)
		{
			if(a[i-1]==46||a[i-1]==32)continue;
			if(a[i-1]==10)break;
			continue;
		}
		else
		{
			character++;
		}
		
	}
	
	printf("character=%d\nword=%d\nline=%d\n",character,word,line);
	
}
