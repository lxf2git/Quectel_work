#include<stdio.h>

 void aaaw(int a, int b ,int c);
int main()
{ 
 int a,b,c;
  printf("please input three number a,b,c:\n");
  scanf("%d%d%d",&a,&b,&c);
  aaaw(a,b,c);
  return 0;
}
 void aaaw(int a, int b ,int c)
{  
   int max,min; 
  if(a>=b)
  {  
    if(c<b)
   {
    max=a;
    min=c;
   }
    if(c=b)
   {max=a;
   min=b;
   }
    if(c>b)
    { min=b;
     if(a>c)
      max=c;
      else max=a;
   }
  }  
   else  if(a<b)
          {if(c<a)
          { max=b;
           min=a;
          }
         if(c=a)
           { max=b;
             min=a;
           }
         if(c>a)
         {   min=a;
            if(c>b)
              max=c;
            else max=b;
      }
    }
      
  
 
   printf("max:%d\n",max);
   printf("min:%d\n",min);   
   printf("%d\n",max-min);
}




