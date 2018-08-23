#include<stdio.h>
#include<string.h>

int main()
{
	char arr[100]={0};
	int median=0,letter=0,sentence=0,word=0,i; 

	for(i=0;;i++){
		arr[i]=getchar();	
		if(arr[i] == '#'){
			break;	
		}
	}
	
	for(i=0;i<strlen(arr);i++){

		if((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z')){
			letter++;		
			median = 1;	
		}		
		if(arr[i] == 32&&median == 1||median == 1&& arr[i] == '.'){		
			word++;
			median = 0;
		}
		if(arr[i] == '.'){
			sentence++;		
		}
		
	}	

	printf("letter:%d word:%d sentence:%d\n",letter,word,sentence);
	
	return 0;
			
}
