#include<stdio.h>

int main()
{
	int ch,line=0,character=0,word=0;
	while( (ch = getchar()))
	{
		if(10 == ch)
		{
			line++;
			if( (ch=getchar())==10 )     // double enter
			{
				break;
			}else
			{
				character++;
			}

		}
		 else if('?'==ch||'!'==ch||' ' == ch||'.' ==ch)
		{
			word++;
		}else
		{
			character++;
		}
			
	}
	printf("character:%d word:%d line:%d\n",character,word,line);
	return 0;
}
