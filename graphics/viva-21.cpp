#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

float xa,xb,ya,yb,dx,dy,u1,u2,xa1,ya1,xb1,yb1,xa2,xb2,ya2,yb2,u11,u21,dx1,dy1,u211,u111,dx11,dy11;

float xaN,xbN,yaN,ybN,dxN,dyN,u1N,u2N,xa1N,ya1N,xb1N,yb1N,xa2N,xb2N,ya2N,yb2N,u11N,u21N,dx1N,dy1N,u211N,u111N,dx11N,dy11N;

int count =0;
int value,value1;
int hh;

pair<int,int> pts[4];
pair<int,int> ptsNew[4];



bool ClipTestNew1(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u2N)
      retVal = false;
    
    else 
    if(r>u1N)
      u1N=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u1N)
      retVal=false;
    else
      if (r<u2N)
      u2N=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}

bool ClipTest2(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u211)
      retVal = false;
    
    else 
    if(r>u111)
      u111=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u111)
      retVal=false;
    else
      if (r<u211)
      u211=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}

bool ClipTestNew3(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u211N)
      retVal = false;
    
    else 
    if(r>u111N)
      u111N=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u111N)
      retVal=false;
    else
      if (r<u211N)
      u211N=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}

bool ClipTestNew2(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u21N)
      retVal = false;
    
    else 
    if(r>u11N)
      u11N=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u11N)
      retVal=false;
    else
      if (r<u21N)
      u21N=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}

bool ClipTest1(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u21)
      retVal = false;
    
    else 
    if(r>u11)
      u11=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u11)
      retVal=false;
    else
      if (r<u21)
      u21=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}

bool ClipTest(float p,float q){
  float r;
  bool retVal=true;

  if(p<0.0){
    r=q/p;
    if(r>u2)
      retVal = false;
    
    else 
    if(r>u1)
      u1=r;
    
  }
  else if(p>0.0) {
    r=q/p;
    if(r<u1)
      retVal=false;
    else
      if (r<u2)
      u2=r;
  }
  else if(q<0.0){
    retVal=false;
  }
  return retVal;
}



void display(){


	
	glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,700, 0,700);
glClear(GL_COLOR_BUFFER_BIT );
  
  glColor3f(1,1,0);

  glBegin(GL_LINES);
  glVertex2i(0,700);
  glVertex2i(700,0);
  
  glEnd();
glColor3f(0.4,0.7,0.1);

  glBegin(GL_LINES);
  glVertex2i(450,550);
  glVertex2i(678,659);
  
  glEnd();
glColor3f(1,1,0.1);
  glBegin(GL_LINES);

  glVertex2i(350,150);
  glVertex2i(678,101);
  
  glEnd();

if((xa!=0&&ya!=700)||(xb!=700&&yb!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa,ya);
  glVertex2i(xb,yb);
  
  glEnd();
}

if((xaN!=0&&yaN!=700)||(xbN!=700&&ybN!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xaN,yaN);
  glVertex2i(xbN,ybN);
  
  glEnd();
}

if((xa1!=450&&ya1!=550)||(xb1!=678&&yb1!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1,ya1);
  glVertex2i(xb1,yb1);
  
  glEnd();
}

if((xa1N!=450&&ya1N!=550)||(xb1N!=678&&yb1N!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1N,ya1N);
  glVertex2i(xb1N,yb1N);
  
  glEnd();
}

if((xa2!=350&&ya2!=150)||(xb2!=678&&yb2!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2,ya2);
  glVertex2i(xb2,yb2);
  
  glEnd();
}
if((xa2N!=350&&ya2N!=150)||(xb2N!=678&&yb2N!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2N,ya2N);
  glVertex2i(xb2N,yb2N);
  
  glEnd();
}
  glFlush();
/*glColor3f(1,0,0);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<pts[i].first<<" "<<pts[i].second<<"|\n";
      glVertex2i(pts[i].first,pts[i].second);
    }

    glEnd();

    glColor3f(1,0.9,0.9);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<ptsNew[i].first<<" "<<ptsNew[i].second<<"|\n";
      glVertex2i(ptsNew[i].first,ptsNew[i].second);
      hh=1;
    }

    glEnd();

    glFlush();*/

  if(hh==1){
         int xx,xy;
        cout<<value<<"\n";
        for(int i=0;i<1000;i++){
          value =rand();
          xx = value%1000;
          
          if(xx<=650&&xy<=650){
            if(value%2==0){
          //2 digit number
          value = value%100;
          
          cout<<"==========================\n";
          //cout<<value;


          pts[0].first=value;
          if(value>=0&&value<=350){

          ptsNew[0].first=value+250;
        }
        else{
         ptsNew[0].first=value-275; 
        }
              if(rand()%2==0){

                value = (rand()%1000);
                
                if(value>=650)
                  value-=350;
                
              }
              else{
                value = (rand()%100);
                
                if(value>=650)
                  value-=350;
                
              }
          pts[0].second=value;
           if(value>=0&&value<=350){

          ptsNew[0].second=value+350;
        }else{
         ptsNew[0].second=value-225; 
        }
              
          pts[1].first=pts[0].first+50;
          pts[1].second=pts[0].second;

          pts[2].first=pts[0].first+50;
          pts[2].second=pts[0].second+50;    

          pts[3].first=pts[0].first;
          pts[3].second=pts[0].second+50;    
//====================================================
          ptsNew[1].first=ptsNew[0].first+50;
          ptsNew[1].second=ptsNew[0].second;

          ptsNew[2].first=ptsNew[0].first+50;
          ptsNew[2].second=ptsNew[0].second+50;    

          ptsNew[3].first=ptsNew[0].first;
          ptsNew[3].second=ptsNew[0].second+50;
          
          xa=0;ya=700;
          xb=700;yb=0;

          u1=0.0;u2=1.0;
          dx=xb-xa;
          dy=yb-ya;

         if(ClipTest(-dx,xa-(pts[0].first))){
          if(ClipTest(dx,(pts[0].first+50)-xa)){
          
          if(ClipTest(-dy,ya-(pts[0].second))){
            if(ClipTest(dy,(pts[0].second+50)-ya)){
              if(u2<1.0){
                xb=xa+u2*dx;
                yb=ya+u2*dy;
              }
              if(u1>0.0){
                xa=xa+u1*dx;
                ya=ya+u1*dy;
                        }
              }
          }
          }
         }
           
         
         xaN=0;yaN=700;
          xbN=700;ybN=0;

         u1N=0.0;u2N=1.0;
          dxN=xbN-xaN;
          dyN=ybN-yaN;

         if(ClipTestNew1(-dxN,xaN-(ptsNew[0].first))){
          if(ClipTestNew1(dxN,(ptsNew[0].first+50)-xaN)){
          
          if(ClipTestNew1(-dyN,yaN-(ptsNew[0].second))){
            if(ClipTestNew1(dyN,(ptsNew[0].second+50)-yaN)){
              if(u2N<1.0){
                xbN=xaN+u2N*dxN;
                ybN=yaN+u2N*dyN;
              }
              if(u1>0.0){
                xaN=xaN+u1N*dxN;
                yaN=yaN+u1N*dyN;
                        }
              }
          }
          }
         }

            xa1=450;ya1=550;
          xb1=678;yb1=659;

          u11=0.0;u21=1.0;
          dx1=xb1-xa1;
          dy1=yb1-ya1;

        if(ClipTest1(-dx1,xa1-(pts[0].first))){
          cout<<"\n1\n";
          if(ClipTest1(dx1,(pts[0].first+50)-xa1)){
          cout<<"2\n";
          if(ClipTest1(-dy1,ya1-(pts[0].second))){
            cout<<"3\n";
            if(ClipTest1(dy1,(pts[0].second+50)-ya1)){
              cout<<"4\n";
              if(u21<1.0){
                xb1=xa1+u21*dx1;
                yb1=ya1+u21*dy1;
                cout<<"xb1="<<xb1<<"&"<<"yb1="<<yb1<<"\n";
              }
              if(u11>0.0){
                xa1=xa1+u11*dx1;
                ya1=ya1+u11*dy1;
                cout<<"xa1="<<xa1<<"&"<<"ya1="<<ya1<<"\n";
              }
            }
          }
          }
         }   
 
   xa1N=450;ya1N=550;
          xb1N=678;yb1N=659;
        u11N=0.0;u21N=1.0;
          dx1N=xb1N-xa1N;
          dy1N=yb1N-ya1N;

        if(ClipTestNew2(-dx1N,xa1N-(ptsNew[0].first))){
          
          if(ClipTestNew2(dx1N,(ptsNew[0].first+50)-xa1N)){
          
          if(ClipTestNew2(-dy1N,ya1N-(ptsNew[0].second))){
          
            if(ClipTestNew2(dy1N,(ptsNew[0].second+50)-ya1N)){
          
              if(u21N<1.0){
                xb1N=xa1N+u21N*dx1N;
                yb1N=ya1N+u21N*dy1N;
                cout<<"xb1N="<<xb1N<<"&"<<"yb1N="<<yb1N<<"\n";
              }
              if(u11N>0.0){
                xa1N=xa1N+u11N*dx1N;
                ya1N=ya1N+u11N*dy1N;
                cout<<"xa1N="<<xa1N<<"&"<<"ya1N="<<ya1N<<"\n";
              }
            }
          }
          }
         }  

       
        xa2=350;ya2=150;
          xb2=678;yb2=101;

          u111=0.0;u211=1.0;
          dx11=xb2-xa2;
          dy11=yb2-ya2;

        if(ClipTest2(-dx11,xa2-(pts[0].first))){
          if(ClipTest2(dx11,(pts[0].first+50)-xa2)){
          
          if(ClipTest2(-dy11,ya2-(pts[0].second))){
            if(ClipTest2(dy11,(pts[0].second+50)-ya2)){
              if(u211<1.0){
                xb2=xa2+u211*dx11;
                yb2=ya2+u211*dy11;
              }
              if(u111>0.0){
                xa2=xa2+u111*dx11;
                ya2=ya2+u111*dy11;
              }
            }
          }
          }
         }   


         xa2N=350;ya2N=150;
          xb2N=678;yb2N=101;

          u111N=0.0;u211N=1.0;
          dx11N=xb2N-xa2N;
          dy11N=yb2N-ya2N;

        if(ClipTestNew3(-dx11N,xa2N-(ptsNew[0].first))){
          if(ClipTestNew3(dx11N,(ptsNew[0].first+50)-xa2N)){
          
          if(ClipTestNew3(-dy11N,ya2N-(ptsNew[0].second))){
            if(ClipTestNew3(dy11N,(ptsNew[0].second+50)-ya2N)){
              if(u211N<1.0){
                xb2N=xa2N+u211N*dx11N;
                yb2N=ya2N+u211N*dy11N;
              }
              if(u111N>0.0){
                xa2N=xa2N+u111N*dx11N;
                ya2N=ya2N+u111N*dy11N;
              }
            }
          }
          }
         }   

         //===========================================================================
glColor3f(1,1,0);

  glBegin(GL_LINES);
  glVertex2i(0,700);
  glVertex2i(700,0);
  
  glEnd();
glColor3f(0.4,0.7,0.1);

  glBegin(GL_LINES);
  glVertex2i(450,550);
  glVertex2i(678,659);
  
  glEnd();
glColor3f(1,1,0.1);
  glBegin(GL_LINES);

  glVertex2i(350,150);
  glVertex2i(678,101);
  
  glEnd();

if((xa!=0&&ya!=700)||(xb!=700&&yb!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa,ya);
  glVertex2i(xb,yb);
  
  glEnd();
}

if((xaN!=0&&yaN!=700)||(xbN!=700&&ybN!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xaN,yaN);
  glVertex2i(xbN,ybN);
  
  glEnd();
}

if((xa1!=450&&ya1!=550)||(xb1!=678&&yb1!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1,ya1);
  glVertex2i(xb1,yb1);
  
  glEnd();
}

if((xa1N!=450&&ya1N!=550)||(xb1N!=678&&yb1N!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1N,ya1N);
  glVertex2i(xb1N,yb1N);
  
  glEnd();
}

if((xa2!=350&&ya2!=150)||(xb2!=678&&yb2!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2,ya2);
  glVertex2i(xb2,yb2);
  
  glEnd();
}
if((xa2N!=350&&ya2N!=150)||(xb2N!=678&&yb2N!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2N,ya2N);
  glVertex2i(xb2N,yb2N);
  
  glEnd();
}


              //===========================================================================





         glColor3f(1,0,0);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<pts[i].first<<" "<<pts[i].second<<"|\n";
      glVertex2i(pts[i].first,pts[i].second);
    }

    glEnd();

    glColor3f(1,0.9,0.9);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<ptsNew[i].first<<" "<<ptsNew[i].second<<"|\n";
      glVertex2i(ptsNew[i].first,ptsNew[i].second);
      hh=1;
    }

    glEnd();

    glFlush();
         sleep(1);

        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT );
   //s    break;

        }
    
        else {
          value = xx;
          cout<<"==========================\n";
          cout<<value;
          pts[0].first=value;
          if(value>=0&&value<=350){

          ptsNew[0].first=value+250;
        }
        else{
         ptsNew[0].first=value-275; 
        }
          if(rand()%2==0){

                value = (rand()%1000);
                if(value>=650)
                  value-=350;
              }
              else{
                value = (rand()%100);
                if(value>=650)
                  value-=350;
              }
          pts[0].second=value;
          if(value>=0&&value<=350){

          ptsNew[0].second=value+350;
        }else{
         ptsNew[0].second=value-225; 
        }


          pts[1].first=pts[0].first+50;
          pts[1].second=pts[0].second;

          pts[2].first=pts[0].first+50;
          pts[2].second=pts[0].second+50;    

          pts[3].first=pts[0].first;
          pts[3].second=pts[0].second+50; 

          ptsNew[1].first=ptsNew[0].first+50;
          ptsNew[1].second=ptsNew[0].second;

          ptsNew[2].first=ptsNew[0].first+50;
          ptsNew[2].second=ptsNew[0].second+50;    

          ptsNew[3].first=ptsNew[0].first;
          ptsNew[3].second=ptsNew[0].second+50;


          xa=0;ya=700;
          xb=700;yb=0;


          u1=0.0;u2=1.0;
         dx=xb-xa;
         dy=yb-ya;

         if(ClipTest(-dx,xa-(pts[0].first))){
          if(ClipTest(dx,(pts[0].first+50)-xa)){
          
          if(ClipTest(-dy,ya-(pts[0].second))){
            if(ClipTest(dy,(pts[0].second+50)-ya)){
              if(u2<1.0){
                xb=xa+u2*dx;
                yb=ya+u2*dy;
              }
              if(u1>0.0){
                xa=xa+u1*dx;
                ya=ya+u1*dy;
              }
            }
          }
          }
         }
         xaN=0;yaN=700;
          xbN=700;ybN=0;

         u1N=0.0;u2N=1.0;
          dxN=xbN-xaN;
          dyN=ybN-yaN;

         if(ClipTestNew1(-dxN,xaN-(ptsNew[0].first))){
          if(ClipTestNew1(dxN,(ptsNew[0].first+50)-xaN)){
          
          if(ClipTestNew1(-dyN,yaN-(ptsNew[0].second))){
            if(ClipTestNew1(dyN,(ptsNew[0].second+50)-yaN)){
              if(u2N<1.0){
                xbN=xaN+u2N*dxN;
                ybN=yaN+u2N*dyN;
              }
              if(u1>0.0){
                xaN=xaN+u1N*dxN;
                yaN=yaN+u1N*dyN;
                        }
              }
          }
          }
         }
           xa1=450;ya1=550;
          xb1=678;yb1=659;

          u11=0.0;u21=1.0;
          dx1=xb1-xa1;
          dy1=yb1-ya1;

        if(ClipTest1(-dx1,xa1-(pts[0].first))){
          cout<<"\n1\n";
          if(ClipTest1(dx1,(pts[0].first+50)-xa1)){
          cout<<"2\n";
          if(ClipTest1(-dy1,ya1-(pts[0].second))){
            cout<<"3\n";
            if(ClipTest1(dy1,(pts[0].second+50)-ya1)){
              cout<<"4\n";
              if(u21<1.0){
                xb1=xa1+u21*dx1;
                yb1=ya1+u21*dy1;
                cout<<"xb1="<<xb1<<"&"<<"yb1="<<yb1<<"\n";
              }
              if(u11>0.0){
                xa1=xa1+u11*dx1;
                ya1=ya1+u11*dy1;
                cout<<"xa1="<<xa1<<"&"<<"ya1="<<ya1<<"\n";
              }
            }
          }
          }
         }  
         
          xa1N=450;ya1N=550;
          xb1N=678;yb1N=659;
        u11N=0.0;u21N=1.0;
          dx1N=xb1N-xa1N;
          dy1N=yb1N-ya1N;

        if(ClipTestNew2(-dx1N,xa1N-(ptsNew[0].first))){
          
          if(ClipTestNew2(dx1N,(ptsNew[0].first+50)-xa1N)){
          
          if(ClipTestNew2(-dy1N,ya1N-(ptsNew[0].second))){
          
            if(ClipTestNew2(dy1N,(ptsNew[0].second+50)-ya1N)){
          
              if(u21N<1.0){
                xb1N=xa1N+u21N*dx1N;
                yb1N=ya1N+u21N*dy1N;
                cout<<"xb1N="<<xb1N<<"&"<<"yb1N="<<yb1N<<"\n";
              }
              if(u11N>0.0){
                xa1N=xa1N+u11N*dx1N;
                ya1N=ya1N+u11N*dy1N;
                cout<<"xa1N="<<xa1N<<"&"<<"ya1N="<<ya1N<<"\n";
              }
            }
          }
          }
         }  


        xa2=350;ya2=150;
          xb2=678;yb2=101;

          u111=0.0;u211=1.0;
          dx11=xb2-xa2;
          dy11=yb2-ya2;

        if(ClipTest2(-dx11,xa2-(pts[0].first))){
          if(ClipTest2(dx11,(pts[0].first+50)-xa2)){
          
          if(ClipTest2(-dy11,ya2-(pts[0].second))){
            if(ClipTest2(dy11,(pts[0].second+50)-ya2)){
              if(u211<1.0){
                xb2=xa2+u211*dx11;
                yb2=ya2+u211*dy11;
              }
              if(u111>0.0){
                xa2=xa2+u111*dx11;
                ya2=ya2+u111*dy11;
              }
            }
          }
          }
         }   

         xa2N=350;ya2N=150;
          xb2N=678;yb2N=101;

          u111N=0.0;u211N=1.0;
          dx11N=xb2N-xa2N;
          dy11N=yb2N-ya2N;

        if(ClipTestNew3(-dx11N,xa2N-(ptsNew[0].first))){
          if(ClipTestNew3(dx11N,(ptsNew[0].first+50)-xa2N)){
          
          if(ClipTestNew3(-dy11N,ya2N-(ptsNew[0].second))){
            if(ClipTestNew3(dy11N,(ptsNew[0].second+50)-ya2N)){
              if(u211N<1.0){
                xb2N=xa2N+u211N*dx11N;
                yb2N=ya2N+u211N*dy11N;
              }
              if(u111N>0.0){
                xa2N=xa2N+u111N*dx11N;
                ya2N=ya2N+u111N*dy11N;
              }
            }
          }
          }
         }   

         glColor3f(1,0,0);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<pts[i].first<<" "<<pts[i].second<<"|\n";
      glVertex2i(pts[i].first,pts[i].second);
    }

    glEnd();


    //===================================================================================


          glColor3f(1,1,0);

  glBegin(GL_LINES);
  glVertex2i(0,700);
  glVertex2i(700,0);
  
  glEnd();
glColor3f(0.4,0.7,0.1);

  glBegin(GL_LINES);
  glVertex2i(450,550);
  glVertex2i(678,659);
  
  glEnd();
glColor3f(1,1,0.1);
  glBegin(GL_LINES);

  glVertex2i(350,150);
  glVertex2i(678,101);
  
  glEnd();

if((xa!=0&&ya!=700)||(xb!=700&&yb!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa,ya);
  glVertex2i(xb,yb);
  
  glEnd();
}

if((xaN!=0&&yaN!=700)||(xbN!=700&&ybN!=0)){

  glColor3f(1,0.2,0.9);
  
  glBegin(GL_LINES);
  
  glVertex2i(xaN,yaN);
  glVertex2i(xbN,ybN);
  
  glEnd();
}

if((xa1!=450&&ya1!=550)||(xb1!=678&&yb1!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1,ya1);
  glVertex2i(xb1,yb1);
  
  glEnd();
}

if((xa1N!=450&&ya1N!=550)||(xb1N!=678&&yb1N!=659)){
 
  glColor3f(0,1,0.7);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1N,ya1N);
  glVertex2i(xb1N,yb1N);
  
  glEnd();
}

if((xa2!=350&&ya2!=150)||(xb2!=678&&yb2!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2,ya2);
  glVertex2i(xb2,yb2);
  
  glEnd();
}
if((xa2N!=350&&ya2N!=150)||(xb2N!=678&&yb2N!=101)){

  glColor3f(0.6,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2N,ya2N);
  glVertex2i(xb2N,yb2N);
  
  glEnd();
}



//================================================================================

    glColor3f(1,0.9,0.9);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<ptsNew[i].first<<" "<<ptsNew[i].second<<"|\n";
      glVertex2i(ptsNew[i].first,ptsNew[i].second);
      hh=1;
    }

    glEnd();

    glFlush();
         sleep(1);
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT );
          //continue;
        //break;
        }

          }
        }
    
    
    }
    
}


void mouse(int button,int state,int x,int y){
	
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      hh=1;
      glutPostRedisplay();


    }        
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Advanced VIVA Question");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	
	glutMainLoop();
	return 0;
}