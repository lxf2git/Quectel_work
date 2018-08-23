#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void open_up(void**p,int sezi);
void input(int **p,int n,int m);
void looking(int **p,int n,int m,int falg);
void output(int **p,int n,int m);

int main()
{	
	srand(time(NULL));
	int n,m,i,j,min=0,**p=NULL;
	
	scanf("%d%d",&n,&m);
	
	open_up((void**)&p,n*sizeof(int*));

	for(i=0;i<n;i++){
		open_up((void**)p+i,m*sizeof(int));	
	
	}
	
	input(p,n,m);

	looking(p,n,m,0);
	looking(p,n,m,1);
	
	output(p,n,m); 
	
	return 0;		
} 

void open_up(void **p,int sezi)
{
	*p = malloc(sezi);		
		
	if(*p == NULL){
		printf("alloction failure");		
	}

}

void input(int **p,int n,int m)
{	
	int i,j;
	srand(time(NULL));

	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			*(*(p+i)+j) = rand()%100; 		
		}		
	}		
			
}

void looking(int **p,int n,int m,int falg)
{
	int i,j,k=0,f=0,temp;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(p[i][j]<p[k][f]){
				k = i;
				f = j;						
			}						
		}		
	}
	
	if(falg == 0){
		p[k][f] = -1;
		return;	
	}			
	temp =p[0][0];
	if(falg == 1){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
						
				if(p[i][j]<temp&&p[i][j]!=-1){
						temp = p[i][j];
				}			
			}		
				
		}		
		
	}
	
	printf("%d\n",temp);			
}

void output(int **p,int n,int m){
		
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%3d",*(*(p+i)+j));		
		}
			printf("\n");		
	}
	
}


