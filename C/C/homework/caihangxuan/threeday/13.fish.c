#include<stdio.h>
#include<stdlib.h>
int fishnumber(int nu,int number);

int main()
{
	int nu=5;
	for(;;nu++)
		fishnumber(nu,nu);
}

int fishnumber(int nu,int number)
{	
	if(nu%5==1)
	{
		nu=nu-nu/5-1;
		if(nu%5==1)
		{
			nu=nu-nu/5-1;
			if(nu%5==1)
			{
				nu=nu-nu/5-1;
				if(nu%5==1)
				{
					nu=nu-nu/5-1;
					if(nu%5==1)
					{
						printf("%d\n",number);
						exit(0);
					}
				}
			}
		}
	}
}
