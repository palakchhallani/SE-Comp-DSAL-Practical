
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class assign1
{
	int xmin,xmax,ymin,ymax;
	float xmid,ymid,r,temp,a,b;
	int gd=DETECT,gm;

	public:
		void getdata();
		void patt();
		void drawpatt();
		void ddaline(int,int, int, int);
		void brcircle(int xc,int yc,float r);
};
void assign1::brcircle(int xc,int yc,float r){
	int x,y,d;
	x=0;
	y=r;
	d=3-2*r;
    do
	{
		putpixel(xc+x,yc+y,15);
		putpixel(xc-x,yc-y,15);
		putpixel(xc+x,yc-y,15);
		putpixel(xc-x,yc+y,15);
		putpixel(xc+y,yc-x,15);
		putpixel(xc-y,yc-x,15);
		putpixel(xc+y,yc+x,15);
		putpixel(xc-y,yc+x,15);
		if(d>0)
		{
			y==y;
			d=d+4*x+6;
		}
		else
		{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}
	while(x<=y);


}

void assign1 ::getdata(){


	cout<< "Enter xmin and ymin" << endl;
	cin>>xmin>>ymin ;
	cout << "Enter xmax and ymax"<<endl;
	cin >>xmax >>ymax;
}
void assign1::patt(){
    xmid=(xmax+xmin)/2;
    ymid=(ymax+ymin)/2;
	a = xmax - xmin ;
	b = ymax - ymin ;
	temp = sqrt(a*a + b*b);
	r = (a*b)/( 2 * temp) ;
}
void assign1::drawpatt()
{
	int gd=DETECT,gm;
	initgraph (&gd, &gm , NULL);
		ddaline(xmin,ymin,xmax,ymin);
		ddaline(xmax,ymin,xmax,ymax);
		ddaline(xmax,ymax, xmin,ymax);
		ddaline(xmin,ymax,xmin,ymin);
		ddaline(xmid,ymin,xmax,ymid);
		ddaline(xmax,ymid,xmid,ymax);
		ddaline(xmid,ymax,xmin,ymid);
		ddaline(xmin,ymid,xmid,ymin);

		circle(xmid,ymid,r);
		delay (8000);
		closegraph();
}
void assign1::ddaline(int x1,int y1, int x2, int y2)
{
	float dx,dy;
	float x,y,length,i;

	dx=(x2-x1);
	dy=(y2-y1);
	if(abs(dx)>= abs(dy))
		length=abs(dx);
	else
		length  = abs(dy);
	dx=dx/length;
	dy=dy/length;
	x=x1;
	y=y1;
	i=1;
	while (i<=length)
	{
		x=x+dx;
		y=y+dy;
		putpixel(x,y,15);
		i++;

}


}
int main()
{
	 assign1 obj;
	 obj.getdata();
	 obj.patt();
	 obj.drawpatt();
     	 return 0;
}



