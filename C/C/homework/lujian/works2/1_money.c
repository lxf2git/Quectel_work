#include<stdio.h>

int main()
{
	unsigned yun,of,tf,ff,sum=0;//of==1 fen,tf==2 fen ....;
	unsigned yuan=100;//100 fen;
	for(ff=0;ff<=20;ff++)
	{
		for(tf=0;ff*5+tf*2<=yuan;tf++)
		{
			of=(yuan-(ff*5+tf*2))/1;
			sum=ff+tf+of;
			printf("	ff:%u + tf:%u +of:%u =sum:%u	 	",ff,tf,of,sum);
			//if(tf%2==0)
			//	printf("\n");
		}
	}		


	return 0;
}


