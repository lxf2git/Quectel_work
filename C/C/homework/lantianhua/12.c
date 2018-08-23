#include<stdio.h>
 
 void ch();
int main()
{
  ch();
  return 0;
}
 void ch()
 { int i,j;
     for(i=1;i<=9;i++)
    {
      for(j=1;j<=i;j++)
      printf("%d*%d=%d ,",j,i,j*i);
      printf("\n");

    }

  }


 

  
 
