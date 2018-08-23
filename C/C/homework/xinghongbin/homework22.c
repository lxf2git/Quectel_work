#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *input_string();
char *insert_char(char *p);
void deal_rank(char *p);
//void output_string(char *a);
int main()
{
//		output_string(input_string());
		
		deal_rank(insert_char(input_string()));
		return 0;
}

char *input_string()
{
		char *p=(char*)malloc(200);
//		char a[100];
//		p=a;
		scanf("%s",p);
//		printf("%s\n",p);
		return p;
}
#if 0
void output_string(char *a)
{
	printf("%s",a);
}
#endif
char *insert_char(char *p)
{
		char *insert=(char*)malloc(100);
//		char s;
		printf("input insert\n");
		getchar();
		scanf("%c",insert);
		strcat(p,insert);
//		printf("%s",strcat(p,insert));
		return p;
}


void deal_rank(char *p)
{
		int i,j;
		char m;
		for(j=0;j<strlen(p);j++)
		for(i=j;i<strlen(p);i++)
		{
				if(*(p+j)>*(p+i))
				{
						m=*(p+j);
						*(p+j)=*(p+i);
						*(p+i)=m;

				}

						
		}
		printf("%s",p);

}

