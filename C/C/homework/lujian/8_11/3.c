#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define  N  (100)
void creat(void** p, int size);
int input(char* p);
int judge_word(char* p);

int main() 
{
	char* str;

	creat((void**)&str, N*sizeof(*str));
	
	input(str);

	judge_word(str);

	free(str);

	 return 0; 
}

void creat(void** p, int size)
{
		*p = malloc(size);

		if (NULL == *p)
		{
			printf("please input malloc error \n"); 		
		}

}

int input(char* p)
{	
	printf("please input string \n");
   	gets(p);	
	 return 0; 
}

int judge_word(char* p)
{
	int i=0, j=0, count=0,max=1;
	char s[N];

	for (i=0; i<strlen(p); i++)
	{
			 
		
		if (*(p+i) !=' '&& *(p+i) !='.')
		{
				count++;
				s[j++] = *(p+i);
			//	printf("please input %d\n",count); 
		}
		else if (count>=max)
		{		
				max = count;
				j=0; 
				count =0;
					
		}
		else 	
		{
				j=0;
				count=0;
		}

	}
	j=0;
	count=0;
	printf("max =%d\n",max);  
	for (i=0; i<strlen(p); i++)
	{
		
		
		if (*(p+i) !=' '&& *(p+i) !='.')
		{
				count++;
				s[j++] = *(p+i);
			
		}
		else if (count==max)
		{		
				s[j] = '\0';
				j=0; 
				count =0;	
				puts(s);
		}
		else 
		{
			j=0;
			count=0;
			
		}
	}

	return 0; 
}	
		
	
	   
	




















