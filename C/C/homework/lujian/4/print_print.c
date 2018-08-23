#include"main.h"
void print_print(int month, int j)
{
		int i;
		printf("%d : %d\n",year,month);
		printf("  Sun Mon Tue wed thu Fri Sat\n");
		if(month==1||month==3||month==5||month==7||
						month==8||month==10||month==12)
		{
				for(i=0;i<j;i++)
						printf("    ");
				for(i=1;i<=31;i++)
				{			
						printf("%4d",i);
						j++;
						if(j==7)
						{
								j=0;
								printf("\n");
						}
				}
				printf("\n");
		}
		else if (month==2)

		{
				if(runyear(year)==29)	
				{
						for(i=0;i<j;i++)
								printf("    ");
						for(i=1;i<=29;i++)
						{
								printf("%4d",i);
								j++;
								if(j==7)
								{
										j=0;
										printf("\n");
								}
						}
						printf("\n");
				}
				else
				{
						for(i=0;i<j;i++)
								printf("    ");
						for(i=1;i<=28;i++)
						{
								j++;
								printf("%4d",i);
								if(j==7)
								{	
										j=0;
										printf("\n");
								}
						}

				}
				printf("\n");

		}
		else
		{
				for(i=0;i<j;i++)
						printf("    ");
				for(i=1;i<=30;i++)
				{
						printf("%4d",i);
						j++;
						if(j==7)
						{	
								j=0;
								printf("\n");
						}
				}	
		}
		printf("\n");
}


