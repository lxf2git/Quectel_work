#include<stdio.h>

int main()
{ 
   char ch;
   int a ,space,number,letter,other;
   space=0;
   number=0;
   letter=0;
   other=0;
   printf("please input string:\n");
   for(;a!=10;)
  { 
   scanf("%c",&ch);
   a=ch;
   
   if(a==32)
     space++;
 
   else  if(a>=48&&a<=57)
          number++;
         
         else if( (a>=65&&a<=90)||(a>=97&&a<=122))
              letter++;
     
            else other++;    
    }
      printf("space:%d\n",space);
      printf("number:%d\n",number);
      printf("letter:%d\n",letter);
      printf("other:%d\n",other);

     return 0;
}


