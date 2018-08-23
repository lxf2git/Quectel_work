

#include <stdio.h>

void fun();

int main() 
{

	printf("[%s = %d line] wo is main  \n", __FUNCTION__, __LINE__ ); 
	fun();
}
