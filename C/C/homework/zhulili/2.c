#include<stdio.h>
int main()
{
	int year,month,day,z;
	scanf("%d,%d,%d",&year,&month,&day);
	if(day<=31 && month<=12  )
	{
		if(year%4==0 && year%100!=0 || year%400==0)
		{		
		
	
			switch(month)
			{	
				case 1:printf("%d\n",day);       break;
				case 2:printf("%d\n",31+day);    break;
				case 3:printf("%d\n",2*31-2+day);break;
				case 4:printf("%d\n",3*31-2+day);break;
				case 5:printf("%d\n",4*31-3+day);break;
				case 6:printf("%d\n",5*31-3+day);break;
				case 7:printf("%d\n",6*31-4+day);break;
				case 8:printf("%d\n",7*31-4+day);break;
				case 9:printf("%d\n",8*31-4+day);break;
				case 10:printf("%d\n",9*31-4+day);break;
				case 11:printf("%d\n",10*31-5+day);break;
				case 12:printf("%d\n",11*31-6+day);break;
			}
		
			printf("该年是润年\n");
		}
	else 
	{
				switch(month)
				{
				case 1:printf("%d\n",day);break;
				case 2:printf("%d\n",31+day);break;
				case 3:printf("%d\n",2*31-3+day);break;
				case 4:printf("%d\n",3*31-3+day);break;
				case 5:printf("%d\n",4*31-4+day);break;
				case 6:printf("%d\n",5*31-4+day);break;
				case 7:printf("%d\n",6*31-5+day);break;
				case 8:printf("%d\n",7*31-5+day);break;
				case 9:printf("%d\n",8*31-5+day);break;
				case 10:printf("%d\n",9*31-5+day);break;
				case 11:printf("%d\n",10*31-6+day);break;
				case 12:printf("%d\n",11*31-7+day);break;
				}
			printf("该年不是润年\n");
	}
	}
	else
			printf("error");
	return 0;
}
