#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
		long l;
		char ptr[200]={'0'};
		FILE *fp;
		fp=fopen(argv[2],"w+");
		FILE *fp1;
		fp1=fopen(argv[1],"r+");

		if(NULL==fp)
		{
				printf("fopen error\n");
				exit(-1);
		}
		fseek(fp1,0,SEEK_END);
		l=ftell(fp1);
		//printf("%d",l);
		fseek(fp1,0,SEEK_SET);
		fread(ptr,l,1,fp1);
		printf("%s",ptr);
		fwrite(ptr,l,1,fp);
		fclose(fp);
		fclose(fp1);
		return 0;

}
