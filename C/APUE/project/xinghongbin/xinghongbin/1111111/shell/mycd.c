#include <unistd.h>
#include <stdio.h>
int main(int argc,char**argv)
{
		if(argc ==1)	
				chdir("/root");
		if(argc == 2)
				chdir(argv[1]);
		return 0;
}
