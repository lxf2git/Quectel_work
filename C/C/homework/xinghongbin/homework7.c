#include<stdio.h>
main()
{
		int q=0,b=0,c=0,i;
		char a;
		
			
		
		for(;a!='/';)
		{       
				scanf("%c",&a);
			
	
				if(64<a&&a<91||96<a&&a<123)
				
						q++;
						
				
					else if(48<a&&a<57)
				
							b++;
							
									
						else if(a==' ')
				
								c++;
								
				
		}
		printf("字母%d数字%d空格%d\n",q,b,c);
		
		
		
		return 0;
	//	printf("%c",);		
}
