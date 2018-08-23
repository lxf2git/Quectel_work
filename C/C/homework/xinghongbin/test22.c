#include<stdio.h>
#include<string.h>
int judge_str(char str[]);
int main()
{
		int m;
		char a[100];
		scanf("%s",a);
		m=judge_str(a);
		printf("%d\n",m);
}

int judge_str(char str[])
{
		int i,j,l,length,d;
		length=strlen(str);
				d=length;
				for(i=0,l=0,j=length-1;i<j;i++,j--)
						if(str[i]==str[j])
								l++;

		if(l==d/2)
				return 0;
		else
				return -1;
}
