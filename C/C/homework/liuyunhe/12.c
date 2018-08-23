#include<stdio.h>
int bao();
int main()
{
		biao();
		return 0;

}

int biao()
{
		int a=0,b,c;
		for(b=1;b<10;b++)
		{
				a=0;
				while(a<b)
                {
						a++;
						c=b*a;
						printf("%d*%d=%d,",a,b,c);
						
						
				}
				if(b==a)
					printf("\n");
		}


}
