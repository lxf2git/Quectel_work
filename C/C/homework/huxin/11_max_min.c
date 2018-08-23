#include<stdio.h>
float max(float x,float y,float z);
float min(float x,float y,float z);
float sub(float x,float y,float z);


int main()
{ 
	float a,b,c,x,y,z;
	printf("please input in :\n");
	scanf("%f %f %f",&a,&b,&c);
	x=max(a,b,c);
   	y=min(a,b,c);
    z=sub(a,b,c);
	
	printf("MAX:%f\n",x);
	printf("MIN:%f\n",y);
	printf("sub:%f\n",z);
    return 0;
}
float max(float x,float y,float z)
{  
		float o;
   if(x>y)
    o=x;
   else 
    o=y;
    if(o<z)
	o=z;
   return(o); 
}
float min(float x,float y,float z)
{  
		float p;
  if(x<y)
     p=x;
  else 
   	 p=y;
   if(p>z)
	 p=z;  
   return(p);
}
float sub(float x,float y,float z)
{
		float q,g,h;
		g=max(x,y,z);
		h=min(x,y,z);
		q=g-h;
		return(q);
}




