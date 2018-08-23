#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
		int i;
		if(argc==1)
		{
			printf("file_name argument");
			exit(-1);
		}
		for(i=0; i<argc; i++)
		{
			printf("%s\n",argv[i]);
		}

		FILE *fp1,*fp2;
		char *buf;
		long l;
		fp1 = fopen(argv[1],"r+");
		buf =(char *)malloc((100+1)*sizeof(char));
		fread(buf,1,100,fp1);
		l=ftell(fp1);
		rewind(fp1);
		fclose(fp1);
		fp2 = fopen(argv[2],"w+");
		fwrite(buf,1,l,fp2);
		free(buf);
		fclose(fp2);
		return 0;
}
