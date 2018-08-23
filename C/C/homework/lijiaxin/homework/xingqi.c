#include<stdio.h>

int main()
{
	int a;
	printf("please enter 1~7 :");
	scanf("%d",&a);
	switch(a)
	{
		case 1:printf("MON\n");break;
		case 2:printf("TUE\n");break;
		case 3:printf("WED\n");break;
		case 4:printf("THU\n");break;
		case 5:printf("FRI\n");break;
		case 6:printf("SAT\n");break;
		case 7:printf("SUN\n");break;
	}

	return 0;
}
