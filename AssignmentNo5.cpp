/*
					ASSIGNMENT NO 5
Problem Statement:- Write C++ program to draw the given pattern
					using any Line and circle drawing algorithms. 

               

NAME: VIKAS LAXMAN DONGARE
CLASS: SE-B
ROLL NO: 15

*/

#include<iostream>
#include<cstdlib>
#include<graphics.h>

using namespace std;

class pixel
{
	
	protected:
	void setpixel(int a, int b,int c=15)
	{
	putpixel(a+320,240-b,c);
	}
};

class linee:public pixel
{	
		int x,y;
		int dx,dy;
		int interchange,e_;
		
	    int sign(int x)
	    {
	    	if(x>0)
	    		return 1;
	    	else if(x<0)
	    		return -1;
	    	else if(x==0)
	    		return 0;
	    }
	public:
	
	void bres(int x1,int y1,int x2,int y2)
	{
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1;
		y=y1;
		int s1=sign(x2-x1);
		int s2=sign(y2-y1);
		
		if(dy>dx)
		{
			int temp;
			temp=dy;
			dy=dx;
			dx=temp;
			interchange=1;
		}
		else
			interchange=0;
		e_=2*dy-dx;
		
			
		for(int i=1;i<=dx;i++)
		{
			setpixel(x,y);
			while(e_>0)
			{
				if(interchange==1)
					x=x+s1;
				else
					y=y+s2;
				
				e_=e_-2*dx;
				
			}
			
			if(interchange==1)
				y=y+s2;
			else
				x=x+s1;
			
			e_=e_+2*dy;
			
			delay(5);
			
		}
		
	
	
	}
	
};

int main()
{
	int ch;
	linee l;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,NULL);
	line(320,0,320,480);
	line(0,240,640,240);
	l.bres(-100,50,-100,-50);
	l.bres(-100,-50,100,-50);
	l.bres(100,-50,100,50);
	l.bres(100,50,-100,50);
	l.bres(0,50,-100,0);
	l.bres(-100,0,0,-50);
	l.bres(0,-50,100,0);
	l.bres(100,0,0,50);
	l.bres(-50,25,-50,-25);
	l.bres(-50,-25,50,-25);
	l.bres(50,-25,50,25);
	l.bres(50,25,-50,25);
	
	delay(5000);
	closegraph();
	

}
