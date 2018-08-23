#include<stdio.h>
int main()
{
	char a;
	int c=0,w=0,l=0;
	printf("输入:\n");
	printf("结束就输入 ','吧\n");
	for(;;)
	{
		scanf("%c",&a);
		if(a>=65&&a<=90||a>=97&&a<=122)
				c++;
		if(a==32||a==46)
				w++;
		if(a==46)
				l++;
		if(a==',')
				break;
				
	}
	printf("character=%d\nword=%d\nline=%d\n",c,w,l);
	return 0;
}
