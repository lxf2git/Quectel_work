#include<stdio.h>
#include<string.h>
#define  N 100
int input(char str[]);
int sort_str(char str[]);
int delet_same(char str[]);

int main()
{
	char str1[N],str2[N];

	input(str1);
	input(str2);

	sort_str(str1);	
	sort_str(str2);	

	strcat(str1,str2);

	sort_str(str1);

	delet_same(str1);
	
	 puts(str1);
	

	return 0; 

}

int input(char str[])
{
		printf("please input string\n"); 
		gets(str);

		return 0; 
}
int sort_str(char str[])
{
		int i, j, k;
		char tmp;
		for (i=0; str[i]!='\0'; i++)
		{	
			k=i;
			
			for (j=i+1; j<strlen(str); j++)
			{
					if (str[k]>str[j])
							k=j;
			}
			tmp = str[k];
			str[k] =str[i];
			str[i] =tmp;		
		}
	//			puts(str);		

	return 0; 
}
int delet_same(char str[])
{
	int i, j, k = 0, flag=0;

	for(i = 0; i<strlen(str); i++)
	{		
				flag = 0;
	
			for (j =0; j<strlen(str); j++)
			{
					if (str[j]==str[i])
						flag++;
			}

					 if (flag==1)
					{	
						str[k++] = str[i];
					}
				 
	}

	str[k] = '\0';

	return 0; 
}
