#include<stdio.h>
/*
 *枚举：enum 
 * */
/*
#define STOP 1
#define PAUSE 6
#define PLAY 7
*/
enum en_name
{
	STOP=9,
	PAUSE,
	PLAY
};
int main()
{	
	int choose;
	printf("please input button 1 stop 2 pause 3 play\n");
	scanf("%d",&choose);	

	switch(choose)
	{
		case STOP:
				printf("stop\n");
				break;
		case PAUSE:
				printf("pause\n");
				break;
		case PLAY:
				printf("play\n");
				break;
		default:
				printf("error \n");
				break;
	}
	return 0;

}
