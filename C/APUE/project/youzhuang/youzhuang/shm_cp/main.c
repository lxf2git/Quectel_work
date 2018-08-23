#include"main.h"

int main(int argc, char **argv)
{
		int fid,shmid;
		fid = open( argv[1], O_RDWR );
		if( fid < 0 )
		{
				perror("open");
		}
		int len = lseek( fid, 0, SEEK_END);
		lseek( fid, 0, SEEK_SET);
		shmid = shmget( 0x8888, len, IPC_CREAT );
		char *p=(char *)shmat(shmid, NULL, 0);
		read(fid, p,len);
		fid = open ( argv[2], O_RDWR|O_CREAT, 0666);
		write(fid, p, len);
		close(fid);
		return 0;
}
