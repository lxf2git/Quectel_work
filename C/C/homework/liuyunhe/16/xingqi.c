#include"xingqi.h"


int xingqi(int sc,int yue,int f)
{		
	
		int kongge=0;
		int mm=1;
		int p;
		p=sc%7;
		int nn;
			
			while(kongge<(p+1))
			{
					
					printf("    ");
					kongge++;
			}
			nn=kongge;
			if(nn==7)
			{
					printf("\n");
					nn=0;
			}
			if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					while(mm<=31)
					{
							printf(" %d ",mm);
							mm++;
							nn++;
							if(mm<10)
							{
									printf(" ");
							}
							if(nn==7)
							{
								printf("\n");
								nn=0;
							}
					}

			if(yue==4||yue==6||yue==9||yue==11)
		        while(mm<=30)
                {
	               printf(" %d ",mm);
				   mm++;
	               nn++;
				   if(mm<10)
                    {
	                   printf(" ");
			        }
				   if(nn==7)
				      {
	                    printf("\n");
	                     nn=0;
	                  }
	             }


			if(yue==2)
			{
			
					int zz;
					zz=28+f;
					 while(mm<=zz)
					{       
							 printf(" %d ",mm);
							 mm++;
							 nn++;
	                         if(mm<10)
					         {       
					             printf(" ");
		                     }
		                  if(nn==7)                           
						     {
					              printf("\n");
	                              nn=0;		
					  		 }

			        }

			}
			printf("\n");
}			

