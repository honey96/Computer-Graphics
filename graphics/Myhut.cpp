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


float f[] = {-3,0,-3,4,-2,6,-1,4,1,4,2,6,3,4,3,0,1,0,1,2,-1,2,-1,0};
float f1[] ={-1,4,-1,2};
float f2[] ={1,4,1,2,-1,0,-1,2,1,0,-1,0,1,2};
float f3[] ={-3,3,-2,3,-2,1,-3,1,-3,3};
float f4[] ={3,3,2,3,2,1,3,1,3,3};
float f5[] ={-3,4,-1,4,1,4,3,4};
float f6[] ={1.75,4.25,2.25,4.25,2.25,5.25,1.75,5.25,1.75,4.25};

void display()
{
glClearColor(0,1,0,0);
glClear(GL_COLOR_BUFFER_BIT ); 
glLoadIdentity(); 
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-9,9,-9,9);  
glColor3f(1,0,0); 

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f); //////////////////////////////Structure of hut 
glDrawArrays(GL_LINE_LOOP,0,12);
glDisableClientState(GL_VERTEX_ARRAY);


glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f1);
glDrawArrays(GL_LINE_LOOP,0,2);                 //Designing of hut
glDisableClientState(GL_VERTEX_ARRAY);


glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f2);               //intersection
glDrawArrays(GL_LINE_LOOP,0,7);
glDisableClientState(GL_VERTEX_ARRAY);



glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f3);               //Left window
glDrawArrays(GL_POLYGON,0,5);
glDisableClientState(GL_VERTEX_ARRAY);


glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f4);               //Right Window
glDrawArrays(GL_POLYGON,0,5);
glDisableClientState(GL_VERTEX_ARRAY);


glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f5);
glDrawArrays(GL_LINE_LOOP,0,4);
glDisableClientState(GL_VERTEX_ARRAY);



glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,f6);             //Top most square
glDrawArrays(GL_POLYGON,0,5);
glDisableClientState(GL_VERTEX_ARRAY);


circle(-2,4.75);                             //circle


glColor3f(1,1,1);
glRasterPos2f(-2.95,-0.65);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"Harshit,    R110214030,   500039661");
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
