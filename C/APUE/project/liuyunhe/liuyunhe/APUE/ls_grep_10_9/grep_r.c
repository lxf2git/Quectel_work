#include"apue.h"

int main()
{
		int fid;
		int i=0,j;
		char ch;
		char pir[50]={'\0'};
		char mmd[50]={'\0'};
		int ret;
		fid = open("pipe",O_RDONLY);
		if(fid<0)
		{
				perror("open");
				exit(-1);
		}
		printf("请输入要查找的字符串\n");
		scanf("%s",mmd);
		while(1)
		{
				ret = read(fid,&ch,1);
				if(ret<=0)
				{
						break;
				}
				
				if(ch!='\n')
				{
						pir[i] = ch;
			//	printf("%d %c \n",i,pir[i]);
						i++;

						if(50 == i)
						{
								printf("空间不足\n");
								close(fid);
								exit(-1);
						}
				}

				if(ch=='\n')/*比较*/
				{
			//	printf("pir:%s\n",pir);
						j=0;
						for(i=0;pir[i]!='\0';i++)
						{
							if(mmd[j]==pir[i])
							{
									for(j;j<50&&mmd[j]!='\0';j++)
									{
											if(mmd[j]!=pir[i+j])
											{
													i=i+j;
													break;
											}
									}
									if(mmd[j]=='\0')
									{
											printf("%s\n",pir);
											break;
									}
									break;
							}

						}
						memset(pir,0,50);
						i=0;
				}
		}
		close(fid);
		return 0;
}
