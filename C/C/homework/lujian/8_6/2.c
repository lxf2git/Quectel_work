#include<stdio.h> 
int count_str(char ch, int count_ch, int count_line);


int main()
{
	int count_ch, count_line;
	char ch;


	printf("please input \n"); 

	scanf("%c%d%d",&ch,&count_ch, &count_line);

	count_str(ch, count_ch, count_line);





	 return 0; 
}

int count_str(char ch, int count_ch, int count_line)
{
	int i, j;

	for (i = 0; i<count_line; i++)
	{
		for (j= 0; j<count_ch; j++)
				printf("%c",ch);
		putchar('\n');
	}
	
	return 0; 
}
