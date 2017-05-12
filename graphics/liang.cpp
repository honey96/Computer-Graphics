#include<stdio.h>
#include<string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>
double xmin=50, ymin=50, xmax=100,ymax=100; 
double xvmin=200,yvmin=200,xvmax=300, yvmax=300; 
int cliptest(double p,double q,double *t1,double *t2)
{ 
   double t=q/p;
    if(p<0.0)        //i am updating enter location here
    {    if(t>*t1) *t1=t;
        if(t>*t2) return(0); //line portion is outside 
    }
    else if(p>0.0) //potentially leaving point ,update leaving
        {
        if(t<*t2) *t2=t;
            if(t<*t1) return(0); //line portion is outside
        }
        else if(p==0.0)
            { if(q<0.0)
                 return(0);//line parallel to edge but outside
            }
            return(1);
}
void liang(double x0,double y0,double x1,double y1)
{
    double dx= x1-x0,dy=y1-y0, enter=0.0,leaving=1.0;


    if(cliptest(-dx,x0-xmin,&enter,&leaving))
    if(cliptest(dx,xmax-x0,&enter,&leaving))
    if(cliptest(-dy,y0-ymin,&enter,&leaving))
    if(cliptest(dy,ymax-y0,&enter,&leaving))
    {
        if(leaving<1.0)
        {
            x1=x0+leaving*dx;
            y1=y0+leaving*dy;
        }
        if(enter>0.0)
        {
            x0=x0+enter*dx;
            y0=y0+enter*dy;
        }
    }
    //window to viewport mappings
    double sx= (xvmax-xvmin)/(xmax-xmin);// scale parameters
            double sy= (yvmax-yvmin)/(ymax-ymin);
            double vx0= xvmin+(x0-xmin)*sx;
            double vy0= yvmin+(y0-ymin)*sy;
            double vx1= xvmin+(x1-xmin)*sx;
            double vy1= yvmin+(y1-ymin)*sy;

        glColor3f(1.0,0.0,0.0);  //draw a red colored viewport
        glBegin(GL_LINE_LOOP);
         glVertex2f(xvmin,yvmin);
         glVertex2f(xvmax,yvmin);
         glVertex2f(xvmax,yvmax);
         glVertex2f(xvmin,yvmax);
        glEnd();
        glColor3f(0.0,0.0,1.0);  
        glBegin(GL_LINES);
         glVertex2d(vx0,vy0);
         
   glVertex2f(vx1,vy1);
        glEnd();

}
void display()
{
    //double x0=60,y0=80,x1=200,y1=100;
    double x0=30,y0=50,x1=100,y1=80;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,1.0);       
    glBegin(GL_LINES);
     glVertex2d(x0,y0);
     glVertex2d(x1,y1);
    glEnd();
    glColor3f(0.0,0.0,1.0);   
    glBegin(GL_LINE_LOOP);
     glVertex2f(xmin,ymin);
     glVertex2f(xmax,ymin);
     glVertex2f(xmax,ymax);
     glVertex2f(xmin,ymax);
    glEnd();
    liang(x0,y0,x1,y1);
    glFlush();
}
void myinit()
{   glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Liang barsky");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
