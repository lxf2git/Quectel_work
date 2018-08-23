#include<stdio.h>
int main()
{
	int i;
	char j;
	for(i=0;i<3;i++)
	{
		sleep(1);
		j = i+'0';
		fwrite(&j,1,1,stdout);
	}	
	return 0;

}
