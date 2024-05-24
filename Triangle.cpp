#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <windows.h>

void DrawCircle() {
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i <= 300; i++) {
    double angle = 2 * 3.1416 * i / 300;
    double x = cos(angle);
    double y = sin(angle);
    glVertex2d(x, y);
  }
  glEnd();
}

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  gluOrtho2D(-3, 3, -3, 3);
  glClear(GL_COLOR_BUFFER_BIT);

  DrawCircle();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Simple Triangle");
  int hight, width;
  std::cin >> hight;
  std::cin >> width;

  glutInitWindowSize(hight, width);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}