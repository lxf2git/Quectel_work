#include<stdio.h>
int main()
{
	int Sum,i,j,S,z,P;
	for(i=1;;i++)
	{
		Sum=i;
		for(j=0;j<=5;j++)
		{
			while(j==5)
			{
				printf("至少捕了%d条鱼\n",Sum);
				S=Sum;
				for(z=1;z<=5;z++)
					{
						if(z!=5)
						{P=(S-1)/5;
						printf("第%d个人拿了%d条鱼\n",z,P);
						S=(S-1)*4/5;}
						else 
						printf("给第%d个人留下了%d条鱼\n",z,S);
					}
				return 0;
			}
			if(Sum*5%4==0)
				Sum=Sum*5/4+1;
			else
				break;
		}
	}
			
}
