#include<stdio.h>
void weishu();

int main()
{
	weishu();
	return 0;
}

void weishu()
{
	int a,b=0;
	printf("输入一个正数\n");
	scanf("%d",&a);
	if(a!=0)
	{	
		while(a!=0)
		{
			a=a/10;
			b++;
		}
	}
	 else
	{
		b=1;
	}
  printf("是%d位数",b);
}

