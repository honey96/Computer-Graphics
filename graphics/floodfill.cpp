#include <GL/glut.h>
#include <iostream>

#define originalWidth 500
#define originalHeight 500

using namespace std;
bool floodFillFlag = false, boundaryFillflag = false;

 struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
};
struct Point
{
	GLint x;
	GLint y;
};

void putPixel(GLint x, GLint y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//enumerating menu items
enum MenuItems
{
	FLOOD_FILL,
	BOUNDARY_FILL,
	SCANLINE_FILL,
	RESET,
};

MenuItems show = FLOOD_FILL;

Color getPixelColor(GLint x, GLint y)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}


void FloodFill(GLint x, GLint y, Color oldColor, Color newColor )
{
	Color color= getPixelColor(x, y);
	cout << color.r <<" " << oldColor.r <<  endl;
	cout << color.g <<" " << oldColor.g <<  endl;
	cout << color.b <<" " << oldColor.b <<  endl;
	/*if (color.r==oldColor.r && color.g==oldColor.g && color.b==oldColor.b)
	{
		//cout << color.r << color.g << color.b << endl;
		putPixel(x, y, newColor);
		FloodFill(x, y+1, oldColor, newColor);
		FloodFill(x+1, y, oldColor, newColor);
		FloodFill(x-1, y, oldColor, newColor);
		FloodFill(x, y-1, oldColor, newColor);
		FloodFill(x-1, y-1, oldColor, newColor);
		FloodFill(x+1, y-1, oldColor, newColor);
		//FloodFill(x-=1, y+=1);
	}*/
	return;
}

void mouse(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {0.0f, 0.0f, 0.0f};
	if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (floodFillFlag)
		{
			//cout <<x << y<<endl;
			FloodFill(x,(500 - y), oldColor, newColor);
			floodFillFlag = false;
		}
	}
}



//function to handle menu
static void menu (int item)
{
	switch(item)
	{
		case FLOOD_FILL:
		{
			floodFillFlag = true;
			break;
		}
	}

	glutPostRedisplay();
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0f, 0.7f, 1.0f);
	glBegin(GL_POLYGON);
		glVertex2f(100, 100 );
		glVertex2f(-100, 100);
		glVertex2f(-100, -100);
		glVertex2f(100, -100);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(originalWidth, originalHeight);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Canvas");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutCreateMenu(menu);
		glutAddMenuEntry("Flood Fill", FLOOD_FILL);
		glutAddMenuEntry("Boundary Fill", BOUNDARY_FILL);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
