#include<stdio.h>

int main()
{
	char a[100];
	int i,j;
	int character,word,line;
	line=0;word=0;
	
	printf("请输入如正文：\n");
	for(i=0;i<100;i++)
	{
			scanf("%c",&a[i]);
			if(a[i]==32)
			{
				word++;
			}
			if(a[i]=='.')
			{
					line++;
					printf("\n");
			}
			
			if(a[i]=='\n')
					break;
	}
	printf("%d   %d   %d\n",i-line-word,word+line,line);

	return 0;
}
