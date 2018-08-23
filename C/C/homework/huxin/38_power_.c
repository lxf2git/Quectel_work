#include<stdio.h>
void solve(int pt,int pw);

int main()
{
	int pt,pw;
    printf("please input in positive :\n");
	scanf("%d",&pt);
	printf("please input in power :\n");
	scanf("%d",&pw);
    solve(pt,pw);
	return 0;
}
void solve(int pt,int pw)
{ 
	int n,m,i;
	n=pt;
	if(pw==0)
	{
		n=1;
		printf("%d\n",n);
	
	}
	else 
	{
			if(pw==1)
			{
				printf("%d\n",n);
			
			}
	        else
			{
				for(i=1;i<pw;i++)
                 {
					   	n=n*pt;
		         }
			     m=n%1000;
                 printf("%d\n",m);
			}


	}
}
