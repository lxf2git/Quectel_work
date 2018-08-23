#include<stdio.h>
#include<string.h>

int main( )
{ 
char str[50]="xyz";

char p1[40]="abcd";//
char p2[]="ABCD";//
strcpy(str+2,strcat(p1+2,p2+1)); xycdBCD
printf("%s",str); //xycdBCD  +2    xyzcdBCD xyabBCD +1 xyabcdBCD  

}

