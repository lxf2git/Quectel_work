#include<stdio.h>
int main()
{
		int f=9;
		int d=8;
		int c=7;
		int b=6;
		int a[5]={1,2,3,4,5};
		int i;
		
		for(i=0;i<6;i++)
		{
				printf("a[%d]%d         %p\n",i,a[i],&a[i]);
		
	    }
		
			//	printf("f:%p  d:%p c:%p b:%p \n",&f,&d,&c,&b);
	//	a[5]=100;
//		printf("a5:%d f:%p b:%p\n",a[5],&f,&b);
//		printf("%p\n",&a+1);
//				printf("f:%p  d:%p c:%p b:%p \n",&f,&d,&c,&b);

		return 0;
}
