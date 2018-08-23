#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

void copy(char *fp1,char *fp2);

int main(int argc,char *argv[])
{
	copy(argv[1],argv[2]);
	return 0;
}

void copy(char *p1,char *p2)
{
	FILE *fp1=NULL;
	fp1 = fopen(p1,"r");
	FILE *fp2 =NULL;
	fp2= fopen(p2,"w+");
	if(fp1 == NULL||fp2 == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	char *pstr;
	fseek(fp1,0,SEEK_END);
	long n;
	n = ftell(fp1);
	pstr = (char *)malloc(n*sizeof(char));
	if(NULL == pstr)
	{
		printf("malloc error\n");
		exit(-1);
	}
	fseek(fp1,0,SEEK_SET);
	fread(pstr,1,n,fp1);
	fwrite(pstr,1,n,fp2);
	if(pstr!=NULL)
	{
		free(pstr);
		pstr=NULL;
	}
	fclose(fp1);
	fclose(fp2);
}
