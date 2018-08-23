#include"main.h"
//ls -lia file/dir
//:表示选项后有参数 optarg:存放选项参数
int main(int argc,char **argv)
{
		int l_ex=0,a_ex=0,i_ex=0;
		char there[]="./";
		deal_arg(&l_ex,&a_ex,&i_ex,argc,argv);
		if(NULL==argv[optind])//如果没有参数
		{
				dir_file(l_ex,a_ex,i_ex,there);
		}
		else
		{
				dir_file(l_ex,a_ex,i_ex,argv[optind]);
		}
		return 0;
}
