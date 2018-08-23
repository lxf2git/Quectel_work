 //#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>

int main(int argc,char **argv)
{
	char *pbuf=NULL;
	int len  = 0,ret=0;	
	FILE *fp = fopen(argv[1],"r+");	
	if(NULL==fp)
	{
		perror("sleep");//错误信息输出
	}

	while(1)
	{
		ret = getline(&pbuf,&len,fp);//mygetline...
		printf("len:%d\n",len);
		//len = 0;
		if(ret==-1)
		{
			break;
		}
		fwrite(pbuf,strlen(pbuf),1,stdout);//stdin stdout stderr
		//pbuf=NULL;
		printf("****************\n");
	}
	
	fclose(fp);
	return 0;

}
