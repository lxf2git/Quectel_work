#include"../apue.h"

int main()
{
	char ch[2];
	char arr[20]="kill ";
	char brr[20]="kill ";
	FILE *fp=fopen("record.txt","r");
	if(fp==NULL)
	{
		perror("fopen");	
		return 0;
	}
		ch[1]='\0';
	while((ch[0]=fgetc(fp))!=EOF)
	{
		strcat(arr,ch);
		if(ch[0]==' ')
		{
			system(arr);
			//printf(arr);
			strcpy(arr,brr);
		}
	}
	fclose(fp);
	
	return 0;
}
