#include <windows.h>
#include <GL/glut.h>
#include <math.h>


void DrawCircle(int radious, int x, int y, int degree) {
    float theta;
    glBegin(GL_POLYGON);
    glColor3f(0.780, 0.0234, 0.0234);
    for (int i = 0; i < degree; i++) {
        theta = i * 3.1416 / 180;
        glVertex2f(x + radious * cos(theta), y + radious * sin(theta));
    }
    glEnd();
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-500, 500, -500, 500, -1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.0770, 0.790, 0.0395);
    glVertex2f(-300.0f, 200.0f); // top left
    glVertex2f(300.0f, 200.0f); // top right 
    glVertex2f(300.0f, -200.0f); // bottom right
    glVertex2f(-300.0f, -200.0f); // bottom left
    glEnd();

    DrawCircle(140, 0, 0, 360);
    

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