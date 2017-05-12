#include <GL/freeglut.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int hh =0,h1=0,h2=0,h3=0;

int xx,yy;
int main_window,subwindow_1,subwindow_2,subwindow_3,subwindow_4;

int main_w=500,main_h=500;


void display(){
	glClearColor(1,0,1,0);
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glFlush();
}

 
void init()
{
 
 glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,main_w,0,main_h);
}

void myinit1()
{
glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,main_w/2,0,main_h/2);
}

int xc,yc;
void displayOne(){
	 glClearColor(1,1,0,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	 
	 glColor3f(1,0,0);
	 float angle,tmpX,tmpY;
	double radius=50;

	if(hh==0)	{
		glColor3f(1,0,0);
		glRasterPos2f(20, 125);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)"Click to draw Circle\nWith polar method");
	}

	if(hh==1){
	glBegin(GL_TRIANGLE_FAN);

	glVertex2i(xc,yc);	 
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = xc+cos(angle)*radius;
	    tmpY = yc+sin(angle)*radius;
	    glVertex2i(tmpX,tmpY);
	} 

	glEnd();}
	
	glFlush();
	 
}

int xcenter,ycenter;
void displayTwo(){
	glClearColor(0,1,0,1); 

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 int r =50;
  int x=0,y=r;
  int p = 1 - r;    

  glColor3f( 1 ,0.4, 0); 


if(h1==0)	{
		glColor3f(1,0,0);
		glRasterPos2f(20, 125);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)"Click to draw Circle\nWith midPoint method");
	}

if(h1==1){
  glBegin(GL_TRIANGLE_STRIP);
  while(x<=y){

    glVertex2i(xcenter+x,ycenter+y);
    glVertex2i(xcenter+y,ycenter+x);  
    glVertex2i(xcenter-x,ycenter+y);
    glVertex2i(xcenter+y,ycenter-x);
    glVertex2i(xcenter-x,ycenter-y);
    glVertex2i(xcenter-y,ycenter-x);
    glVertex2i(xcenter+x,ycenter-y);
    glVertex2i(xcenter-y,ycenter+x);

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


int xxc,yyc;
void displayThree(){
		glClearColor(0,1,1,1); 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 if(h2==0)	{
		glColor3f(1,0,0);
		glRasterPos2f(20, 125);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)"Click to draw Ellipse\nWith polar method");
	}

	 glColor3f(1,0.7,1); 
	 float angle,tmpX,tmpY;
	double radius=50;

	if(h2==1){
	glBegin(GL_POLYGON);
	glVertex2i(xxc,yyc);	 

	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = xxc+cos(angle)*radius;
	    tmpY = yyc-0.5*sin(angle)*radius;
	    glVertex2i(tmpX,tmpY);
	} 
	 
glEnd();}
	 glFlush();	
}



void displayFour(){
	glClearColor(1,1,1,1); 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 if(h3==0)	{
		glColor3f(1,0,0);
		glRasterPos2f(20, 125);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)"Click to draw Ellipse\nWith midpoint method");
	}

	 glClearColor(0,1,1,1);

 		if(h3==1){
        
 			float rx=50, ry=30;
        float rxSq = rx * rx;
        float rySq = ry * ry;
        float x = 0, y = ry, p;
        float px = 0, py = 2 * rxSq * y;

		  glColor3f( 1 ,0, 0);

         glBegin(GL_POLYGON);       
          
         glVertex2d(xx+x,yy-y);
          glVertex2d(xx-x,yy-y);
          glVertex2d(xx-x,yy+y);
         

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
                         glVertex2d(xx+x,yy+y);
                          glVertex2d(xx+x,yy-y);
                          glVertex2d(xx-x,yy-y);
                          glVertex2d(xx-x,yy+y);
                         
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
        
               glVertex2d(xx+x,yy+y);
          glVertex2d(xx+x,yy-y);
          glVertex2d(xx-x,yy-y);
          glVertex2d(xx-x,yy+y);
         glEnd();
         
        }
        

	 }


	 glFlush();	

}

void mouse1(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		hh=1;
		xc=x;yc=250-y;
	/*	glutPostRedisplay();*/
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		hh=0;
	/*	glutPostRedisplay();*/
	}
}

void mouse2(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		h1=1;
		xcenter = x;
		ycenter = 250-y;
	/*	glutPostRedisplay();*/
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		h1=0;
	/*	glutPostRedisplay();*/
	}
}

void mouse3(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		h2=1;
		xxc=x;
		yyc=250-y;
	/*	glutPostRedisplay();*/
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		h2=0;
	/*	glutPostRedisplay();*/
	}

}


void mouse4(int button,int state,int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		h3=1;
		xx=x;
		yy=250-y;
	/*	glutPostRedisplay();*/
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		h3=0;
	/*	glutPostRedisplay();*/
	}

}




void resize(int w,int h){


	main_h = h;
	main_w = w;


	glutSetWindow(main_window);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,main_w,0,main_h);
	glutReshapeWindow(main_w,main_h);
	
	/*glutPostRedisplay();*/
	
	glutSetWindow(subwindow_1);
	myinit1();
	glutReshapeWindow((main_w/2),(main_h/2));
	glutPositionWindow(0,0);
	
	/*glutPostRedisplay();*/


	glutSetWindow(subwindow_2);
	myinit1();
	glutReshapeWindow((main_w/2),(main_h/2));
	glutPositionWindow(main_w/2,0);
	
/*	glutPostRedisplay();*/


	glutSetWindow(subwindow_3);
	myinit1();
	glutReshapeWindow((main_w/2),(main_h/2));
	glutPositionWindow(0,main_h/2);
/*	glutPostRedisplay();*/

	glutSetWindow(subwindow_4);
	myinit1();
	glutPositionWindow(main_w/2,main_h/2);
	glutReshapeWindow((main_w/2),(main_h/2));
/*	glutPostRedisplay();*/

}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);

 main_window= glutCreateWindow("SubWindows");
 init();
 glutDisplayFunc(display);
 glutReshapeFunc(resize);


 subwindow_1 = glutCreateSubWindow (main_window, 0, 0, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayOne);
 glutMouseFunc(mouse1);


 subwindow_2 = glutCreateSubWindow (main_window, 250, 0, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayTwo);
 glutMouseFunc(mouse2);


 subwindow_3 = glutCreateSubWindow (main_window, 0, 250, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayThree);
 glutMouseFunc(mouse3);


 subwindow_4 = glutCreateSubWindow (main_window, 250, 250, 250, 
    250);
  myinit1();
 glutDisplayFunc(displayFour);
 glutMouseFunc(mouse4);
 


 glutMainLoop();
 return 0;
}
