#include <windows.h>
#include <GL/glut.h>
#include <math.h>



void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.780, 0.0234, 0.0234);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-500, 500, -500, 500, -1, 1);
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_LINES);
    glColor3f(0.0770, 0.790, 0.0395);
    glVertex2f(-300.0f, 200.0f); // top left
    glVertex2f(300.0f, 200.0f); // top right 
    glVertex2f(300.0f, 200.0f); // top right
    glVertex2f(300.0f, -200.0f); // bottom right
    glVertex2f(300.0f, -200.0f); // bottom right
    glVertex2f(-300.0f, -200.0f); // bottom left
    glVertex2f(-300.0f, -200.0f); // bottom left
    glVertex2f(-300.0f, 200.0f); // top left
    glEnd();

    drawCircle(0, 0, 150, 500);
    

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("FLAG");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 500);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}