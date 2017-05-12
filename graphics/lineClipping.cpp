#include <GL/freeglut.h>
#include <iostream>
using namespace std;

float xa,xb,ya,yb,dx,dy,u1,u2;
int count =0;
int hh;

void display(){
	float temp;
glClear(GL_COLOR_BUFFER_BIT);	
	glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,700, 0,700);
  
  glColor3f(1,0,0);

  glBegin(GL_LINE_LOOP);
  glVertex2i(200,200);
  glVertex2i(550,200);
  glVertex2i(550,550);
  glVertex2i(200,550);
  glEnd();
  

if(hh==1){

  glColor3f(1,1,0);

    glBegin(GL_LINES);
 	
 	glVertex2i(xa,ya);
 	glVertex2i(xb,yb);
  	
  	glEnd();
  	
}

  glFlush();
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



void mouse(int button,int state,int x,int y){
	
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(count==0)
        {	hh=0;
        	count++; 
         xa=x;
         ya=700-y;
         cout<<"xa="<<xa<<" "<<"ya="<<ya <<"\n";
         }
	else if(count==1)
	{count++; 
		float temp;
         xb=x;

         yb=700-y;
         cout<<"xb="<<xb<<" "<<"yb="<<yb <<"\n";
         if(xa>xb){
		    temp = xa;
		    xa=xb;
		    xb=temp;
		    temp=ya;
		    ya=yb;
		    yb=temp;
		  }
         //==============================================
		u1=0.0;u2=1.0;
         dx=xb-xa;
         dy=yb-ya;
         if(ClipTest(-dx,xa-200.0)){
         	if(ClipTest(dx,550.0-xa)){
         	
         	if(ClipTest(-dy,ya-200.0)){
         		if(ClipTest(dy,550.0-ya)){
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
         hh=1;
         //==============================================
	glutPostRedisplay();
        }
	else if(count==2 )
	{count=0; 
	
	 hh=0;
	 glutPostRedisplay();
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