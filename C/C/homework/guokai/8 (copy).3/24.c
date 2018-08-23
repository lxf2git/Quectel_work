#include<stdio.h>
int main()
{
  char a[30]={'0'};
  int i,j;
   gets(a);
   for(i=0;i<30;i++)
   {
		   
 if(a[i]=='c')
 {	 
     for(j=i;j<30;j++)
	 {
	    a[j] = a[j+1];
	 }
     i--;
  }
   }
   puts(a);
return 0;
}
