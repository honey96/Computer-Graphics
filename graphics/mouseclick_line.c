#include <GL/glut.h>
#include<stdio.h>  
#include<GL/freeglut.h>
  int win_width,win_height;  
  int flag=0;  
  int xa,ya,xb,yb;  
  void drawLine(int xa,int ya,int xb,int yb)  
  {  
       glClear(GL_COLOR_BUFFER_BIT);  
       glLineWidth(3.0);  
       glBegin(GL_LINES);  
       glVertex2i(xa,ya);  
       glVertex2i(xb,yb); 
       glColor3f(1, 0, 0);
       glRasterPos2f(200,300);
       glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"Harshit,    R110214030,   500039661"); 
       glEnd();  
       glFlush();  
  }  
  void display()  
  {  
       glClearColor(0.2, 0.4, 0.0, 1.0);  
       glColor3f(1, 0, 0);  
       glClear(GL_COLOR_BUFFER_BIT);  
       /*glRasterPos2f(200,300);
       glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"Harshit,    R110214030,   500039661");*/
       glFlush();  
  }  
  void mouse(int btn,int state,int x,int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {  
            switch(flag)  
            {  
            case 0:  
                 xa=x;  
                 ya=win_height-y;  
                 flag=1;  
                 break;  
            case 1:  
                 xb=x;  
                 yb=win_height-y;  
                 drawLine(xa,ya,xb,yb);  
                 flag=0;  
	         break;  
            }  
       }  
  }  
  void myinit() 
  {  
       glViewport(0,0,win_width,win_height);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0.0,(GLdouble)win_width,0.0,(GLdouble)win_height);  
       glMatrixMode(GL_MODELVIEW);  
  }  
  int main(int argc,char** argv)  
	{  
	printf("enter the size of window: window height || window width");
	scanf("%d %d",&win_height,&win_width);
        glutInit(&argc,argv);  
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
        glutInitWindowSize(win_width,win_height);  
        glutCreateWindow("Draw Line With Mouse Click");  
        glutDisplayFunc(display);  
        myinit();  
        glutMouseFunc(mouse);  
        glutMainLoop(); 
        return 0;  
  }  

