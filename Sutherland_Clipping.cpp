//============================================================================
// Name        : assign.cpp
// Author      : Palak Chhallani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <graphics.h>
using namespace std;
int gd=DETECT,gm;
typedef struct coordinate{
	int x;
	int y;
	char code[4];
} PT;

void drawwindow(){
	setcolor(RED);
	rectangle(150,100,450,350);
}
void drawline(PT x1,PT x2){
	setcolor(WHITE);
	line(x1.x,x1.y,x2.x,x2.y);
}
PT setcode(PT p)
{
	PT ptemp;
if(p.y<100)
	ptemp.code[0]='1';/*TOP*/
else
	ptemp.code[0]='0';
if(p.y>350)
	ptemp.code[1]='1';/*BOTTOM*/
else
	ptemp.code[1]='0';
if(p.x>450)
	ptemp.code[2]='1';/*RIGHT*/
else
	ptemp.code[2]='0';
if(p.x<150)
	ptemp.code[3]='1';/*LEFT*/
else
	ptemp.code[3]='0';
ptemp.x=p.x;
ptemp.y=p.y;
return (ptemp)	;
}
int visibility (PT p1,PT p2){
	int i,flag=0;/*line completely visible*/

	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0')||(p2.code[i]!='0'))
			flag=2;/*line partially visible*/
	}
	for(i=0;i<4;i++)
		{
			if((p1.code[i]==p2.code[i]) &&(p1.code[i]=='1'))
			flag=1;/*line completely invisible*/

		}
	if(flag==0)
			return(0);
	if(flag==1)
			return(1);
	if(flag==2)
			return(2);

}
PT resetendpt(PT p1,PT p2)
{
 PT temp ;
 int x,y;
 float m,k;
 if (p1.code[3]=='1')//cutting left edge
	 x=150;
 if (p1.code[2]=='1')//cutting right edge
	 x=450;
 if ((p1.code[3]=='1')||(p1.code[2]=='1'))
 {
	 m=(float)(p2.y-p1.y)/(p2.x-p1.x);
	 k=(p1.y+(m*(x-p1.x)));
	 temp.y=k;
	 temp.x=x;
	 if(temp.y<=350&&temp.y>=100)
		 return(temp);
 }
 if(p1.code[0]=='1')//cutting top edge
	 y=100;
 if(p1.code[1]=='1')//cutting bottom edge
   	y=350;
  if((p1.code[0]=='1')||(p1.code[1]=='1'))
   	 {
   		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
   			 k=(float)p1.x+(float)(y-p1.y)/m;
   			 temp.y=y;
   			 temp.x=k;
   			 if(temp.x<=450&&temp.x>=150)
   				 return(temp);
   	 }
   	 else
   	 return(p1);
}
void check_line(PT p1,PT p2){
	int v;
	p1=setcode(p1);
	//cout<<p1.code<<endl;
	p2=setcode(p2);
	//cout<<p2.code<<endl;
	v= visibility(p1,p2);
	switch(v)
	{
	case 0:
		cleardevice();
		cout<<"Visible";
		drawwindow();
		drawline(p1,p2);
	break;
	case 1:
		cleardevice();
		cout<<"Competely invisible";
		drawwindow();
    break;
	case 2:
		cleardevice();
		drawwindow();
		cout<<"Partially visible";
		p1=resetendpt(p1,p2);
		cout<<p1.x<<p1.y<<endl;
		p2=resetendpt(p2,p1);
		check_line(p1,p2);

	break;

	}
	delay(2000);
}



int main() {
	int gd=DETECT,gm;
    initgraph(&gd,&gm,"");


	PT p1,p2;
	p1.x=200;
	p1.y=200;
	p2.x=400;
	p2.y=500;

	drawwindow();
	drawline(p1,p2);
	check_line(p1,p2);
	//resetendpt(p1,p2);
	delay(8000);
	return 0;
}


