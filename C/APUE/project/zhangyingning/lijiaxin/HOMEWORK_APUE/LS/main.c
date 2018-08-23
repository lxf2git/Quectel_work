#include "apue.h"
//ls -lix file/dir
//:表示选项后有参数 optarg:存放选项参数
int main(int argc, char **argv)
{
	int ret;
	int i;
	char file_flage[4];
	int l_flage=0;
	int a_flage=0;
	int i_flage=0;

	memset(file_flage, 0, sizeof(file_flage));

	while(1)
	{
		ret=getopt(argc, argv, "lai");
		if(ret==-1)
		{
				break;
		}
		switch(ret)
		{
				case 'l':
				{
						//显示所有属性
						strcat(file_flage, "l");
						break;
				}
				case 'a':
				{
						//显示隐藏文件
						strcat(file_flage, "a");
						break;
				}
				case 'i':
				{
						strcat(file_flage, "i");
						break;
				}
				case '?':
				{
					printf("err.\n");
					break;
				}
				default:
				{
						printf("default.\n");
						break;
				}

		}
		for(i=0;i<4;i++)
		{
				if('l'==file_flage[i])
				{
						l_flage=1;
				}
				if('a'==file_flage[i])
				{
						a_flage=1;
				}
				if('i'==file_flage[i])
				{
						i_flage=1;
				}
		}
	}
	if(1==l_flage||1==a_flage||1==i_flage)
	{
			file_show(argv[optind],l_flage,a_flage,i_flage);
	}
	else
			file_show(argv[1],l_flage,a_flage,i_flage);
	if(1!=l_flage)
	{
			printf("\n");
	}
	return 0;

	
}

