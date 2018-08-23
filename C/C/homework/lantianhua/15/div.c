#include"div.h"

void div()
{  
   int a,i,number=0,sum=0;
  do {
       printf("请输入100到500的整数：\n");
        scanf("%d",&a);
   
     }while((a<100)||(a>500));

    for(i=2;i<a;i++)
   {
       if(a%i==0)
     
      {  
         printf("约数是：%d\n",i);
         number=number+1;
         sum=sum+i;
      }
    }
       
      printf("约数的个数是：%d\n",number);
      printf("约数的和为：%d\n",sum);


}
