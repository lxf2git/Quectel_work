#include<stdio.h>
int output(int a);
void deal();
int main()
{
		deal();
		printf("\n");
	return 0;	

}
void deal()
{
		
		int a=0,i;
		for(i=1;i<1001;i++)	
				if(i%3==2&&i%5==3&&i%7==1)
				{
						output(a++);
						printf("%-3d ",i);
				}
				
}

int output(int a)
{
		if(6==a)
		printf("\n");
		return 0;	
}

