 #include"15_fan.h"
 int choose(int a)
 {
         int z=1;
         int m=0;
         int sum=0;
         for(z=1;z<=a;z++)
         {
                 if(0==a%z)
                         {
			if(a!=z)
			{
                         if(1!=z)
                         {
                         m=m+1;
                         sum=sum+z;
                         printf("%d\n",z);
                         }
                        } 
			}
         }
         sum=sum+1+a;
         printf("M:%d\n",m);
         printf("SUM:%d\n",sum);
 
 }

