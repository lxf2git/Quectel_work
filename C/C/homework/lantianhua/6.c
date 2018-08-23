#include<stdio.h>

int main()
{
   int i,j,k,l;
   int hour ,minute, second;
  
    printf("plesae input hour:\n");
    scanf("%d",&hour);
    i=hour*60;
    printf("please input minute:\n");
    scanf("%d",&minute);
    j=minute;
    printf("please input second:\n");
    scanf("%d",&second);
    k=second/60;
    l=i+j+k;
    printf("%d\n",l);
  
    return 0;
}
