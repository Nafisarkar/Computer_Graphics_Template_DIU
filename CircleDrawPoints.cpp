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
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();  
  glOrtho(-100, 100, -100, 100, -1.0, 1.0);  
}



void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,0, 0);
  glPushMatrix();
   circle(60,50,0,0);
   glRectf(-25,-25,25,25);
glPopMatrix();



glutSwapBuffers();
}


void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            ty=ty+5;    
            break;
        case GLUT_KEY_DOWN:
            ty=ty-5;
            break;
        case GLUT_KEY_LEFT:
            tx=tx-5;
            break;
        case GLUT_KEY_RIGHT:
            tx=tx+5;
            break;
    }
    glutPostRedisplay();
}

int main(int argc,char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(500,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}
