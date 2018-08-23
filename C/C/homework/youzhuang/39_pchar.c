#include<stdio.h>

#define N 100

void input(char a1[],char a2[]);
char *find(char *p1,char *p2);
int main()
{
		char string1[N],string2[N];
		char *p;
		input(string1,string2);
		p=find(string1,string2);
		printf("%s\n",p);
		return 0;
}

void input(char a1[],char a2[])
{
		printf("please input string a1:\n");
		gets(a1);
		printf("please input string a2:\n");
		gets(a2);
}

char *find(char *p1,char *p2)
{
		int count=0,maxcount=0;
		char *p11,*p22;
		char *pstart,*pend,*mpstart=p1,*mpend,*p2head=p2;
		while(*p1!='\0')
		{
				while(*p2!='\0')
				{
						if(*p1==*p2)
						{
								count=1;
								pstart=p1;
								pend=p1;
								p11=p1;
								p22=p2;
								while(*p11!='\0'&&*p22!='\0')
								{
										p11++;
										p22++;
										if(*p11==*p22)
										{
												pend=p11;
												count++;
										}
										else
										{
												break;
										}
								} 
						}
						if(maxcount<count)
						{
								maxcount=count;
								mpstart=pstart;
								mpend=pend;
						}
						p2++;
				}
				p2=p2head;
			
				p1++;
		}
		if(maxcount==0)
		{
				*mpstart='\0';
		}
		else
		{
				mpend++;
				*mpend='\0';
		}
		return mpstart;
}
