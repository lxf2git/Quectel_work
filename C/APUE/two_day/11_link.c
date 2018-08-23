#include "../apue.h"

int main()
{
		int ret;

		ret=link("file", "file2");
		perror("link");

		return 0;
}
