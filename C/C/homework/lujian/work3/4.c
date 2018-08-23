#include<stdio.h>

int  fn(int  human);
int main()
{
		int human = 5;
		int re,temp;
		int j;
		for(j = 0; ;j++)
		{
				re = fn(human);	
				temp = re;
				if ((re-1)%5==0)
				{
						re = ((re-1)/5)*4; 

						if ((re-1)%5==0)
						{
								re = ((re-1)/5)*4; 
								if ((re-1)%5==0)
								{
										re = ((re-1)/5)*4; 
										if ((re-1)%5==0)
										{
												re = ((re-1)/5)*4; 
												if ((re-1)%5==0)
												{
														break;
												}
										}
								}
						}

				}
		}
		printf("%d\n",temp);
		return 0;
}
int  fn(int  human)
{	
		if (liv_human == 0)
		{

				static int i = 0;
				i++;
				return (4*i);
		}
		return   ((5*fn(liv_human-1))/4+1);
}	
