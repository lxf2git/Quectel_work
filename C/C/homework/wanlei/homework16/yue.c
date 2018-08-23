int yue(int y,int z)
{
	int a;
	if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
		a=31;
	else if(y==2&&z==1)
		a=29;
	else if(y==2&&z==0)
		a=28;
	else 
		a=30;
	return a;
}
