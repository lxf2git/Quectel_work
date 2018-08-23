
int run(int x)
{
	int y;
	if((x%4==0&&x%100!=0)||x%400==0)
	{
		y=1;
	}
		else
	{
		y=0;
	}
	return y;
}
