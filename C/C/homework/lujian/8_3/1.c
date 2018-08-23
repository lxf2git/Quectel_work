#include<stdio.h>
int count_digit(int num);
void translate_chars(int array[]);
int digit; 
int main()
{
	int num, i;
	
	printf("please input num:\n");

	scanf("%d",&num); 
	if (num < 0)
	{
		putchar('-'); // 负数时输出‘-’
		num = 0 - num;
	}
	digit = count_digit(num); 
	//printf("[%s = %d line]digit = %d\n", __FUNCTION__, __LINE__ ,digit);
/*************求整型数个位，十位，百位....的数字并存在数组中****/

	int  array[digit] ;
		array[0] = num%10;
	//	printf("[%s = %d line]  %d\n", __FUNCTION__, __LINE__,array[0] );
	for (i = 1; i < digit; i++)
	{
		num /= 10;
		array[i] = num%10;
	//	printf("[%s = %d line] array[%d] = %d\n", __FUNCTION__, __LINE__ ,i, array[i]);

	}

	translate_chars(array);
	
	return 0;

}
/*********转换成字符串********/

void translate_chars(int array[])
{
	char str1[digit+1];
	char str2[digit+1];
	int i;
	
	for (i =0; i< digit; i++)
	{
		str1[i] = array[i]+48;
	}
	//str1[digit] = '\0';
	for (i =0 ; str1[i] !='\0'; i++ )
	{
		str2[i] = str1[digit -1- i];
	}
	//str2[digit] = '\0';
	printf("%s\n",str2);


}
/********求整型数的的位数********/

int count_digit(int num)
{
	int i, temp = -1, shi = 1;
	 
	for (i = 1;num !=temp; i++)
	{
		shi *=10;
		temp = num%shi;

	}
	//	printf("[%s = %d line]  %d\n", __FUNCTION__, __LINE__,i-1 );

	return (i - 1) ;

}
