int my(int x,int y)
{
	int n,i,j;
	j=run(x);
	n=0;
	if(y!=1)
	{
		for(i=1;i<y;i++)
		{
			n=n+31;
			if(i==4||i==6||i==9||i==11)
			{
				n=n-1;
			}
			if(i==2&&j==1)
			{
				n=n-2;
			}
			if(i==2&&j==0)
			{
				n=n-3;
			}
		}
	}
	if(y==1)
	{
		n=0;
	}
	return n;
}
