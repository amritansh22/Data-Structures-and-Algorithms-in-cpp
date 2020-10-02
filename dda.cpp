/*Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel
class and Use function overloading.*/
#include<graphics.h>
#include<iostream>
using namespace std;
void DDA_algo(float x1,float y1,float x2,float y2)//DDA Algorithm
{
float dx = x2-x1;
float dy = y2-y1;
float steps;

if(abs(dx)>abs(dy))
	steps=dx;
else
	steps=dy;
	cout<<steps<<"ho  ";
	
float Xinc=dx/steps;
float Yinc=dy/steps;
cout<<Xinc<<"  "<<Yinc;
int x=x1;
int y=y1;
for(int i=1;i<steps;i++)
{

putpixel(x,y,RED);
x=x+Xinc;
y=y+Yinc;

}

}

void Bresenhem(float x1,float y1,float x2,float y2)//Bresenhem Algorithm
{
float dx =abs( x2-x1);
float dy =abs( y2-y1);
int sign,interchange;
(x2-x1)>=0?sign=1:sign=0;
if(dy>dx)
{
int temp=dx;
dx=dy;
dy=temp;
interchange=1;
}else
interchange=0;

int e=2*dy-dx;

for(int i=1;i<dx;i++)
{
setpixel(x,y);
while(e>0)
{
if(interchange)
	x1=x1+s1;
else
	y1=y1+s2;
e=e-2*dx;		


}
}


}



int main()//main Function
{
int gd=DETECT, gm;
initgraph(&gd,&gm,NULL);
setbkcolor(WHITE);
//std::cout<<"hi";
float X0=2,Y0=2,X1=140,Y1=160;
DDA_algo(20,20,140,160);
delay(5000);
closegraph();
return 0;
}

