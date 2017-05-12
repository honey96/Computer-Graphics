#include <GL/glut.h> 
#include<GL/freeglut.h>
#include<math.h>
#include<stdio.h>
int n,flag,screen,xc1,yc1;
char t;
void display();
void display1();
void getInput()
{
glClearColor(0,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRasterPos2f(-0.75,-0.65);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"enter the value of tx and ty  ");
 glFlush();	
 printf("Enter tx: ");
 scanf("%d", &xc1); 
 printf("Enter ty: ");
 scanf("%d",&yc1); 
}

void keypress(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 116:
	getInput();
	glutDisplayFunc(display1);
	glutPostRedisplay();	
	
   break;
	default:
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"invalid output");
glFlush();
}
}
void menu()
{
glClearColor(0,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glRasterPos2f(-8.5,0.75);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"press t for translation\t R for rotation\t re for reflection \t S for scaling\t Sh for shearing");
glEnd();
glFlush();
}
/*void display()
{
glClearColor(0,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glRasterPos2f(-0.75,-0.65);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"enter  ");
glutPostRedisplay();
glutDisplayFunc(display1);
glFlush();
}
*/
void display1()
{
glClearColor(0,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(n==3)
{
glBegin(GL_TRIANGLES);
glVertex2f( -0.5, -0.5);
glVertex2f(0.5, -0.5);     
glVertex2f(0 ,1);
glEnd();
}
glFlush();
}

void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-9,9,-9,9);
}

int main(int argc,char** argv)
{
 printf("enter the no of coordinates\n");
 scanf("%d",&n);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(800,700);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Transformation");
 myinit();
 glutDisplayFunc(menu);
glutKeyboardFunc(keypress);
//glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
