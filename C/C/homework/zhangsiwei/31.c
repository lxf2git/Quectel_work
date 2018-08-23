#include<stdio.h>

void game(int a[])
{
	int i,j,k,b;
	j=0;b=0;
	for(i=0;i<10;i++)
	{
		if(a[i]!=0)
		{
				if(j<3)
				{
						j++;
				}

				if(j==3)
				{
						for(k=i;;k++)
						{			
								if(a[k]!=0)
									{	a[k]=0;
										b++;
							//			printf("%d   ",k);
										break;
								  	}
								else 
									k++;
								if(k==9)
									k=-1;
					
						}
					j=0;
				}
		}
		if(i==9)
				i=-1;
		if(b==9)
		{
			break;
		}
	}
	for(i=0;i<10;i++)
	{
		if(a[i]!=0)
				printf("%d\n",a[i]);
	}
	
}
int main()
{
	int i;
	int a[10];
	for(i=0;i<10;i++)
	{
		a[i]=i+1;
	}
	game(a);
	return 0;
}
