#include<stdio.h>
int jisuan();
int s,i=0;
int main(int s)
{
		s=1;
		for(s=1;s<=1000&&s>=1;s++)
		{
				jisuan(s);
		}
		printf("\n");
		return 0;
}

int jisuan(int s)
{
		int a,b,c;
		
		a=s%3;
		b=s%5;
		c=s%7;
		
		if((a==2)&&(b==3)&&(c==1))
		{
				printf("%d,",s);
				i++;
		
		if(i==6)
		{
				printf("\n");
		        i=0;
		}
		}	
	
}


