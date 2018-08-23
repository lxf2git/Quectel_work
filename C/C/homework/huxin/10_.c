#include<stdio.h>
void zhaoshu();

int main()
{
   zhaoshu();
   return 0;

}
void zhaoshu()
{
 	int i,j=0;
    for(i=1;i<1000;i++)
    {
       if(i%3==2&&i%5==3&&i%7==1)
	   {
			   printf("%d",i);
			   printf(" ");
               j++;
					if(j%6==0)
					printf("\n");
	   }   
    }
   printf("\n");	
}

