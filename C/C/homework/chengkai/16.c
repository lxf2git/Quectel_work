#include<stdio.h>

int a_month(int month);
int	day(int years,int month);
void output(int num,int month);

int main()
{	
	int yeare,month,month1,num;

	scanf("%d%d",&yeare,&month);
			
	num	= day(yeare,month);

	output(num,month);
		
	return 0;		
}

int a_month(int month)
{
	switch(month){
			
			case 1:
				 	return(31);
					break;	
			case 2:
					return(28);
					break;
			case 3:
					return(31);
					break;
			case 4:
					return(30);
					break;
					
			case 5:
					return(31);
					break;
			case 6:
					return(30);
					break;
			case 7:
					return(31);
					break;
			case 8:
					return(31);
					break;
			case 9:
					return(30);
					break;
			case 10:
					return(31);
					break;
			case 11:
					return(30);
					break;
			case 12:
					return(31);
					break;
			
	}		
						
			
}		
			
		
int	day(int yeare,int month)
{

	int i,j = 0,t = 0 ,m = yeare,p = 0,n=1,s;
	
	for(i=1900;i<yeare;i++){
			
		if((i%4 == 0&&i%100 != 0)||i%400 == 0){
				
				j+=366;					
		}else{
							
			j+=365;				
		}		
			
	}		
			
	for(i=1;i<=month;i++,n++){
			
		if((m%4 == 0&&m%100 != 0)||m%400 == 0){
			
			if(i == 2){
			t++;	
				continue;		
			}
			t+=a_month(i);
						
		}else{
	
			p+=a_month(i);			
		}		
	}	
		t+=29;	
				
	if(m%4 == 0&&m%100 != 0||m%400 == 0){
			i = t+j-30;
		while(i >= 7){
				
			i = i%7;		
		}
		return(i);
		printf("%d\n",i);				
	}else{
		i = p+j-30;
				
		while(i >= 7){
			i = i%7;
		}		
		printf("%d\n",i);	
		return(i);	
	}						
}		
		
void output(int num,int month)
{
	int i,j,k;
	int d;

	k = a_month(month);
	
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");

	for(j=0;j<num;j++){
		printf("    ");		
	}

	for(i=1;i<=k;i++){
		(i<10?printf("   %d",i):printf("  %d",i));	
//		printf("%d",i);
			num++;
		if(num%7 == 0&&num!=0){
			num=0;
			printf("\n");
		}	
			
	}
	printf("\n");		
			
}		
		











