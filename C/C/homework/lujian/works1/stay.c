#include<stdio.h>
#include<time.h>

int main()
{
		char *p;
		long tm;
		//tm=time(NULL);
		int i, n=5;
		char *a[]={"欢","迎","来","到","召","唤","师","峡","谷"};
		for(i=0;i<9;i++)
		{
				printf("%s",a[i]);
				fflush(NULL);
				sleep (1);
		}
		printf("\n");
		printf("英雄还有5秒钟即将到达战场\n");
		while(n>0)
		{
				sleep(1);
				printf(" .%d\n",n--);
				//p=ctime(&tm);
				//printf("time :%s",p);
		}
		sleep(2);
		printf("defeat! caiB \n");
		return 0;
}
