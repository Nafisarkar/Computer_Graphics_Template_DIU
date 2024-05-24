#include <GL/glut.h>
#include <windows.h>


void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glOrtho(-300, 300, -300, 300, -4, 4);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(88, 144);
  glVertex2f(164, 96);

  glColor3f(0.295, 0.314, 0.670);
  glVertex2f(3, 0);
  glVertex2f(-3, 0);
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Two lines");
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}