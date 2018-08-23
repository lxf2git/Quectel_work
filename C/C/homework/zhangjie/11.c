#include<stdio.h>
float max(float x,float y);
float min(float x,float y);
float cha(float x,float y);
int main()
{
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	printf("cha:%.2f\n",cha(max(max(a,b),c),min(min(a,b),c)));	
	return 0;
}

float max(float x,float y)
{
	return (x>y? x:y);
}

float min(float x,float y)
{
	return (x<y? x:y);
}

float cha(float x,float y)
{
	return (x-y);
}
