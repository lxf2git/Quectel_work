#include<stdio.h>
int main()
{

	float l=100,t=0,w=100;
	do
        { 
		l=l/2;
		w+=l*2;
		t++;
}      while(t<10);
 	printf("10次反弹后高度：%f\n10次反弹后路程:%f\n",l,w);

return 0;

}
