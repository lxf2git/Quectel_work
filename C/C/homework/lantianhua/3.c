#include <stdio.h>

 int main()
 {
   int data1,a, ch,data2;
   char op;
  printf("please input data1 data2:\n");
  scanf("%d%d",&data1,&data2);
  printf("please input op:\n");
  scanf("%c",&op);
   ch=getchar();
   switch(ch)
  {
   case 43: a=data1+data2;break;
   case 45: a=data1-data2;break;
   case 42:  a=data1*data2;break;
   case 47:  a=data1/data2;break;
   }   
   printf("%d\n",a);
   return 0;
  }
