

int tian(int x , int y , int z)
{
	int i,j,n,a;
	n=0;
	for(i=1900;i<x;i++)
	{	
		a=choose(i);
		n+=365;
		if(a==1)
			n++;
	}
	for(j=1;j<y;++j)
	{
		n=n+28;
		if(z==1&&j==2)
			n=n+1;
		else if(j==1||j==3||j==5||j==7||j==8||j==10)
			n=n+3;
		else if(j==4||j==6||j==9||j==11)
			n=n+2;
	}
	return n;
}
