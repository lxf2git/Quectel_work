#include"main.h"

int main(int argc,char **argv)
{
	char *pbuf=NULL;
	int i=0,max=240;
	FILE *fp=fopen(argv[1],"r++");
	if(NULL==fp)
	{
	perror("wrong");
	}
	int c;
	while(EOF!=(c=fgetc(fp)))
	{
		printf("%c",c);
		i++;
		if(c=='\n')
		{
			printf("%d\n",i);
				if(i>240)
				{
				max=max>i?max:i;
				}
				if(i<120&&max==0)
				{
				printf("120\n");
				}
				if(i<=240&&i>=120&&max==0)
				{
				printf("240\n");
				}
				if(max!=240)
				{
				printf("%d\n",max);
				}
			i=0;
			continue;	
		}
	}
	fclose(fp);
	return 0;
}
