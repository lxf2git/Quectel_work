#include<stdio.h>
#include<stdlib.h>
// a.out src des
int main(int argc,char **argv)
{
		
	if(argc<2)
	{
		printf("file_name argument!\n");
		exit(-1);
	}	

	FILE *fp1,*fp2;
	char ch;

	 if((fp1 = fopen(argv[1],"r"))==NULL)
	 {
	 	printf("can not open %s\n",argv[1]);
		exit(-1);
	 }
	 if((fp2 = fopen(argv[2],"w+"))==NULL)
	 {
	 	printf("fopen fp2 error\n");
		exit(-1);
	 }

	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}

	fclose(fp1);
	fclose(fp2);



	
	return 0;

}
