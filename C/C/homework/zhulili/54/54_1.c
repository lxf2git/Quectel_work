#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp1;
	FILE *fp2;
	char ch;
	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"w+");
	if(argc<2)
	{
		printf("file_name argument");
		exit(-1);
	}
	if(fp1 == NULL)
	{
		printf("fopen 1 error");
		exit(-1);
	}
	if(fp2 == NULL)
	{
		printf("fopen 2 error");
		exit(-1);
	}
	while((ch = fgetc(fp1)) != EOF)
	fputc(ch,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;

}
