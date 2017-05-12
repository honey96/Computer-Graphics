#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
using namespace std;
bool cp3flag = true;
bool cp2flag=true;
bool changeBeginFlag =false ;
struct Point
{
	GLfloat x;
	GLfloat y;
};

Point cp1 = {-250, 0}, cp2 = {-100, -100}, cp3 = {100, 100}, cp4={250, 0}; //the thre control points
typedef struct node
{
	Point point;
	struct node * next;
} node_t;

Point bezier(Point cp1, Point cp2, Point cp3, Point cp4, GLfloat t)
{
	GLfloat x = ((((1-t)*(1-t)*(1-t))*cp1.x)+(3*(1-t)*(1-t)*t*(cp2.x))+(3*(1-t)*t*t*cp3.x)+(t*t*t*cp4.x));
	GLfloat y = ((((1-t)*(1-t)*(1-t))*cp1.y)+(3*(1-t)*(1-t)*t*(cp2.y))+(3*(1-t)*t*t*cp3.y)+(t*t*t*cp4.y));
	Point ptr = {x, y};
	return ptr;
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7f, 0.6f, 0.5f);
	GLfloat i=0;
	glBegin(GL_POINTS);
	for(; i<1.0f; i+=0.004)
	glVertex2f(bezier(cp1, cp2,cp3, cp4, i).x, bezier(cp1, cp2,cp3, cp4, i).y);
	glVertex2f(cp1.x, cp1.y);
	glVertex2f(cp2.x, cp2.y);
	glVertex2f(cp3.x, cp3.y);
	glVertex2f(cp4.x, cp4.y);
	glEnd();
	glFlush();
}

void  mouse(int button, int state, int x, int y)
{
	x -=250; y-=250;
	if(changeBeginFlag)
	{
		if(abs(x-cp2.x)<=6 && abs(y+cp2.y)<=6)
		{
			cp2flag = true;
		}
		else if(abs(x-cp3.x)<=6 && abs(y+cp3.y)<=6)
		{
			cp3flag = true;
		}
		changeBeginFlag = false;
	}

	else if(cp2flag  && state==GLUT_UP)
	{
		cp2 = {x, -y};
		cp2flag = true;
		changeBeginFlag = true;
	}
	else if(cp3flag)
	{
		cp3 = {x, -y};
		cp3flag = true;
		changeBeginFlag = true;
	}
	cout << "\nX: " << x << " Y: " << y <<endl;
	glutPostRedisplay();

}
void init()
{
	glClearColor(0.2f, 0.3f, 0.4f, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250, 250, -250, 250);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier Curve");
	init();
	node_t *head = NULL;
	//head = malloc(sizeof(node_t));
	head=(struct node *)malloc(sizeof( node_t));
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
