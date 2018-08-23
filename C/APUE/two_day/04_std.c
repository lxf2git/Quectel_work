#include "apue.h"

int main()
{
		char buf[1024];
		int n;
		int i;

		//scanf("%s", buf);
		//printf("%s\n", buf);

		n=read(0, buf, 5);
		for(i=0; i<3; i++)
		{
			//write(1, buf, n);
			printf("buf=%s", buf);
			sleep(1);
		}

		for(i=0; i<3; i++)
		{
			write(2, buf, n);
			sleep(1);
		}

		return 0;
}
