
int zts(int x)
{
	int j,a,b;
	j=0;
	for(a=1900;a<x;a++)
	{
		b=run(a);
		j=j+366;
		if(b==0)
		{
			j=j-1;
		}
	}
	return j;
}
