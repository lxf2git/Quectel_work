#include<stdio.h>
void number();
void putout(int c,int i);
int main()
{
   number();
  return 0;
} 
void number ()
{
  int  i,c;
  c=0; 
  for(i=0;i<=1000;i++)
  { 
   if((i%3==2)&&(i%5==3)&&(i%7==1))
     {    c=c+1;
      putout(c,i);
    }
  }
}
  void putout(int c,int i)
{    
   if(c==6)
  { printf("  %d  ",i);
   printf("\n");
}
   else 
   printf("  %d  ",i);

}
