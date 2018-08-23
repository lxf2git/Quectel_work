#include<stdio.h>
int main()
{
		char a[100]={};
		int i,m=0,x;
		scanf("%s",a);
		for(i=0;;i++)
		{
				if(a[i]=='\0')
						break;

				if(a[i]=='c')
				{
						m++;//统计有几个c
						x=i;
						for(;;)
						{
								a[x]=a[x+1];
								x++;
								if(a[x]=='\0')
										break;
						}
						if(a[i]=='c')
						i--;
				}
		}
		printf("一共有%d个c\n",m);
		puts(a);
}
