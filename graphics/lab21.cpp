#include <GL/glut.h> 
#include<GL/freeglut.h>
#include <bits/stdc++.h>
void circle(float x,float y)   // to draw the circle
{
	float angle,tmpX,tmpY;
	double radius= 0.5;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);	 
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
	    tmpX = x+cos(angle)*radius;
	    tmpY = y+sin(angle)*radius;
	    glVertex2f(tmpX,tmpY);
	} 
	glEnd();
}
void display()
{
glClearColor(0,1,0,0);
glClear(GL_COLOR_BUFFER_BIT ); 
glLoadIdentity(); 
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-9,9,-9,9);  
glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
/*glVertex2i(50,50);
glVertex2i(50,100);
glVertex2i(100,150);
glVertex2i(150,100);
glVertex2i(150,50);
*/
glVertex2f(-3.0,0.0);
glVertex2f(-3.0,4.0);
glVertex2f(-2.0,6.0);
glVertex2f(-1.0,4.0);
glVertex2f(1.0,4.0);
glVertex2f(2.0,6.0);
glVertex2f(3.0,4.0);
glVertex2f(3.0,0.0);
glVertex2f(1.0,0.0);
glVertex2f(1.0,2.0);
glVertex2f(-1.0,2.0);
glVertex2f(-1.0,0.0);
glEnd();

glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-1.0,4.0);
glVertex2f(-1.0,2.0);
/*glVertex2f(1.0,4.0);
glVertex2f(1.0,2.0);*/
glEnd();

glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(1.0,4.0);
glVertex2f(1.0,2.0);
glVertex2f(-1.0,0.0);
glVertex2f(-1.0,2.0);
glVertex2f(1.0,0.0);
glVertex2f(-1.0,0.0);
glVertex2f(1.0,2.0);
glEnd();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(-3.0,3.0);
glVertex2f(-2.0,3.0);
glVertex2f(-2.0,1.0);
glVertex2f(-3.0,1.0);
glVertex2f(-3.0,3.0);
glEnd();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(3.0,3.0);
glVertex2f(2.0,3.0);
glVertex2f(2.0,1.0);
glVertex2f(3.0,1.0);
glVertex2f(3.0,3.0);
glEnd();
glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-3.0,4.0);
glVertex2f(-1.0,4.0);
glVertex2f(1.0,4.0);
glVertex2f(3.0,4.0);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2f(1.75,4.25);
glVertex2f(2.25,4.25);
glVertex2f(2.25,5.25);
glVertex2f(1.75,5.25);
glVertex2f(1.75,4.25);
glEnd();

circle(-2,4.75);


glEnd();



glFlush();
}


int main(int argc, char** argv) {
glutInit(&argc, argv);            // Initialize GLUT
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(50,50);
glutCreateWindow("HUT");
glutDisplayFunc(display);        
glutMainLoop(); 

return 0;
}
