#include <GL/freeglut.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void displayOne(float x,float y);
int flag=0,flag1=0,flag2=0,flag3=0;
/*void mouse(int x,int y)  
  {  
      displayOne(float x,float y);
  }
*/  
void display(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glFlush();
}

void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,500,0,500);
}
void myinit1()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,250,0,250);
}
float xCenter,yCenter,xc,yc;
void displayOne(){
glClearColor(1,1,0,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 //float x,y;
	// x=y=100;
	 float angle,tmpX,tmpY;
	double radius=50;
	if(flag==1){
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(xCenter,yCenter);	 
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = xCenter+cos(angle)*radius;
	    tmpY = yCenter+sin(angle)*radius;
	    glVertex2i(tmpX,tmpY);
	} 

	glEnd();
}
	glFlush();
	 
}
void displayTwo(){
	glClearColor(0,1,0,1); 

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int r=50;
	 //int xCenter=100,yCenter=100,r=50;
  int x=0,y=r;
  int p = 1 - r;    
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0.4, 0); 

	if(flag1==1)
{
  glBegin(GL_TRIANGLE_STRIP);
  while(x<=y){

    glVertex2i(xCenter+x,yCenter+y);
    glVertex2i(xCenter+y,yCenter+x);  
    glVertex2i(xCenter-x,yCenter+y);
    glVertex2i(xCenter+y,yCenter-x);
    glVertex2i(xCenter-x,yCenter-y);
    glVertex2i(xCenter-y,yCenter-x);
    glVertex2i(xCenter+x,yCenter-y);
    glVertex2i(xCenter-y,yCenter+x);

    if (p<0)
  p += (2*x)+3;
    else {
 p += (2*(x-y))+5;
 y -= 1;
    }
    x++;
  }
	  
  glEnd();

}
	 glFlush();	
}
void displayThree(){
		glClearColor(0,1,1,1); 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glColor3f(1,0.7,1); 
	// float x,y;
	 //x=y=100;
	 float angle,tmpX,tmpY;
	double radius=50;
	if(flag2==1)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(xCenter,yCenter);	 
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = xCenter+cos(angle)*radius;
	    tmpY = yCenter-0.5*sin(angle)*radius;
	    glVertex2i(tmpX,tmpY);
	} 
	 
glEnd();
}
	 glFlush();	
}
void displayFour(){
	glClearColor(1,1,1,1); 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(flag3==1)
{	
   float rx=50, ry=30;
        float rxSq = rx * rx;
        float rySq = ry * ry;
        float x = 0, y = ry, p;
        float px = 0, py = 2 * rxSq * y;
        glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);
         glBegin(GL_POLYGON); 
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
        

        p = rySq - (rxSq * ry) + (0.25 * rxSq);
        while (px < py)
        {
                        x++;
                        px = px + 2 * rySq;
                        if (p < 0)
                        p = p + rySq + px;
                        else
                        {
                        y--;
                        py = py - 2 * rxSq;
                        p = p + rySq + px - py;
                        }
                         glBegin(GL_POLYGON);

                          glVertex2d(xc+x,yc+y);
                          glVertex2d(xc+x,yc-y);
                          glVertex2d(xc-x,yc-y);
                          glVertex2d(xc-x,yc+y);
                         

        }

        p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
        while (y > 0)
        {
                y--;
                py = py - 2 * rxSq;
                if (p > 0)
                p = p + rxSq - py;
                else
                {
                x++;
                px = px + 2 * rySq;
                p = p + rxSq - py + px;
                }
               glBegin(GL_POLYGON);

          glVertex2d(xc+x,yc+y);
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
         glEnd();
}
}

         glFlush();
        
        }

 void mouse(int btn,int state,int x,int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {   flag=1;
     	          xCenter=x;  
                 yCenter=250-y;  
                 glutPostRedisplay();  
       }  
  }  
void mouse1(int btn,int state,int x,int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {   flag1=1;
     	          xCenter=x;  
                 yCenter=250-y;  
                 glutPostRedisplay();  
       }  
  }  
void mouse2(int btn,int state,int x,int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {   flag2=1;
     	          xCenter=x;  
                 yCenter=250-y;  
                 glutPostRedisplay();  
       }  
  }  
void mouse3(int btn,int state,int x,int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {   flag3=1;
     	          xc=x;  
                 yc=250-y;  
                 glutPostRedisplay();  
       }  
  }  
/*void changeSize(int w, int h) {

	if (h == 0)
	h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);
}*/

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 int main_window = glutCreateWindow("SubWindows");
 myinit();
 glutDisplayFunc(display);
 int subwindow_1 = glutCreateSubWindow (main_window, 0, 0, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayOne);
glutMouseFunc(mouse);
//glutReshapeFunc(changeSize); 
 int subwindow_2 = glutCreateSubWindow (main_window, 250, 0, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayTwo);
glutMouseFunc(mouse1);
 int subwindow_3 = glutCreateSubWindow (main_window, 0, 250, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayThree);
glutMouseFunc(mouse2);
 int subwindow_4 = glutCreateSubWindow (main_window, 250, 250, 250, 
    250);
  myinit1();
//glutMouseFunc(mouse3);
 glutDisplayFunc(displayFour);
glutMouseFunc(mouse3);
 glutMainLoop();
 return 0;
}
