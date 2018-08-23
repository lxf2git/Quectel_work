#include<stdio.h>
int main()
{
	char i;
	int letter = 0,num = 0,empty = 0,all = 0,m = 0;
	
	for(;;)
	{	scanf("%c",&i);
			if(i == '\n')
			{
				break;		
			}
			all++;	
			if(97<=i&&i>=122||65<=i&&i>=90)
			{
				letter++;
			}

			else if(47<= i&&i <=58)
				 {
					num++;
				 }		 	
			else if(i == ' ')
				 {
					empty++;
				 }		

			else {
					m++;
				 }	
					
	}
	
	printf("letter:%d\nnum:%d\nempty:%d\nm:%d\n",letter,num,empty,m);
	
	return 0;


}					
				
