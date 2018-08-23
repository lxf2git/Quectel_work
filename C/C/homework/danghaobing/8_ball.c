#include<stdio.h>
int main()
{
		float s=100,i=0,w=100;
		do
		{
			s=s/2;
			w+=s*2;
			i++;	
		}while(i<10);
		printf("反弹后高度:%f\n反弹路程:%f\n",s,w);
}
