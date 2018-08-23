#include"main.h"
int main()
{
		FILE *fp = fopen("mon","r");
		if(NULL==fp)
		{
				perror("fopen");
		}
		char *pbuf = NULL;
		int len=0,ret=0;
		while(1)
		{
			ret = mygetline(&pbuf,&len,fp);
			printf("ret:%d\n",ret);
			if(-1==ret)
					break;
			printf("len:%d\n",len);
		//	printf("%s",pbuf);
			fwrite(pbuf,strlen(pbuf),1,stdout);
		}
		fclose(fp);
		return 0;
}
