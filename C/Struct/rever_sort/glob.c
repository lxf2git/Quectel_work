#include<stdio.h>
#include<glob.h>
#include<string.h>

int main(int argc,char *argv[])//  /home
{
	char pattern[256];
	glob_t globres;
	int i;
	sprintf(pattern,"%s/*.c",argv[1]);//   /home/*	

	glob(pattern,0,0,&globres);

	for(i=0;i<globres.gl_pathc;i++)//   0  1  2
	{
		write(1,globres.gl_pathv[i],strlen(globres.gl_pathv[i]));
		write(1,"\n",1);
	}


	return 0;

}
