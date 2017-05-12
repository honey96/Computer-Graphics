#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

float xa,xb,ya,yb,dx,dy,u1,u2,xa1,ya1,xb1,yb1,xa2,xb2,ya2,yb2,u11,u21,dx1,dy1,u211,u111,dx11,dy11;

int count =0;
int value;
int hh;

pair<int,int> pts[4];

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
glColor3f(0.2,0.5,0.8);

  glBegin(GL_LINES);
  glVertex2i(250,450);
  glVertex2i(234,359);
  
  glEnd();
glColor3f(1,1,0.8);
  glBegin(GL_LINES);

  glVertex2i(450,350);
  glVertex2i(578,301);
  
  glEnd();

if((xa!=0&&ya!=700)||(xb!=700&&yb!=0)){

  glColor3f(1,0,0);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa,ya);
  glVertex2i(xb,yb);
  
  glEnd();
}
if((xa1!=250&&ya1!=450)||(xb1!=234&&yb1!=359)){
 
  glColor3f(0,1,0);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1,ya1);
  glVertex2i(xb1,yb1);
  
  glEnd();
}
if((xa2!=450&&ya2!=350)||(xb2!=578&&yb2!=301)){

  glColor3f(0,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2,ya2);
  glVertex2i(xb2,yb2);
  
  glEnd();
}
  

/*if((xa1!=450&&ya1!=550)||(xb1!=678&&yb1!=659)){
 
  glColor3f(0,1,0);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa1,ya1);
  glVertex2i(xb1,yb1);
  
  glEnd();
}
if((xa2!=350&&ya2!=150)||(xb2!=678&&yb2!=101)){

  glColor3f(0,0,1);
  
  glBegin(GL_LINES);
  
  glVertex2i(xa2,ya2);
  glVertex2i(xb2,yb2);
  
  glEnd();
}
  
*/
  if(hh==1){

    glColor3f(1,0,0);
    
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<pts[i].first<<" "<<pts[i].second<<"|\n";
      glVertex2i(pts[i].first,pts[i].second);
    }

    glEnd();
    
    }
    glFlush();
}


void mouse(int button,int state,int x,int y){
	
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int xx;
        cout<<value<<"\n";
        for(int i=0;i<1000;i++){
          value =rand();
          xx = value%1000;
          if(xx<=650){
            if(value%2==0){
          //2 digit number
          value = value%100;
          cout<<"==========================\n";
          cout<<value;


          pts[0].first=value;
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
          hh=1;

              //===========================================================================
          pts[1].first=pts[0].first+50;
          pts[1].second=pts[0].second;

          pts[2].first=pts[0].first+50;
          pts[2].second=pts[0].second+50;    

          pts[3].first=pts[0].first;
          pts[3].second=pts[0].second+50;    


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
            

	 xa1=250;ya1=450;
          xb1=234;yb1=359;
            /*xa1=450;ya1=550;
          xb1=678;yb1=659;
*/
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
 
       
        xa2=450;ya2=350;
          xb2=578;yb2=301;

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
         hh=1;
        glutPostRedisplay();
          break;
        }
    
        else {
          value = xx;
          cout<<"==========================\n";
          cout<<value;
          pts[0].first=value;
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
          hh=1;


          pts[1].first=pts[0].first+50;
          pts[1].second=pts[0].second;

          pts[2].first=pts[0].first+50;
          pts[2].second=pts[0].second+50;    

          pts[3].first=pts[0].first;
          pts[3].second=pts[0].second+50;    


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
           /*xa1=450;ya1=550;
          xb1=678;yb1=659;
*/
	xa1=250;ya1=450;
          xb1=234;yb1=359;
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
         
        
        xa2=450;ya2=350;
          xb2=578;yb2=301;

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
        glutPostRedisplay();
          break;
        }

          }
        }

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
