int choose(int x)
{
	int a;
	if((x%4==0)&&(x%100!=0)||(x%400==0))
		a=1;
	else
		a=0;
	return a;
}
