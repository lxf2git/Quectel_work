#include "../apue.h"
int main()
{
		char *arr;
		char brr[256];
		int n=0;
		FILE *fp = fopen("record.txt","r");
		if(fp==NULL)
		{
				perror("fopen");
				return 0;
		}	
	
		getline(&arr,&n,fp);	
		sprintf(brr,"kill -9 %s",arr);
		system(brr);
		fclose(fp);
}
