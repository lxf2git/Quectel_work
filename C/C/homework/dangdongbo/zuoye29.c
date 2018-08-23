#include<stdio.h>
int main()
{
		char ch[100]={};
		int n=0,i,m=0,k=0;
		gets(ch);
	for(i=0;i<100;i++)
	{
			if((ch[i]>=65&&ch[i]<=90)||(ch[i]>=97&&ch[i]<=122))
			k++;
		if(ch[i]=='.')
				n++;
		if(ch[i]==' ')
				m++;
		printf("%c",ch[i]);

	}

	printf("%d %d %d",k,n+m,n);
}
