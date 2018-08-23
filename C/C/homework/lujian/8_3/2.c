#include<stdio.h>
#define N 11
int sort_ch(char ascii[]);
int main()
{	
	char ascii[N] ="123456789";
	char ch;
	printf("%s\n",ascii);
	printf("please input char\n"); 

	scanf("%c",&ch);

	ascii[N -2] = ch;
	//printf("%c\n",ascii[9]); 
	//printf("%s\n",ascii);
				
	sort_ch(ascii);

	printf("%s\n",ascii);

	return 0;

}

int sort_ch(char ascii[])
{
	int i, j, k;
	char tmp;
	for (i = 0; i < N; i++ )
	{
		k = i;
			for (j = i + 1; j < N-1; j++)
			{
				if (ascii[k] > ascii[j])
						k = j;
			}
		
			tmp = ascii[k];
			ascii[k] = ascii[i];
			ascii[i] = tmp;
	}
	
	printf("%s\n",ascii);
	return 0;
}
