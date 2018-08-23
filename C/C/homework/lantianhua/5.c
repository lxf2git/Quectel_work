#include<stdio.h>
int main()
{    int x,y,z,n;
     n=0;
    for(x=0;x<=100;x++)
      {  
       for (y=0;y<=50;y++)
          {
	    for (z=0;z<=20;z++)
             {
               if(100==x+2*y+z*5)
                 n=n+1;
             }
          }
       }
    printf("%d\n" ,n);
    return 0;
}
