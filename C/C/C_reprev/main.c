


#include"/home/C.语言笔记/class_exercise/APUE/apue.h" 


int main() 
{

		struct msgbuf {
				long mtype;       /* message type, must be > 0 */
				char mtext[12];    /* message data */
		};
	

		struct msgbuf a;
		printf("%d\n", sizeof(a));
}


