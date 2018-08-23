#include<stdio.h>
int main()
{
        int year,month,c,i,space;
	int zday=0,g,day;
        int n,m=0,j,count;
        printf("请输入年，月:\n");
	scanf("%d,%d",&year,&month);
	printf(" <  %d  >                                 <  %d  >\n",month,year);
	printf("sun     mon     tue     wed     thu     fir     sat\n");
		 if(year%100==0)
        {
                if(year%400==0)
                {
              //  printf("%d是润年\n",year);
                n=1;
                }
                else
                {
              //  printf("%d不是润年\n",year);
                n=0;
                }
        }
        else
        if(year%4==0)
        {
                                                             
//	printf("%d是润年\n",year);
        n=1;
        }

          else
        {
  //      printf("%d不是润年\n",year);
        n=0;
        }
	for(c=1900;c<=year;c++)
	{
		zday=zday+366;
	if(n==0)
		zday=zday-1;

	}
        for(g=1;g<=month-1;g++)
        {
                m=m+31;
        if(n==1&&g==2)
                m=m-2;
        if(n==0&&g==2)
                m=m-3;
        if(g==4||g==6||g==9||g==11)
                m=m-1;

        }
		
		count=(zday+m)%7;
		for(space=1;space<=count;space++)
		printf("	");
          for(g=1;g<=month;g++)
        {
		day=31;
        if(n==1&&g==2)
                day=day-2;
        if(n==0&&g==2)
                day=day-3;
        if(g==4||g==6||g==9||g==11)
                day=day-1;

        }
		
	 for(i=1;i<=day;i++)
        {
                  j=j+1;
		
			printf("%d	",i); 
		         if((i+space-1)%7==0)
                     printf("\n");     
  	   }                                       	
			printf("\n");
	
//        printf("你输入的%d年%d月是%d年的第%d天!\n",year,month,year,m);
  //      printf("从1900年到现在共%d天！\n",zday+m) ;                               
}
