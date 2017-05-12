#include<stdio.h>
#include<GL/freeglut.h>
#include<math.h>
#define GAP  25
float main_window_x;
float main_window_y;
float main_window_w = 256 + GAP * 2;
float main_window_h = 256 + 64 + GAP * 3;
char *window_title = "SubWindow Template";
int main_window;
void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,640,0,480);
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
//glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
//centerOnScreen();
//glutInitWindowSize();
glutInitWindowSize (main_window_w, main_window_h);  
glutInitWindowPosition (main_window_x, main_window_y);  
glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);  
main_window = glutCreateWindow (window_title);
/*glutCreateWindow(circlesandellipses);
int main_window = glutCreateWindow ();*/
myinit();
//glutDisplayFunc(show);
glutMainLoop();
return 0;
}

