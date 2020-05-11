/*
					ASSIGNMENT NO 3
Problem Statement:- Write C++ program to draw 2-D object and
					perform following basic transformations, 
					a) Scaling 
					b) Translation
					c) Rotation 
					Use operator overloading.  

NAME: VIKAS LAXMAN DONGARE
CLASS: SE-B
ROLL NO: 15

*/


#include<iostream>
#include<graphics.h>
#include<iomanip>
#include<cmath>
using namespace std;
class D
{
      protected:
            float translate[3][3],scaling[3][3],rotation[3][3];
            float** arr;
            int n;
      public:
            D(int no)
            {
                  n=no;
                  arr=new float*[n];
                  for(int i=0;i<n;i++)
                    arr[i]=new float[3];
                  
            }
     
     void getpolygon()
     {
             
	     int i=0;
	     cout<<"\nEnter coordinates of "<<n<<" vertices(x,y): ";
	     while(i<n)
	     {
	        
	        
	            cout<<"\nEnter vertex "<<i+1<<": ";
	            cin>>arr[i][0];
	            cin>>arr[i][1];
	            arr[i][2]=1;
	         
	       i++;    
        }
     }
     void display()
     {
        for(int i=0;i<n-1;i++)
            line(320+arr[i][0],240-arr[i][1],320+arr[i+1][0],240-arr[i+1][1]);
            
            
        line(320+arr[n-1][0],240-arr[n-1][1],320+arr[0][0],240-arr[0][1]);
     }
     void Translate()
     {
        int i=0;
        float tx,ty;

        cout<<"\nEnter the value by how much you want to translate(x,y)(put negative for leftward and downward translation): ";
        cin>>tx>>ty;
        
         for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                       		translate[i][j]=0;   
                              
                                
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i==j)
                    translate[i][j]=1;
        translate[2][0]=tx;
        translate[2][1]=ty;
        
                
                
       Multiply(translate);
     }
     void Scaling()
     {
     	int i=0;
        float sx,sy;

        cout<<"\nEnter the value by how much you want to scale(x,y)(put negative for leftward and downward translation): ";
        cin>>sx>>sy;
       
         for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)  
                       		 scaling[i][j]=0;
                           
       	 scaling[0][0]=sx;
         scaling[1][1]=sy;
         scaling[2][2]=1;
        
                
       Multiply(scaling);
    }
    void Rotate()
    {
    	int i=0;
    	float yp,xp,ra;
    	cout<<"\nEnter the value of angle: ";
    	cin>>ra;
    	
         for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                       	       rotation[i][j]=0;
                       	       
         rotation[0][0]=rotation[1][1]=cos(ra*3.14/180);
         rotation[0][1]=sin(ra*3.14/180);
         rotation[1][0]=-sin(ra*3.14/180);
         rotation[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
         rotation[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
         rotation[2][2]=1;
         
         Multiply(rotation);
     }
       			
    	
        
     void Multiply(float t[3][3])
     {
        float** result;
        
        result=new float*[n];
            for(int i=0;i<n;i++)
                result[i]=new float[3];
                
              
                    
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    result[i][j]+=arr[i][k]*t[k][j];
                    
                    
                    
                    
    
        
        for(int i=0;i<n-1;i++)
            line(320+result[i][0],240-result[i][1],320+result[i+1][0],240-result[i+1][1]);
            
            
        line(320+result[n-1][0],240-result[n-1][1],320+result[0][0],240-result[0][1]);     
                         
     }
};
int main()
{
    int no,ch;
	int gd=DETECT, gm;                      
	cout<<"\nEnter the no of vertices of your polygon: ";
	cin>>no;
	D d(no);
	
	d.getpolygon();
	initgraph(&gd,&gm,NULL);
        line(320,0,320,480);
        line(0,240,640,240);
      
	d.display();
	delay(1000);
 
    do
    {
        cout<<"\n***MENU***\n1.Translate\n2.Scaling\n3.Rotation\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            	setcolor(RED); 
                d.Translate();
                
		delay(1000);
   		
                break;
            case 2:
            	setcolor(GREEN);
            	d.Scaling();
            	delay(1000);
            	break; 
            	
            case 3:
            	setcolor(LIGHTBLUE);
            	d.Rotate();
            	delay(1000);
            	break; 
	    case 4:
		closegraph();
		break;
        }
    }while(ch<4);              
    
}
	
