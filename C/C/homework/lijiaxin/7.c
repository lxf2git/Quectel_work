#include<stdio.h>

int main()
{
	char ch;
	int zi=0;
	int kong=0;
	int shu=0;
	int other=0;
	printf("please enter yi chuan zi fu:");
	for( ; ; )
	{	
		scanf("%c",&ch);
		if((ch >= 'A' && ch <='Z')||(ch >= 'a' && ch <= 'z'))
	        	 zi++; 
		else if(ch >= 48 && ch <= 57)
			
			 	shu++;
		else if( ch == 32 ) 
			
				kong++;
	   	else
		 		other++;
	   if( ch =='\n')
		   break;
	}
	printf(" 字母:%d \n数字:%d\n 空格:%d\n 其它:%d\n",zi,shu,kong,other);	
	return 0;
}
