#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
int screen=0;
int type=0;
int onMouse=0;

void mouseClicks(int,int,int,int);

void display()
{   
     
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(150,450);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Press B for Bresenhan and D for DDA algorithm");
 glFlush();
}


void display_ddao()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(150,450);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Press I for console input and M for mouse input for DDA algorithm");
 glFlush();
}

void display_breso()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glColor3f(1,1,1);
 glRasterPos2i(150,450);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Press I for console input and M for mouse input for Bresenham algorithm");
 glFlush();
}

int xc1,yc1,xc2,yc2;

void getInput()
{
 glRasterPos2i(250,350);
 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Input Coordinates");
 glFlush();	
 printf("Enter coordinate 1: ");
 scanf("%d %d",&xc1,&yc1); 
 printf("Enter coordinate 2: ");
 scanf("%d %d",&xc2,&yc2); 
}


void dda()
{
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  float m;
  float x,y;
  m=(float)(yc2-yc1)/(float)(xc2-xc1);
  glColor3f(0,1,0); 
  glBegin(GL_POINTS);
  if(m>0 && m<=1)
 {
   x=(xc1<xc2)?xc1:xc2;
   y=(x==xc1)?yc1:yc2;
   while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    x+=1;
    y=y+m;
   }
}
  else if(m>1)
 {
   x=(xc1<xc2)?xc1:xc2;
   y=(x==xc1)?yc1:yc2;
  while((y<=yc2 && y>=yc1) || (y>=yc2 && y<=yc1))
   {
    glVertex2i(x,y);
    y+=1;
    x=x+1/m;
   }
}
  else if(m<=0.0 && m>-1)
  {
   x=(xc1>xc2)?xc1:xc2;
   y=(x==xc1)?yc1:yc2;
  while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    x-=1;
    y=y-m;
   }
 }
  else if(m<-1)
 {
   y=(yc1>yc2)?yc1:yc2;
   x=(y==yc1)?xc1:xc2; 
 
  while((y<=yc2 && y>=yc1) || (y>=yc2 && y<=yc1))
   {
    glVertex2i(x,y);
    y-=1;
    x=x-1/m;
   }
 }
  glEnd();
  glFlush();

}


void  bres()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_POINTS);
  int x=(xc1>xc2)?xc2:xc1;
  int y=(x==xc1?yc1:yc2); 
  int xg=(xc1<xc2)?xc2:xc1;
  int yg=(xg==xc1?yc1:yc2);
  if(x==xg)
  	{
  	  if(yc1<yc2)
  	  {y=yc1;
  	   yg=yc2;}
  	   else
  	   {y=yc2;
  	   yg=yc1;} 
  	}
  int dx=xg-x;
  int dy=yg-y;
  float m=0.0;
  if (dx!=0)
  m=(float)dy/dx;
  dy=abs(dy);
  dx=abs(dx);
  int p=2*dy-dx;
  printf("%d %d\n",yg,y );
  if(dx==0)
  while(y<=yg)
   {
     glVertex2i(x,y);
     y++;
   }

else if(m<=1 && m>=0)
  while(x<=xg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y++;
       p=p+2*dy-2*dx;}
     else if(p<0)
	{x++;
	 p=p+2*dy;}
   }

else if(m>1)
 while(y<=yg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y++;
       p=p+2*dx-2*dy;}
     else if(p<0)
	{y++;
	 p=p+2*dx;}
   }
else if(m<0 && m>=-1)
 while(x<=xg)
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y--;
       p=p+2*dy-2*dx;}
     else if(p<0)
	{x++;
	 p=p+2*dy;}
   }
else if(m<-1 )
 while(x<=xg )
   {
     glVertex2i(x,y);
     if(p>=0)
      {x++;
       y--;
       p=p+2*dx-2*dy;}
     else if(p<0)
	{y--;
	 p=p+2*dx;}
   }


 glEnd();
 glFlush();
}

void keypress(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 100:
	glutDisplayFunc(display_ddao);
	glutPostRedisplay();
        screen++; 
        type=0;
   break;
   case 98:
	glutDisplayFunc(display_breso);
	glutPostRedisplay();
        screen++;
        type=1;   
  break;  
  case 105:
	if(type==0 && screen==1)
	 { 

	   getInput();
       glutDisplayFunc(dda);
	   glutPostRedisplay();
	   screen=2; }

         else if(type==1 && screen==1)
	 { getInput();
           glutDisplayFunc(bres);
	   glutPostRedisplay();
	   screen=2; }
 break;
 case 109:
	if(type==0 && screen==1)
	 { 
	 	xc1=0;
	 	xc2=0;
	 	yc1=0;
	 	yc2=0;
	 	onMouse=0;
	   glutMouseFunc(mouseClicks);
           glutDisplayFunc(dda);
	   glutPostRedisplay();
	   screen=2; }
       
       else if(type==1 && screen==1)
	 { 
	 	xc1=0;
	 	xc2=0;
	 	yc1=0;
	 	yc2=0;
	 	onMouse=0;
	 	glutMouseFunc(mouseClicks);
           glutDisplayFunc(bres);
	   glutPostRedisplay();
	   screen=2; }
 break;
	
 case 27:
 	if(type==0 && screen==2)
 	{glutDisplayFunc(display_ddao);
	 glutPostRedisplay();
     screen--;
    }
    else if(type==1 && screen==2)
 	{glutDisplayFunc(display_breso);
	 glutPostRedisplay();
     screen--;
    }
    else if(screen==1)
 	{glutDisplayFunc(display);
	 glutPostRedisplay();
     screen--;
    }
    else if(screen==0)
    {
    	glutDestroyWindow(glutGetWindow());
    }
  break;
  default:
  		 glRasterPos2i(150,350);
		 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Invalid Input");
		 glFlush();	
  }

}



void mouseClicks(int button, int state, int x, int y) {

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(onMouse==0)
        {onMouse++; 
         xc1=x;
         yc1=700-y;
         }
	else if(onMouse==1)
	{onMouse++; 
         xc2=x;
         yc2=700-y;
	glutPostRedisplay();
        }
	else if(onMouse==2)
	{onMouse=0; 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glFlush();
        }	
       
    }
}



void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,800,0,700);
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(800,700);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Bresenhan line");
 myinit();
 glutDisplayFunc(display);
 glutKeyboardFunc(keypress);
 glutMainLoop();
 return 0;
}
