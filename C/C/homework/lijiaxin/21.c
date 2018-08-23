#include<stdio.h>
#include<string.h>

int main()


{
		int inter,inter1;
		char a[4]={0};
		int i,j,count=0;

		printf("请输入一个小于4位的整数:\n");
		scanf("%d",&inter);
		inter1=inter;
		do
		{
			inter1/=10;
			count++;
		}while(inter1!=0);
		if(inter<0)
		{
				a[0] = '-';
				inter=-inter;
	
	//	printf("%d",count);
	//	int i,j;
	//	char a[4]={'0'};
	//	a[0]='-';
			for(i=0;i<count;i++)
			{
					j = inter%10;
					a[count-i] = j+48;
					inter/=10;

			}
		
		}
		else
		{
			for(i=0;i<count;i++)
			{
					j = inter%10;
					a[count-1-i] = j+48;
					inter/=10;

			}

		}
		puts(a);
		return 0;
}
