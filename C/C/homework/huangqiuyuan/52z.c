#include<stdio.h>
#define N 3
#define M 10


int main()
{
	int i,j,a=0,b=0,c=0;
	char x;
	printf("请给a b c三个候选人投票：\n");
	for(i=0;i<M;i++)
	{
		printf("第%d个人投票给",i+1);
		scanf("%c",&x);
		if(x=='a')
			a++;
		if(x=='b')
			b++;
		if(x=='c')
			c++;
		getchar();
	}
		printf("a得%d票\n",a);
		printf("b得%d票\n",b);
		printf("c得%d票\n",c);


	return 0;
}
