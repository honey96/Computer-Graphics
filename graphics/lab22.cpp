#include<GL/freeglut.h>
int flag=0;
void mouseActions(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {   
			flag=1;
		glutPostRedisplay();
		}
	
		else {  
		flag=0;
		glutPostRedisplay();
      	
		}
	
}
float square[] ={-5,-5,-5,5,5,5,5,-5,-5,-5};
void display()
{
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
gluOrtho2D(-9,9,-9,9);  
if(flag)
glColor3f(0,1,1);
else
glColor3f(0,0,1);


glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,square);
glDrawArrays(GL_POLYGON,0,5);                 
glDisableClientState(GL_VERTEX_ARRAY);
glColor3f(0,1,1);
glRasterPos2f(-3.35,-5.65);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"Harshit,    R110214030,   500039661");
glFlush();

}

int main(int argc, char** argv) {
glutInit(&argc, argv);            // Initialize GLUT
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(50,50);
glutCreateWindow("Square");
glutDisplayFunc(display);
glutMouseFunc(mouseActions);        
glutMainLoop(); 

return 0;
}
