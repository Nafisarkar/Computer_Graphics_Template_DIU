#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float tx=0,ty=0;
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
   glTranslatef(tx,ty,0);
   glRectf(-25,-25,25,25);
   glColor3f(0.964, 0.980, 0.00);
   glRectf(-15,-15,15,15);
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
