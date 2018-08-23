#include"year.h"


void type()
{
	int t,h;
	t=1;
	h=0;
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	if(mback!=0)
	{
		while(mback!=0)
		{
			printf("     ");
			mback--;
			h++;
		}
	}
	for(;d>0;d--)
	{
		printf("%5d",t);
		t++;
		h++;
		if(h==7)
		{
			printf("\n");
			h=0;
		}

	}
	printf("\n");
}
