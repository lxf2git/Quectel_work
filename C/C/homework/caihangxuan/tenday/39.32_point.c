#include<stdio.h> 
#include<string.h> 
char first_l[100],second_l[100];
int charnu=1,maxnu=0,adrr_u=0,adrr_d=0,nocon=0;
int turn_up,turn_down;
char judge(int up,int down)
{
	if(charnu>maxnu)
	{
	maxnu=charnu;
	turn_up=up;
	turn_down=down;
//	printf("maxnu:%d \nturn_up:%d \nturn_down:%d\n",maxnu,turn_up,turn_down);
	}
}

char cmp(char *p_fir,char *p_sec)
{
	int t_f,t_s,size_f,size_s,t_rf,t_rs;
	size_f=strlen(p_fir);
	size_s=strlen(p_sec);
	for(t_f=0;t_f<size_f;t_f++)
	{
		for(t_s=0;t_s<size_s;t_s++)
		{ //     printf("%c %c\n",*(p_fir+t_f),*(p_sec+t_s));
  				if(*(p_fir+t_f)==*(p_sec+t_s))
				{
					for(t_rf=t_f+1,t_rs=t_s+1;t_rf<size_f||t_rs<size_s;t_rf++,t_rs++)
					{  //        printf("%c %c\n",*(p_fir+t_rf),*(p_sec+t_rs));
						if(*(p_fir+t_rf)==*(p_sec+t_rs))
						{
							if(nocon++,nocon<2)
							adrr_u=t_rs-1;
							printf("up:%d ",adrr_u);    
						}
						else
						{
							adrr_d=t_rs-1;
							charnu=adrr_d-adrr_u+1;
							printf("down:%d ",adrr_d);
							printf("char:%d ",charnu);
							judge(adrr_u,adrr_d);
						        nocon=0;
							break;
						}
					}
				}
		}
	}	
}
int main()
{
	printf("BUG声明：连续相同数不可以小于两个，第一个相等字符失效。\n");
	char first_l[100],second_l[100];
	printf("请输入一个字符串。");
	scanf("%s",first_l);
	printf("请输入第二个字符串。");
	scanf("%s",second_l);
	cmp(first_l,second_l);
	printf("\n1\n");
	for(;turn_up<=turn_down;turn_up++)
		printf("%c",second_l[turn_up]);
	printf("\n");
}
