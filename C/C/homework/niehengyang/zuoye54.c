#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(int argc,char *argv[])
{
	FILE *in,*out;
	char ch;
	if(argc!=3)
	{
		printf("you forget enter filename!\n");
		exit (0);
	}
	in=fopen("argv[1]","r");
	if(in==NULL)
	{
		printf("rfile cannot open! \n");
		exit(0);
	}
	out=fopen("argv[2]","w");
	if(out==NULL)
	{
		printf("outfile cannot open!\n");
		exit(0);
	}

	while(!feof(in))fputc(fgetc(in),out);
	fclose(in);
	fclose(out);


}
