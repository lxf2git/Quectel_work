
#include"../../apue.h" 


int main(int argc, char** argv) 
{
	assert(argc == 3);

	int fds, fdd;
	int count = 0;
	char* pmap = NULL;

	if ((fds = open(argv[1], O_RDONLY)) < 0)
	{
		myperror("open");
	}

	if ((fdd = creat(argv[2], 0777)) < 0)
	{
		myperror("creat");
	}
	
	struct  stat sta;
	struct  stat* pstat = &sta;

	if (fstat(fds, pstat) < 0)
	{
			perror("fstat");
			goto ERR;
	}
	printf("size = %d\n", pstat->st_size);
	
	ftruncate(fds, pstat->st_size);

	if ((pmap = (char* )mmap(NULL, pstat->st_size, PROT_READ
						, MAP_SHARED,fds, 0)) == MAP_FAILED)
	{
			perror("mmap");
			goto ERR;
	}

#if 1
	while(count++ < (pstat->st_size))
	{
		#if 0
		if (*pmap == EOF)
		{
			break;
		}
		#endif 

		if ((write(fdd, pmap,1)) < 0)
		{
			myperror("write");
			goto ERR;
		}
		else
		{
			pmap++;
		}
	}
#endif 
	close(fds);
	close(fdd);
	munmap(pmap, pstat->st_size);
	return TURE; 

ERR:

	close(fds);
	close(fdd);
	munmap(pmap, pstat->st_size);
	return FALSE;  
}
