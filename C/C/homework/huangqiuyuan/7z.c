#include<stdio.h>
int main()
{

	int v=0,s=0,n=0,p=0;
	char w;
	for( ; ;)
{    
	 scanf("%c",&w);
	if ((w>=65&w<=90)||(w>=97&w<=122))
		v++;
	else if(w==32)
		s++;
	else if(w>=48&w<=57)
		n++;
	else if (w!=10)
		p++;
	else if (w==10)
{ printf("字母数：%d\n空格数：%d\n数字数：%d\n其他个数：%d\n",v,s,n,p);
         break;
}          
}
	return 0;

}

