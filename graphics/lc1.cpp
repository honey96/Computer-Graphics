#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include<stdlib.h>

float h=540,w=720;
float xa,xb,ya,yb;
int count=0;
int a,b,c,d;

void init() {
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w, 0, h);
}


void lianbask(float x1,float x2,float y1,float y2){
	float p[4],q[4],r[4],u1[4],u2[4],t1,t2;
	float xn1=0,xn2=0,yn1=0,yn2=0,temp=0.0;;
	p[1]=x1-x2;	q[1]=x1-60;	
	p[2]=x2-x1;	q[2]=180-x1;
	p[3]=y1-y2;	q[3]=y1-300;
	p[4]=y2-y1;	q[4]=420-y1;
	u1[0]=0;	u2[0]=1;
	for(int i=1;i<5;i++){
		r[i]=(q[i]/p[i]);
		u1[i]=0;
		u2[i]=1;
	}
	for(int i=1;i<5;i++){
		if(p[i]<0){
			u1[i]=r[i];
		}
		else if(p[i]>0){
			u2[i]=r[i];
		}
	}
	for(int i=1;i<5;i++){
		if(u1[i]>temp){
			temp=u1[i];}
	}
	t1=temp;
	temp=1.0;
	for(int i=1;i<5;i++){
		if(u2[i]<temp){
			temp=u2[i];}
	}
	t2=temp;
	if(t2>t1){
		xn1=x1+(t1*p[2]);
		xn2=x1+(t2*p[2]);
		yn1=y1+(t1*p[4]);
		yn2=y1+(t2*p[4]);
	}
	glBegin(GL_LINE_LOOP);
	glColor4f(0,1,0,1);
		glVertex2f(xn1,yn1);
		glVertex2f(xn2,yn2);
	glEnd();
	glFlush();			
}

void display(){


	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1,0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(60,h-120);
	glVertex2f(180,h-120);
	glVertex2f(180,h-240);
	glVertex2f(60,h-240);
	glEnd();
	a=rand() % 640;
	b=rand() % 540;
	c=rand() % 640;
/*
	d=rand() % 540;
*/
	glColor4f(1,0,0,1);
	glBegin(GL_LINES);
	glVertex2f(a,b);
	glVertex2f(c,d);
	glEnd();
	lianbask(a,b,c,d);
	glFlush();
			
}

void onMouseClick(int button, int state, int x, int y){

	
	/*line();
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN && count==0){
			xa=x;
			ya=h-y;
		count=1;
		}
	else if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN && count==1){
			xb=x;
			yb=h-y;
		count=0;
	}
	if(xa!=0 && xb!=0 && ya!=0 && yb!=0 && count==0){

	lianbask(xa,xb,ya,yb);}*/
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutCreateWindow("Line clipping");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
