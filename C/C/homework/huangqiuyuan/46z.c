#include<stdio.h>
#include<string.h>

int main()

{
	char a[100]={};
	int i,j,p,m;
	printf("输入一个字符串\n");
	for(i=0;;i++)
		{
			scanf("%c",&a[i]);
				if(a[i]=='\n')
				{	a[i]='\0';
						i--;
							break;
				}
		}
		p=strlen(a);
		printf("你想右移几位：");
		scanf("%d",&j);
		m=p-j;
		for(i=m;j>0;j--,i++)
			printf("%c",a[i]);
		for(i=0;m>0;m--,i++)
			printf("%c",a[i]);







	return 0;
}
