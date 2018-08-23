#include"fork.h"
int main()
{
		char pid[30];
		int i;
		char kill[50]={"kill "};
		int fid = open("a.txt",O_RDONLY);
		int size=read(fid,pid,sizeof(pid));
		strncat(kill,pid,size);
		system(kill);
		return 0;
}
