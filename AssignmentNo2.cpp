/*
					ASSIGNMENT NO 2
Problem Statement:- Write C++ program to draw circle using
					Bresenham‘s algorithm. Inherit pixel class. 

NAME: VIKAS LAXMAN DONGARE
CLASS: SE-B
ROLL NO: 15

*/



#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
class brecircle
{
      int Xc,Yc,Xi,Yi,R,Di,limit,d,d_;
      public:
      void mycircle(int,int,int);
      void mh()
      {
        Xi=Xi+1;
        Di=Di+(2*Xi)+1;
      }
      void mv()
      {
        Yi=Yi-1;
        Di=Di-(2*Yi)+1;
      }

      
      void md()
      {
         Xi=Xi+1;
         Yi=Yi-1;
         Di=Di+(2*Xi)-(2*Yi)+2;
      }
     
      
};
void brecircle::mycircle(int Xc,int Yc,int R)
{
    limit=0;
    Xi=0;
    Yi=R;
    Di=2*(1-R);
    while(Yi>=limit)
    {
        putpixel(Xc+Xi,Yc+Yi,RED);
        putpixel(Xc+Xi,Yc-Yi,BLUE);
        putpixel(Xc-Xi,Yc-Yi,10);
        putpixel(Xc-Xi,Yc+Yi,15);
        
        if(Di<0)
        {
            d=(2*Di)+(2*Yi)-1;
            if(d<=0)
                mh();
            else
                md();
        }
        else if(Di>0)
        {
            d_=(2*Di)-(2*Xi)-1;
            if(d_<=0)
                md();
            else
                mv();
        }
       else if(Di==0)
                md();
    }
}

int main()
{
    brecircle c;
    int xc,yc,r;
    int gd=DETECT,gm;
    cout<<"\nEnter the coordinates of circle(x,y): ";
    cin>>xc>>yc;
    cout<<"\nEnter the radius of circle: ";
    cin>>r;
    initgraph(&gd,&gm,NULL);
    c.mycircle(xc,yc,r);
    getch();
    delay(500);
    closegraph();
    return 0;
}
    
      
         
