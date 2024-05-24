#include <GLUT/glut.h>

int r, x = 0, y, Pk;
void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    r = 800;
    y = r;
    Pk = 1 - r;
    

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    while (x <= y) {
        glVertex2i(x, y);

        if (Pk < 0) {
            Pk = Pk + (2 * x + 1);
        } else {
            y = y - 1;
            Pk = Pk + (2 * x) + 1 - (2 * y);
        }
        x++;
        
        glVertex2i(x, y);
        glVertex2i(y, x);
        glVertex2i(x, -y);
        glVertex2i(y, -x);
        glVertex2i(-x, -y);
        glVertex2i(-y, -x);
        glVertex2i(-x, y);
        glVertex2i(-y, x);
        
        
    }
    glEnd();
    glFlush();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000, 1000, -1000, 1000);
    Draw();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Mid point circle");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}