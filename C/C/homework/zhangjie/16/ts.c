int ts(int x,int y)
{
	int i,j,n;
	i=run(x);
	if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
	{
		n=31;
	}
	else if(y==4||y==6||y==9||y==11)
	{
		n=30;
	}
	else if(i==1&&y==2)
	{
		n=29;
	}
	else if(i==0&&y==2)
	{
		n=28;
	}
	return n;
}
