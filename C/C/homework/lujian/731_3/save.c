 #include"main.h"
extern double balance;	
int save()
{
	int sum;
	int i;
	printf("please save money: (>100) \n");
	scanf("%d",&sum);
	
	for (i = 0; i < 3; i++)
	{
			printf("*******");
			sleep(1);
	}

	balance += sum;

	printf("save compelet!\n");
}
