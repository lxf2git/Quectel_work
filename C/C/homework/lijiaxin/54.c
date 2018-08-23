#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
		FILE *pf1,*pf2;
		char ch;
		char str[100];
		if(argc <2)
		{
				printf("no argument\n");
				exit(-1);
		}
		if((pf1 = fopen(argv[1],"r"))==NULL)//表示只读文件，且文件已存在
		{
				exit(-1);
		}
		if((pf2 = fopen(argv[2],"w+"))==NULL)//表示可以追加文件
		{
				exit(-1);
		}
	/*	while((ch=fgetc(pf1))!=EOF)  //
		{
				fputc(ch,pf2);
		}*/
		while(!feof(pf1))
		{
				fgets(str,99,pf1);
				fputs(str,pf2);

		}
		fclose(pf1);
		fclose(pf2);
}
		
