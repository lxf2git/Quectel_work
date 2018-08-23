#include<stdio.h>
int main()
{
	char i;
	int total;
	int zimu=0,num=0,space=0,other=0;
	for(;;)
	{
			scanf("%c",&i);
		if(i!='\n')
		{
			if(i>=65&&i<=90 || i>=97&&i<=122 )
				zimu=zimu+1;
		    if(i==32)
				space+=1;
			if(i>=48&&i<=57)	
				num+=1;
			if(i>=0&&i<32 ||i>32&&i<48 || i>57&&i<65 || i>90&&i<97 || i>122 )
				other+=1;
		}
		if(i=='\n')
		{
			break;
		}
	}
	total=zimu+space+num+other;
	printf("%d\n",zimu);
	printf("%d\n",space);
	printf("%d\n",num);
	printf("%d\n",other);
	printf("%d\n",total);
	return 0;
}
