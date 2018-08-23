#include<stdio.h>
int main()
{
	int arr[12]={1,2,3,4,5,6,7,8,9,10};
        int i=0,j,k,q,n=0,m;
	do{	
		i+=1;
		if((i+1)%3==0){
			n+=1;
			for(q=i;q<10-n;q++){
				arr[q]=arr[q+1];
			}
			for(j=0;j<i;j++)
				for(k=0;k<10-n-1;k++){
					m=arr[k+1];
					arr[k+1]=arr[k];
					arr[k]=m;
				}
			i=0;
	}	
	}while(n<8);
		printf("%d\n",arr[1]);
	return 0;
}
