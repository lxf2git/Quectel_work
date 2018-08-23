#include"same_str.h"

char *same_str(char *p1,char *p2)
{
		int i,j,i1,j1,length1,length2;
		int k=0,count1=0,count2=0;
		length1=strlen(p1);
		length2=strlen(p2);
	// printf("p1:%p\n P2:%s\n",p1,p2);
		for(i=0;i<length1;i++)
		{
				for(j=0;j<length2;j++)
				{
	 			//		printf("count1=%d\n",count1);
						count1=0;		
	 			//		printf("*(p2+j)=%c\n",*(p2+j));
				//		printf("++++========+++++");
						if(*(p1+i)==*(p2+j))
						{

	 			//				printf("**************************\n");
								for(i1=i,j1=j;i1<length1||j1<length2;
												i1++,j1++)
								{
										if(*(p1+i1)==*(p2+j1))
												count1++;
										else
										{
												if(count1>count2)
												{
													count2 = count1;
													k = i;
													break;
												}
												break;
										}
								}
	 			//				printf("count2:%d\n K:%d\n",count2,k);
						}				
				}
		}
		*(p1+k+count2) = '\0';
	//	printf("%p\n %p\n",(p1+k+count2),(p1+k));
		return (p1+k);
}
