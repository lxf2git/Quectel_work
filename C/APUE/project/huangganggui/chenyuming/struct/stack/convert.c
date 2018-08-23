#include "pub.h"

size_t convert_two(pStack data_stack, int convert_num)
{
	int rem;
	int tmp;
	int index = 0;
	char num_str[100];

	while(convert_num!=0){
		rem = convert_num%2;
		Push(data_stack, rem);
		convert_num = convert_num/2;
	}
	
	while(data_stack->top!=NULL){
		num_str[index] = Pop(data_stack)+48;
		index++;
	}
	num_str[index+1] = '\0';
	return atoi(num_str);
}


size_t convert_eight(pStack data_stack, int convert_num)
{
	int rem;
	int tmp;
	int index = 0;
	char num_str[100];

	while(convert_num!=0){
		rem = convert_num%8;
		Push(data_stack, rem);
		convert_num = convert_num/8;
	}
	
	while(data_stack->top!=NULL){
		num_str[index] = Pop(data_stack)+48;
		index++;
	}
	num_str[index+1] = '\0';
	return atoi(num_str);
}


size_t convert_sixteen(pStack data_stack, int convert_num)
{
	int rem;
	int tmp;
	int index = 2;
	char num_str[100];
	num_str[0] = '0';
	num_str[1] = 'x';
	
	while(convert_num!=0){
		rem = convert_num%16;
		if (rem>9){
			rem = rem + 55;
			Push(data_stack, rem);
		}
		else{
			Push(data_stack, rem+48);
		}
		convert_num = convert_num/16;
	}
	
	while(data_stack->top!=NULL){
		num_str[index] = Pop(data_stack);
		index++;
	}
	num_str[index] = '\0';
	printf("%s\n", num_str);
	return ;
}
