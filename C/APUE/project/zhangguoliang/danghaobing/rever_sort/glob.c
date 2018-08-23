#include"glob.h"
int glob_deal(char argv[20],pFirst pfirst)//  /home
{
	char pattern[256];
	glob_t globres;
	int i,n=0;//n指第几个文件
	char *buf;
	char fbuf;
	FILE *fp;
	sprintf(pattern,"%s/*",argv);//   /home/*	
	glob(pattern,0,0,&globres);

	for(i=0;i<globres.gl_pathc;i++)//   0  1  2
	{
		//write(1,globres.gl_pathv[i],strlen(globres.gl_pathv[i]));
		//printf("%s\n",globres.gl_pathv[i]);
		//write(1,"\n",1);
		buf = globres.gl_pathv[i];//取到文件夹下每一个文件的文件名
	//	printf("%s\n",buf);
		fp = fopen(buf,"r");
		n++;//第n个文件
		int x=1;//代表循环中的第几个字符
		int s=1;//控制是否输出为首字母
		char chara[20];
		int j=0;//控制单词字母位置
		while((fbuf = fgetc(fp))!=EOF)//一个完整的循环结束，就意味着一个文件的遍历结束
		{
				//fread(fbuf,1,1,fp);
				//printf("%c",fbuf);//逐个读取文件的字符
				if(s==1&&((fbuf>='a'&&fbuf<='z')||(fbuf>='A'&&fbuf<='Z')))
				{
						//printf("第 %d 个文件，第 %d 个单词首字母为%c\n",n,x,fbuf);
						x++;
						s=0;
				}
				if(s==0&&((fbuf<'A'||(fbuf>'Z'&&fbuf<'a')||fbuf>'z')))
				{
					s=1;
					chara[j]='\0';
					//printf("第%d个文件，第%d个单词为：%s\n",n,x-1,chara);
					save_to_chain(pfirst,n,x-1,chara);
					j=0;
				}
				if(s==0&&((fbuf>='a'&&fbuf<='z')||(fbuf>='A'&&fbuf<='Z'))&&j!=20)
				{
					
					chara[j]=fbuf;
					j++;
					
				}
		}
		fclose(fp);

	}


	return 0;

}
