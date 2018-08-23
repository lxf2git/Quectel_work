#include<stdio.h>
#include<string.h>

void xun(char aa[20],int c)
{
		printf("%d",c);
	int a, b;
	char d;
	for(a = 0; a < c;a++)
	{
			for(b = a;b < c;++b)
			{
				if(aa[a] >  aa[b])
				{	
					d = aa[a];
					aa[a] = aa[b];
					aa[b] = d;
			 	}
			}
	}
	puts(aa);
}
int main()
{
	char aa[20] = {'0'};
	int c;
    char d;
	gets(aa);
	c = strlen(aa);
	xun(aa,c);
	printf("请输入要插入的字符");
	scanf("%c",&aa[c]);
	printf("\n输入%c",aa[c]);
	xun(aa,c+1);

}


