#include <windows.h>
#include <GL/glut.h>
#include <math.h>


void DrawCircle(int radious, int x, int y, int degree) {
    float theta;
    glBegin(GL_POLYGON);
    for (int i = 0; i < degree; i++) {
        theta = i * 3.1416 / 180;
        glVertex2f(x + radious * cos(theta), y + radious * sin(theta));
    }
    glEnd();
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(0, 500, 0, 500, -1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    DrawCircle(100, 250, 250, 180);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Line Strip");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}