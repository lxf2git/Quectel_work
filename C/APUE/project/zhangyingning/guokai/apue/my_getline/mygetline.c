#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
int mygetline(char **pbuf,int *len,FILE *fp)
{
	char ch;
	int i=0;		
	if((ch=fgetc(fp))==EOF)
	{
		return -1;
	}
	fseek(fp,-1,SEEK_CUR);
//	ch=fgetc(fp);
//	printf("%c\n",ch);	
	while((ch=fgetc(fp))!='\n')
	{			
		i++;		
	}
	fseek(fp,-i-1,SEEK_CUR);
	*len = i;
	*pbuf = (char *)malloc(120*sizeof(char)); 	
//	fseek(fp,-1,SEEK_CUR);
	fgets(*pbuf,i+1,fp);
	fseek(fp,1,SEEK_CUR);
}

int main()
{
	char *pbuf = NULL;
	int len = 0,ret = 0;
	FILE *fp = fopen("1","r+");
	if(NULL==fp)
	{
		perror("open");
	}
	fseek(fp,0,SEEK_SET);
	while(1)
	{
		ret = mygetline(&pbuf,&len,fp);
//		len = 0;
		if(ret==-1)
		{
			break;
		}
		printf("len:%d\n",len);
		fwrite(pbuf,strlen(pbuf),1,stdout);
		printf("\n");
		pbuf = NULL;
	}	
	fclose(fp);
return 0; 
}
