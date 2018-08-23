#include<stdio.h>
int main(int argc,char *argv[])
{
	FILE*fp;
	fp=fopen(argv[1],"r+");
	FILE*fp1=fopen(argv[2],"w+");
	char p;
	while((p=fgetc(fp))!=EOF)
	{
			fputc(p,fp1);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
