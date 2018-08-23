#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	FILE *a1=fopen(argv[1],"r");
	FILE *a2=fopen(argv[2],"w+");
	int b;
	for(;;)
	{

		b=fgetc(a1);
		if(b==-1)
				break;
		fputc(b,a2);
	}
	fclose(a1);
	fclose(a2);
}
