#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

float xa,xb,ya,yb,dx,dy,u1,u2;
int count =0;
int value;
int hh;
pair<int,int> pts[4];
void display(){
	float temp=0.0;
	
	glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,700, 0,700);
glClear(GL_COLOR_BUFFER_BIT );
  
  glColor3f(1,1,0);

  glBegin(GL_LINES);
  glVertex2i(0,700);
  glVertex2i(700,0);
  
  glEnd();
if(xa!=0&&ya!=700&&xb!=700&&yb!=0){
  glColor3f(1,0.5,0.6);
glBegin(GL_LINES);
  glVertex2i(xa,ya);
  glVertex2i(xb,yb);
  
  glEnd();
}

  glFlush();

  if(hh==1){
    


    glColor3f(1,0,0);
    int c=0;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++){
      cout<<" \n";
      cout<<pts[i].first<<" "<<pts[i].second<<"|\n";
      glVertex2i(pts[i].first,pts[i].second);
    }
    cout<<"=========="<<c<<"=========count";


      
    glEnd();
    glFlush();

    }

  
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
          pts[0].second=value;
          hh=1;

              //===========================================================================
    pts[1].first=pts[0].first+50;
    pts[1].second=pts[0].second;

    pts[2].first=pts[0].first+50;
    pts[2].second=pts[0].second+50;    

    pts[3].first=pts[0].first;
    pts[3].second=pts[0].second+50;    


    xa=0;
    ya=700;
    xb=700;
    yb=0;
    u1=0.0;u2=1.0;
         dx=xb-xa;
         dy=yb-ya;
         
     

         float p1,p2,p3,p4;
         p1=-dx;
         p2=dx;
         p3=-dy;
         p4=dy;

         float q1 = xa-value;
         float q2 = (value+50)-xa;
         float q3 = ya-value;
         float q4 = (value+50)-ya;
         float r1;
         float r2;
         float r3;
         float r4;

         if(((p1==0.0) && (q1<0.0)) || ((p2==0.0) && (q2<0.0)) || ((p3==0.0) && (q3<0.0)) || ((p4==0.0) && (q4<0.0))){
          cout<<"Outside the window";
          glutPostRedisplay();
         }
       else {
        if( p1 != 0.0 ){

          if( p1 < 0.0 ){
            r1 =(float) q1 /p1 ;
              if(r1>u1)
                u1=r1;
        } 
        else {
          if(r1<u2)
            u2=r2;
        }
      }

      if( p2 != 0.0 ){

        r2 = (float ) q2 /p2 ;
        if( p2 > 0.0 ){
          if(r2<u2)
            u2=r2;          
          }
          else{
               if(r2>u1)
                u2=r2;
            }
        }
      
      if( p3 != 0.0 ){

        r3 = (float )q3 /p3 ;
        if( p3 < 0.0 ){
          if(r3>u1)
            u1=r3;    
        }
         else {
            if(r3<u2)
             u2=r3;
              }
        }
      if( p4 != 0.0 ){

        r4 = (float )q4 /p4 ;
        if( p4 > 0.0 ){
          if(r4<u2)
            u2=r4;
          }
          else{

        if(r4>u1)
          u1=r4;
          }
        }      

        cout<<u1<<" "<<u2<<"\n";

      if( u1 > u2 )
        cout<<"Line rejected\n";
        else
        {
        xa = xa + u1 * ( xb - xa ) ;
        ya = ya + u1 * ( yb - ya ) ;

        xb = xa + u2 * ( xb - xa );
        yb = ya + u2 * ( yb - ya );

        cout<<"=================================\n";
        /*xa = (int)xa;
        ya = (int)ya;
        xb = (int)xb;
        yb = (int)yb;*/
        cout<<xa<<"-"<<ya<<";\n";
        cout<<xb<<"-"<<yb<<";\n";
      
               }


         //==============================================
               
        glutPostRedisplay();
          break;
        }
        else {
          value = xx;
          cout<<"==========================\n";
          cout<<value;
          pts[0].first=value;
          pts[0].second=value;
          hh=1;

              //===========================================================================
    pts[1].first=pts[0].first+50;
    pts[1].second=pts[0].second;

    pts[2].first=pts[0].first+50;
    pts[2].second=pts[0].second+50;    

    pts[3].first=pts[0].first;
    pts[3].second=pts[0].second+50;    


    xa=0;
    ya=700;
    xb=700;
    yb=0;
    u1=0.0;u2=1.0;
         dx=xb-xa;
         dy=yb-ya;
         
     

         float p1,p2,p3,p4;
         p1=-dx;
         p2=dx;
         p3=-dy;
         p4=dy;

         float q1 = xa-value;
         float q2 = (value+50)-xa;
         float q3 = ya-value;
         float q4 = (value+50)-ya;
         float r1;
         float r2;
         float r3;
         float r4;

         if(((p1==0.0) && (q1<0.0)) || ((p2==0.0) && (q2<0.0)) || ((p3==0.0) && (q3<0.0)) || ((p4==0.0) && (q4<0.0))){
          cout<<"Outside the window";
          glutPostRedisplay();
         }
       else {
        if( p1 != 0.0 ){

          if( p1 < 0.0 ){
            r1 =(float) q1 /p1 ;
              if(r1>u1)
                u1=r1;
        } 
        else {
          if(r1<u2)
            u2=r2;
        }
      }

      if( p2 != 0.0 ){

        r2 = (float ) q2 /p2 ;
        if( p2 > 0.0 ){
          if(r2<u2)
            u2=r2;          
          }
          else{
               if(r2>u1)
                u2=r2;
            }
        }
      
      if( p3 != 0.0 ){

        r3 = (float )q3 /p3 ;
        if( p3 < 0.0 ){
          if(r3>u1)
            u1=r3;    
        }
         else {
            if(r3<u2)
             u2=r3;
              }
        }
      if( p4 != 0.0 ){

        r4 = (float )q4 /p4 ;
        if( p4 > 0.0 ){
          if(r4<u2)
            u2=r4;
          }
          else{

        if(r4>u1)
          u1=r4;
          }
        }      

        cout<<u1<<" "<<u2<<"\n";

      if( u1 > u2 )
        cout<<"Line rejected\n";
        else
        {
        xa = xa + u1 * ( xb - xa ) ;
        ya = ya + u1 * ( yb - ya ) ;

        xb = xa + u2 * ( xb - xa );
        yb = ya + u2 * ( yb - ya );

        cout<<"=================================\n";
        /*xa = (int)xa;
        ya = (int)ya;
        xb = (int)xb;
        yb = (int)yb;*/
        cout<<xa<<"-"<<ya<<";\n";
        cout<<xb<<"-"<<yb<<";\n";
      
               }


         //==============================================
               
        glutPostRedisplay();

          break;
        }

          }
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
	glutCreateWindow("Line Clipping-Liang Barsky");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	
	glutMainLoop();
	return 0;
}
