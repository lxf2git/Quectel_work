#include<stdio.h>	

int main()
{
	FILE *fp;
	fp = fopen("save.txt","w+");
	int n,m=0;
/*	fseek(fp,-4,SEEK_END);
	fread(&n,4,1,fp);
	printf("n:%d\n",n);
*/
	fwrite(&m,4,1,fp);
	fseek(fp,0,SEEK_SET);
	fread(&n,4,1,fp);
	printf("%d\n",n);

}
