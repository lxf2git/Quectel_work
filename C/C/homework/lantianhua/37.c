#include<stdio.h>
#define N 50
# if 0
char *mystrcpy(char *dest,char *src)
{	char *p=dest;	
	int i;
	for(i=0;i<N;i++)
	{
		*dest=*src;
		
		if(*src==0)
	  {	return p;
                 break;
          }

		dest++;
		src++;
      
	}

}
#endif
#if 0
char *mystract(char *dest,char *src)
 {
	char *q=dest;
	int i,j;
	for(i=0;i<N;i++)
	{
		dest++;
		if(*dest==0)
		break;
	}
	for(j=0;j<N;j++)
	{
		*dest=*src;
		if(*src==0)
		{
			return q;
			break;
	}
			dest++;
			src++;
	}
 }
#endif

int mystrcmp(char *dest,char *src)
{
	int i;int a;
	for(i=0;i<N;i++)
	{
		if(*dest>*src)
			a=1;
		else if(*dest<*src)
			a=-1;
			else if(*dest==*src)
                         {	dest++;
				src++;		
				if(*dest==0)
				{	a=0;
					break;
				}
			}
	}
	return a;


}
int main()
{	
	char str1[N]={};
	char str2[N]={};
	char *point;
	char *point_1;
	int b;
	printf("please input str1,str2\n");
	gets(str1);
	gets(str2);
	//	point=mystrcpy(str1,str2);
//	printf("%s\n",point);
	//	point_1=mystract(str1,str2);
	//	printf("%s\n",point_1);
		b=mystrcmp(str1,str2);
		printf("%d",b);	
	return 0;
}
