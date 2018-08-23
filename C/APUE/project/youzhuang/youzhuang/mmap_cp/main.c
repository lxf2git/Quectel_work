#include"main.h"

int main(int argc, char **argv)
{
		int i;
		int fd;
		char *p=NULL;
		if( argc < 3)
		{
				printf("file name\n");
				exit( -1 );
		}
		fd = open( argv[1], O_RDWR);
		if( fd < 0 )
		{
				perror( "open" );
				exit( -1 );
		}
		ftruncate( fd, 1024 );
		p = ( char * )mmap( 0, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
		if( p == MAP_FAILED )
		{
				perror( "mmap" );
				exit( -1 );
		}
		fd = open( argv[2], O_RDWR|O_CREAT, 0666 );
		if( fd < 0 )
		{
				perror( "open" );
				exit( -1 );
		}
		write( fd, p, strlen(p) );

		return 0;
}
