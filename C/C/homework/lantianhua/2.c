#include <stdio.h>

  int main()
  { 
    int a;
    printf("please input number:\n");
    scanf("%d",&a);
    
switch(a)
  {
    case 1:printf("Monday\n");break;
    case 2:printf("Tuseday\n");break;
    case 3:printf("Wendesday\n");break;
    case 4:printf("Thursday\n");break;
    case 5:printf("Friday\n");break;
    case 6:printf("Saturday\n");break;
    case 7:printf("Sunday\n");break;
     default :printf("error\n");break;
   }
     return 0;
}




