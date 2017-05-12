#include<stdio.h>
#include<GL/freeglut.h>
#include<math.h>
int xa,ya,xb,yb;
void show()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
double x=xa ,y=ya,m;
m=(double)(yb-ya)/(double)(xb-xa);	
glColor3f(0,1,0);
glBegin(GL_POINTS);
if((m>0)&&(m<=1))
{
    while((x<xb)&&(y<yb))
	{
	glVertex2i(x,y);
	x=x+1;
	y=y+m;
	}
}

else if(m>1)
{
   while((x<xb)&&(y<yb))
	{
	glVertex2i(x,y);
	y=y+1;
	x=x+1/m;
	}
}
else if((m<=0)&&(m>-1))
{
   while((x<xb)&&(y<yb))
	{
	glVertex2i(x,y);
	x=x-1;
	y=y-m;
	}
}
else if(m<-1)
{
   while((x<xb)&&(y<yb))
	{
	glVertex2i(x,y);
	y=y-1;
	x=x-1/m;
	}
}
glEnd();
glColor3f(1,0,0);
glRasterPos2f(-0.65,-0.85);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"Harshit,    R110214030,   500039661");
glFlush();
}
void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,640,0,480);
}

int main(int argc,char **argv)
{
printf("enter the initial coordinates of the line");
scanf("%d %d",&xa,&ya);
printf("enter the end coordinates of the line");
scanf("%d %d",&xb,&yb); 
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(200,200);
glutCreateWindow("line");
myinit();
glutDisplayFunc(show);
glutMainLoop();
return 0;
}

