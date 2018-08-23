#include"../apue.h"

int main()
{
	time_t t;
	struct tm* tm;
	time(&t);
	//1 tm = gmtime(&t);
	
	/*2 time(&t);
	tm = localtime(&t);	
	 printf("%s\n",asctime(tm));
	*/
	printf("%s",ctime(&t));


	return 0;

}
