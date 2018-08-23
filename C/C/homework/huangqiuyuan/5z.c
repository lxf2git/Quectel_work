#include<stdio.h>

int main()
{
	int q,w,e,n=0;
	 for (q=0;q<=100;q++)
		 for(w=0;w<=50;w++)
	 		 for(e=0;e<=20;e++)
	   			if( q+2*w+5*e==100)
	         			n++ ;   


	printf("将一元兑换成1分 2分 5分的方法有%d 种\n",n);
	return 0;

}
