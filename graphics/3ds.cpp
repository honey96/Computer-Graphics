#include <GL/glut.h> 
#include <unistd.h>
#include <bits/stdc++.h>


#include <iostream>
using namespace std;

float angle=0.0,a=0.0,b=0.0,c=0.0;
float i=1.0,j=0.0,k=-8.0;


void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
//  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
glEnable(GL_CULL_FACE);    
glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();
             
   
   glTranslatef(i, j, k);
   glRotatef(angle, a, b, c);  
   /*glRotatef(0.0, 1.0f, 1.0f, 1.0f);  */
 
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      
glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);


glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
   glEnd();
   glFlush();  // End of drawing color-cube
   glutSwapBuffers();

}
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
void keys(int key,int x,int y)
{
  if(key == GLUT_KEY_UP){
    
    a=1;
    angle+=1.0;
    glutPostRedisplay();

  }
  else if(key == GLUT_KEY_LEFT){
    
    
b=1;
    angle-=1.0;
    
    glutPostRedisplay();
  }
    else if(key == GLUT_KEY_RIGHT){

      angle+=1.0;
      if(b==1){
        c=1;
      }
    
    glutPostRedisplay();

    }
      else if(key == GLUT_KEY_DOWN){
        angle-=1.0;
    
    glutPostRedisplay();
      }


}

void keypressed(unsigned char key,int x,int y)
{
  
  switch(key)
  {
  
    case 97:

    i-=0.1;
    glutPostRedisplay();
    break;

    case 100:
    i+=0.1;
    glutPostRedisplay();
    break;

    case 115:
    j-=0.1;
    glutPostRedisplay();
    break;

    case 119:
    j+=0.1;
    glutPostRedisplay();
    break;


 case 27:
  
      glutDestroyWindow(glutGetWindow());
  break;
     glFlush(); 
  }

}
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("title");
glEnable(GL_DEPTH_TEST);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutSpecialFunc(keys);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc(keypressed);
   initGL();                       // Our own OpenGL initialization
   //glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}