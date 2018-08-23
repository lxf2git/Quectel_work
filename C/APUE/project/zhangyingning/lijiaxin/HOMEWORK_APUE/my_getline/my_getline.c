#include"getline.h"
void pbuf_free(void **pbuf)
{
		free(*pbuf);
		pbuf = NULL;
}
void creat_memory(char **pbuf,int p_len)
{
		if(p_len==118)
		{
				*pbuf =(char *)realloc(*pbuf,240);
				before_len = 240;
		}
	else
		if(p_len==238)
		{
				*pbuf =(char *)realloc(*pbuf,480);
				before_len = 480;
		}
	else
		{
				*pbuf =(char *)realloc(*pbuf,p_len+1);
				before_len = p_len+2;
		}

}
int my_getline(char **pbuf,int *p_len,FILE *fp)
{
		int len=0;
		char ch;
		if((ch=fgetc(fp))==EOF)
		{
			return -1;
		}
		if(*pbuf==NULL)
		{
			*pbuf = (char *)malloc(120);
			before_len = 120;
			while((ch=fgetc(fp))!='\n')
			{
					(*pbuf)[len]=ch;
						len++;
					if(len==118)
					{
							creat_memory(pbuf,len);
					}
					if(len==238)
					{
							creat_memory(pbuf,len);
					}
					if(len>=478)
					{
							creat_memory(pbuf,len+1);
					}
					*p_len = before_len;
			}	
		}
		else
		{
			memset(*pbuf,0,sizeof(*pbuf));
			while((ch=fgetc(fp))!='\n')
			{
					(*pbuf)[len]=ch;
					len++;
					if(len==(*p_len-2))
					{
							if(*p_len<120)
							{
								*pbuf = (char*)realloc(*pbuf,120);;
								before_len = 120;
							}
							else
								if(*p_len<240)
								{
									creat_memory(pbuf,118);
								}
					
							else
								if(*p_len<480)
								{
									creat_memory(pbuf,238);
								}
								else
								{
										creat_memory(pbuf,len+1);
								}
					*p_len = before_len;
					}
			}				
		}
		(*pbuf)[len]='\n';
		(*pbuf)[len+1]='\0';
		return 0;
}
