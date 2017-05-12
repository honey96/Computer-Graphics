#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<GL/glu.h>
const int ww=600, wh=600;
int winid;
int xmax, xmin, ymin, ymax,c=0,c1=0;
void display();
void myinit();
void Clip(int, int);
void drawWindow(int, int, int, int);
void mouse(int,int, int,int);
void setPixelSimp(GLint, GLint);
 int main(int argc,char** argv)  
  {  
  		glClear(GL_COLOR_BUFFER_BIT); 
       glutInit(&argc,argv);  
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       winid=glutCreateWindow("clipping");  
       glutDisplayFunc(display);  
       myinit();  
       glutMouseFunc(mouse); 
       glutMainLoop(); 
       return 0;   
}  
void Clip(int x, int y){
	if(x<=xmin||x>=xmax||y<=ymin||y>=ymax){
                     	std::cout<<"outside window\n";
			c++;
     }
     else{ 
     	std::cout<<"inside window\n";
			c1++;
     		glColor3f(0.6, 0.8, 1.0);
         	setPixelSimp(x,y);
         	glFlush();
    }


}
void setPixelSimp(int x,int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
void display()
{ 
	glColor3f(0.0, 0.0, 0.0);
       glClearColor(1.0, 0.0, 1.0, 1.0);  
       glColor3f(1.0, 1.0, 1.0);  
       glClear(GL_COLOR_BUFFER_BIT); 
       drawWindow(glutGet(GLUT_WINDOW_WIDTH)/4,glutGet(GLUT_WINDOW_HEIGHT)/2,3*glutGet(GLUT_WINDOW_WIDTH)/4,glutGet(GLUT_WINDOW_HEIGHT)/4);   

       glFlush();
}
void myinit()  
  {  
       glViewport(0,0,ww,wh);  
       glMatrixMode(GL_PROJECTION); 
       glClearColor(0.0,0.0,0.2,1.0); 
	glPointSize(5.0);
       //glColor3f(1.0, 1.0, 1.0);  
       glLoadIdentity();  
       gluOrtho2D(0.0,(GLdouble)glutGet(GLUT_WINDOW_WIDTH),0.0,(GLdouble)glutGet(GLUT_WINDOW_HEIGHT));  
       glMatrixMode(GL_MODELVIEW);  
  }
  void mouse(int btn,int state,int x,int y)  
  { 
  int xi, yi; 
  	xi=x;
  	yi=wh-y;
       if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {  
       	Clip(xi,yi);  
       } 
       else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
       	glutDestroyWindow(winid);
	std::cout<<"no of outside point in the window is"<<c<<"\n";
	std::cout<<"no of inside point in the window is"<<c1<<"\n"; 
        exit(0);
       }
  } 
  void drawWindow(int x1, int y1, int x2, int y2)  
  {       
  	
  	xmin=x1;
    xmax=x2;
    y1=wh-y1;
    y2=wh-y2;
    ymin=y1;
    ymax=y2;
       glColor3f(0.0,0.0,0.0);  
       glBegin(GL_LINES);  
           glVertex2i(x1, y1);  
            glVertex2i(x1, y2);   
       glEnd(); 
       glBegin(GL_LINES);  
            glVertex2i(x2, y1);  
            glVertex2i(x2, y2);  
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x1, y1);  
            glVertex2i(x2, y1);  
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x1, y2);  
            glVertex2i(x2, y2);  
       glEnd();  
       glFlush();
        
  }
