#include"circle.h"
int circle(pStackn stn,pStackx stx,int *a3,char *c2)
{
		int b;
		int a4=0,a2,c1;
		char c3,c,c10;
		a2=*a3;
		c1=*c2;
		while(popn(stn,&b)!=EMPTY)
		{
				*a3=b;
				int ret = popx(stx,&c);
				*c2=c;
				if(ret==EMPTY)
				*c2='a';
				switch(c1)
				{
						case '+':
								if(*c2!='*'&&*c2!='/')
								{	
							//	printf("a2:%d+a3:%d\n",a2,a3);
										a2=*a3+a2;
								}
								else
								{
										a4=a2;
										c3=c1;
										a2=*a3;
								}
								break;
						case '-':
								if(*c2!='*'&&*c2!='/')
								{
							//	printf("a2:%d-a3:%d\n",a2,a3);
										if(*c2=='-')
										{
												a2=*a3+a2;
										}
										else
												a2=*a3-a2;
													
								}
								else
								{
										a4=a2;
										c3=c1;
										a2=*a3;
								}
								break;
						case '*':
							//	printf("a2:%d*a3:%d\n",a2,a3);
								if(*c2=='*'||*c2=='/')
									a2=a2*(*a3);
								else if(*c2==')')
										break;
								else
								{
										if(c3=='+')
										a2=a2*(*a3)+a4;
										else if(*c2=='-')
										a2=a2*(*a3)+a4;
										else
										a2=a2*(*a3)-a4;
								}
								break;
						case '/':
								if(*c2=='*'||*c2=='/')
								a2=*a3/a2;
								else if(*c2==')')
										break;
								else
								{
										if(c3=='+')
										a2=*a3/a2+a4;
										else
										a2=*a3/a2-a4;
								}
								break;
						case ')':
								if(c10=='+')
									a2+=circle(stn,stx,a3,c2);
								else if(c10=='-')
										a2=circle(stn,stx,a3,c2)+a2;
								else if(c10=='*')
									a2*=circle(stn,stx,a3,c2);
								else if(c10=='/')
										a2=circle(stn,stx,a3,c2)/a2;
								else
									a2=circle(stn,stx,a3,c2);

								break;
						case '(':
								return a2;
								break;
						case 'a':
								break;
						default:
								printf("don't lie to me!\n");
								return 0;
						}	
						c10=c1;
						c1=*c2;	
								
						//		printf("%c",c);
			
		}
		return a2;
}
