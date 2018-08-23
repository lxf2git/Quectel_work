 #include"main.h"
//extern double balance;
int withdraw()
{
	int sum;
	int i;
	printf("pleae withdraw sum:\n");
	do
	{
	scanf("%d",&sum);
	}while ( ((sum%100) != 0) && (sum > balance)
				&& printf("please money 100 ~ 2000000 \n"));
	for (i = 0; i < 5; i++)
	{
	printf("withdraw :$$$$$$$\n");
	sleep(1);
	}
	balance-=sum;
	sleep(2);
	printf("withdraw money complete!");
	
	return 0;

}
