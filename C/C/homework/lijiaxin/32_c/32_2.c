#include"32_.h"

void same_string_(char src1[],char src2[])
{
	int length1,length2;
	int i,j,k=0,i1,j1,count1=0,count2=0;
	length1 = strlen(src1);
	length2 = strlen(src2);
    for(i=0;i<length1;i++)
	{
			for(j=0;j<length2;j++)
			{
					count1 = 0;
					if(src1[i]==src2[j])
					{
							
							for(i1=i,j1=j;i1<length1||j1<length2;i1++,j1++)
							{
									if(src1[i1]==src2[j1])
									{
											count1++;

									}	
									else
									{

											if(count1>count2)
											{
													count2=count1;
													k = i;
									      		   	break;
											}
											break;
									}
							}
					}				
			}
	}

	for(i=k;i<(k+count2);i++)
			printf("%c",src1[i]);			
}
