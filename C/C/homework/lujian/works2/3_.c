#include<stdio.h>
#define N  100
int main()
{
		int eg ,space, digit,other,i,Ba;
		char array[N];
		char* re;
		eg=space=digit=other=i=Ba=0;
		printf("please input %%s:(<N)\n");
		re=gets(array);
		Ba=puts(re);
		if(Ba>=N)
		{
				printf("shuzu yuejie !dangours! input error\n ");
				return (-1);
		}
		else
				for(i=0;i<N-1;i++)
				{
						if((array[i]>=65&&array[i]<=90)||array[i]>=97&&array[i]<=122)
								eg+=1;
						else if(array[i]==32)
								space+=1;
						else if(array[i]>=30&&array[i]<=39)
								digit+=1;
						else 
								other+=1;
					
				}
		printf("the eg = %d\n",eg);
		printf("the space = %d\n",space);
		printf("the digit = %d\n",digit);
		printf("the other = %d\n",other);
		return 0;
}




