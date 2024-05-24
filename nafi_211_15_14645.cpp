#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>

float tx=0,ty=0;

void circle (GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI=3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0; i<361; i++)
    {
        angle = i*PI/180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void init(void)
{
  glClearColor(1,1,1,0.0);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();  
  glOrtho(-100, 100, -100, 100, -1.0, 1.0);  
}

void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,0, 0);
   circle(20,20,0,0);
   
   glColor3f(0.168, 0.689, 0.990);
   circle(15,15,25,25); //top right
   circle(15,15,25,-25); //bottom right
   circle(15,15,-25,-25); //bottom left
   circle(15,15,-25,25); //top left

    glColor3f(0.135, 0.710, 0.336);
    circle(10,30,0,50); //top
    circle(10,30,0,-50); //bottom
    circle(30,10,50,0); //right
    circle(30,10,-50,0); //left
   glutSwapBuffers();
}


int main(int argc,char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(500,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
