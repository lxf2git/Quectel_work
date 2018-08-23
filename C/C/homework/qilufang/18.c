#include<stdio.h>

int main()
{
	int i;
	float input[10],max,min,sum,aver;
	printf("请评分：\n");
	scanf("%f",&input[0]);
	max=min=input[0];
	for(i=0;i<10;i++)
	{
		scanf("%f",&input[i]);
		if(max<input[i])
		{
			max=input[i];
		}
		if(min>input[i])
		{
			min=input[i];
		}
		sum+=input[i];
	}
	aver = (sum-max-min)/8.0;
	printf("小伙你的平均成绩是：%f\n",aver);

	return 0;	
}
