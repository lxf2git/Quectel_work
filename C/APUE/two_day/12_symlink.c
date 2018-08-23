#include "../apue.h"

int main()
{
		int ret;

		ret=symlink("/home/APUE/two_day/file", "/root/file2");// /root/file2->file
		perror("symlink");

		return 0;
}
