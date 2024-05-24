#include <windows.h>
#include <GL/glut.h>
#include <math.h>


float p = -10.0; // Display Measurement with ortho starting from the left -10 and right 10 

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (p <= 10) //moving limit with the display measurement 
        p = p + .005; // changing the object position for redisplaying 

    else
        p = -10; // For backing the object continuously 

    glutPostRedisplay(); // To redraw the object in the display 


    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p, 3);       // To draw the object position from the left limit,p 
    glVertex2f(p + 3, 3);
    glVertex2f(p + 3, -3);
    glVertex2f(p, -3);
    glEnd();

    /*
     glBegin(GL_QUADS);
     glColor3f(1.0,1.0,0);
     glVertex2f(-2,3);
     glVertex2f(1,3);
     glVertex2f(1,-3);
     glVertex2f(-2,-3);
     glEnd();
     */





    glFlush();
}
void init(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0); // Background Color 
    glOrtho(-10, 10, -10, 10, -10, 10); // To specify the coordinate & Specify the distances to the nearer and farther depth clipping planes. 

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT and process any command line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Specify display mode
    glutInitWindowSize(600, 600); // Set initial window size
    glutInitWindowPosition(100, 100); // Set initial window position
    glutCreateWindow("moving_object"); // Create window with a title

    init(); // Initialize OpenGL settings (background color, projection)

    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop(); // Enter the event processing loop

    return 0;
}