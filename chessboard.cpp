#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <windows.h>

void DrawChessBorad() {
    bool Change_Color = false;
    for (int i = 0; i < 8; i++) {
        Change_Color = !Change_Color;
        for (int j = 0; j < 8; j++) {
            if (Change_Color) {
                glColor3f(0.0f, 0.0f, 0.0f);
                Change_Color = false;
            } else {
                glColor3f(1.0f, 1.0f, 1.0f);
                Change_Color = true;
            }
            glBegin(GL_QUADS);
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glVertex2f(i, j + 1);
            glEnd();
        }
    }

}

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  gluOrtho2D(0, 8, 0, 8);
  glClear(GL_COLOR_BUFFER_BIT);

  DrawChessBorad();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Simple Triangle");
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}