#include"deal.h"
void deal_arg(int *l_ex,int *a_ex,int *i_ex,int argc,char **argv)
{
		char ret;
		while(1)
		{
				ret=getopt(argc,argv,"lai");
				if(ret==-1)
						break;
				switch(ret)
				{
					case 'l':
					{
						*l_ex=1;
						break;
					}
					case 'a':
					{
						*a_ex=1;
						break;
					}
					case 'i':
					{
							*i_ex=1;
							break;
					}
					default:
					{
							printf("default.\n");
							break;
					}
				}
		}
}
