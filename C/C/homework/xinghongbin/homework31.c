#include<stdio.h>
void rank(int *a);
int main()
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		rank(a);
		return 0;
}
void rank(int *a)
{
		int i=1,j,h=10,m=0,mov=0,kill=0,yu=1;
		for(;kill!=9;)
		{
					
				for(;i<=h-kill;i++)
				{
						
						m++;
						if(i%3==0)
						{
								printf("%d\n",a[m-1-mov]);
							
								
								for(j=m-1-mov;j<h-kill;j++)
										a[j]=a[j+1];
								mov++;
						}
						

				}
				yu=(h-kill)%3+yu;
				kill+=mov;
				i=yu%3;
				m=mov=0;
		}
				
		
}
