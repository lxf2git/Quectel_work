#include<stdio.h>
void six(int nu,int s);

int main()
{
	int i,nu=1,s=0;
	for(i=0;i<1000;i++)
	{
		if(nu%3==2&&nu%5==3&&nu%7==1)
	//		printf("%d ",nu);		
	{
			s++;
			six(nu,s);
			} 
		nu++;
	}

}

void six(int nu,int s)
{
//	int nu;
	if(s==6)
	{
		s=0;
		printf("%d\n",nu);
	}
	else
	printf("%d ",nu);
}
