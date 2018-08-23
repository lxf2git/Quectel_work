#include<stdio.h>

int main()
{
		int h,l,i,j;
		char ch;
		printf("请输入一个字符：\n");
		scanf("%c",&ch);
		printf("请输入每行个数：\n");
		scanf("%d",&l);
		printf("请输入要输入行数：\n");
		scanf("%d",&h);
		for(i=0;i<h;i++)
		{
			for(j=0;j<l;j++)
					printf("%c",ch);
			printf("\n");
		}


		return 0;
}
