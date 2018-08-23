#include<stdio.h>
#include<stdlib.h>
#define N 100
int main()
{
		char zhongshu[N];
		int i;
		printf("please input (>0) 's shu:\n");
		for (i = 0; i < N; i++)
		{
				scanf("%c",&zhongshu[i]);
				if (zhongshu[0] == '0')
				{
						printf("input error\n");
						exit(-1);
				}	
				else if (zhongshu[i] == '\n')	
						break;
				else if (zhongshu[i] < '0' || zhongshu[i] > '9')
				{
						printf("input error\n");
						exit(-1);
				}
		}

		printf("%d\n",i);
		return 0;
}
