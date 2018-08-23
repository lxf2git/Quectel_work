  #include<stdio.h> 
#define N 10
#define M 1

int tick_1,tick_2,tick_3;

int xuan3()
{
	tick_3=tick_3+M;
}
int xuan2()
{
	tick_2=tick_2+M;
}
int xuan1()
{
	tick_1=tick_1+M;
}
void print()
{
	printf("第一候选名%d第二候选人%d第三候选人%d\n",tick_1,tick_2,tick_3);
}
int main()
{
	int ticket,tick_nu=0;
	for(;tick_nu<N;tick_nu++)
	{
		printf("第%d位投票者,请为候选人投票,1.一号候选人2.二号候选人3.三号候选人\n",tick_nu+M);
		scanf("%d",&ticket);
		int (*use[3])()={xuan1,xuan2,xuan3};
		use[ticket-M]();
	}
	print();
}
