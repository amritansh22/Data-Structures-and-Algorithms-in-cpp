/*Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel
class and Use function overloading.*/
#include<iostream>
#include<graphics.h>
using namespace std;
class pixel
{
public:
int x0,x1,y0,y1;
void getdata();
};
void pixel ::getdata()
{
cout<<" Enter the starting coordinates of line "<<"\n";
cin>>x0>>y0;
cout<<" Enter the end coordinates of line "<<"\n";
cin>>x1>>y1;
}
class linedraw :public pixel
{
public:
void line();
void line(int c);
int sign(int a,int b);
};
  void linedraw ::line()
  {
   float dx,dy,x,y,steps;
    dx=x1-x0;
    dy=y1-y0;
     if(fabs(dx)>fabs(dy))
        steps=fabs(dx);
    else
        steps=fabs(dy);
     dx=dx/steps;
     dy=dy/steps;
       x=x0;
       y=y0;
    for(int i=0;i<steps;i++)
       {
           putpixel(x,y,RED);
           x+=dx;
        y+=dy;
       }

 }
   int linedraw :: sign(int a,int b)
  {
  if(a<b)
  return 1;
  else
  return -1;
  }
  
 void linedraw ::line(int c)
 {
   float x,y,dx,dy,s1,s2,temp,inter,e;
   x=x0 ;
   y=y0;
   dx=x1-x0;
   dy=y1-y0;
   s1=sign(x0,x1);
   s2=sign(y0,y1);
   if(dy>dx)
   {
   temp=dx;
   dx=dy;
   dy=temp;
   inter=1;
   
   } 
   else
   {
   inter =0;
   }
  e=2*dy-dx;
 for(int i=0;i<dx;i++)
 {
 putpixel(x,y,RED);
  while(e>0)
  {
  if(inter==1)
  {
  x=x+s1;
  
  }
  else
  {
  y=y+s2;
  }
  e=e-2*dx;
  
  
  }
 if(inter==1)
 {
 y=y+s2;
 }
 else
 {
 x=x+s1;
 }
 e=e+2*dy;
 
 }
 
 
} 
 
 int main()
 {
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,NULL);
 
 linedraw obj;
 setbkcolor(WHITE);
 int x;
      
    do
    {
    cout<<"1.DDA\n2.Breshanam\n3.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>x;
    switch(x)
    {
    case 1 : 
           obj.getdata();
             obj.line();
             break;
    case 2 : 
            obj.getdata();
             obj.line(2);
             break;
    case 3 : exit(1);
    }
    } 
    while(x=3);                
    return 0;
    }

 
 
 
 

