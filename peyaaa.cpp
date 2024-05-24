#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;

void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,0, 0);
  glPushMatrix();
   glTranslatef(tx,ty,0);
   glRectf(-25,-25,25,25);
glPopMatrix();


glutSwapBuffers();
}

void specialKeys(int key,int x,int y){
    
    switch(key){
        case GLUT_KEY_UP:
        ty = ty+ 5;
        glutPostRedisplay();
        break;

        case GLUT_KEY_DOWN:
        ty = ty- 5;
        glutPostRedisplay();
        break;


        case GLUT_KEY_LEFT:
        ty = tx+ 5;
        glutPostRedisplay();
        break;

        case GLUT_KEY_RIGHT:
        ty = ty- 5;
        glutPostRedisplay();
        break;

    }
}
void init(void)
{
    glClearColor(0, 0, 0, 0); // Background Color 
    glOrtho(-100, 100, -100,100, -100, 100); // To specify the coordinate & Specify the distances to the nearer and farther depth clipping planes. 

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("tranformation"); 

    init(); 

    glutDisplayFunc(Draw);
    glutSpecialFunc(specialKeys); 
    glutMainLoop();

    return 0;
}    
    
