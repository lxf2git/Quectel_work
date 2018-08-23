#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define N 30
int main() 
{
		char *p;
		int i,j,x=0;
		p = (char *)malloc(N*sizeof(char));
		printf("请输入一串字符\n"); 
		scanf("%s",p);
		for(i=0;i<strlen(p);i++)
		{
				printf("%c",*(p+i));
						if(*(p+i+1)=='\0')
						break;
						for(j=0;j<(2*x+1);j++)
						{
								printf("#");
						}
						x++;
		}
}
