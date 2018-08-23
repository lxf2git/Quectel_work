#include<stdio.h>
void main()
{
  int x;
  x=1900;
  while(x<=2000)
  {
    if((x%4==0 && x%100!=0) || x%400==0)
  printf("%d\t",x);
	x=x+1;
	
  }

}
