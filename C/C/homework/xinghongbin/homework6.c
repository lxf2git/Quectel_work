#include<stdio.h>
main()
{
		int h,s,i,j;
		float min=0,m;
		printf("hour minute second\n");
		scanf("%d%f%d",&h,&m,&s);
		if(h>24||m>60||s>60)
		{
				printf("error\n");
				return 1;
		}		

				for(i=0;i<h;i++)
						min+=60;
				m+=min;
				min=0;
				for(j=0;j<s;j++)
						min=min+0.01667;
				m+=min;
				min=0;
				printf("%f\n",m);
				return 0;		

}
