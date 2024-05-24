#include <GL/glut.h>
#include <windows.h>

using namespace std;

void plot(int x, int X1, int y, int Y1) {
  glBegin(GL_POINTS);
  glVertex2i(x + X1, y + Y1);
  glEnd();
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-500, 500, -500, 500, -1, 1);
}

void midCircleDraw(int pntX1, int pntY1, int r) {
  int x = 0;
  int y = r;
  float decision = 5 / 4 - r;
  plot(x, pntX1, y, pntY1);

  while (y > x) {
    if (decision < 0) {
      x++;
      decision += 2 * x + 1;
    } else {
      y--;
      x++;
      decision += 2 * (x - y) + 1;
    }
    plot(x, pntX1, y, pntY1);
    plot(x, pntX1, -y, pntY1);
    plot(-x, pntX1, y, pntY1);
    plot(-x, pntX1, -y, pntY1);
    plot(y, pntX1, x, pntY1);
    plot(-y, pntX1, x, pntY1);
    plot(y, pntX1, -x, pntY1);
    plot(-y, pntX1, -x, pntY1);
  }
}

void myDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(1.0);

  midCircleDraw(0, 0, 100);

  midCircleDraw(200, 200, 100);
  midCircleDraw(-200, 200, 100);
  midCircleDraw(-200, -200, 100);
  midCircleDraw(200, -200, 100);

  glBegin(GL_LINES);
  glColor3f(0.0770, 0.790, 0.0395);
  glVertex2f(-100.0f, 200.0f); // top left
  glVertex2f(100.0f, 200.0f);  // top right
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0.0770, 0.790, 0.0395);
  glVertex2f(200.0f, 100.0f);  // top right
  glVertex2f(200.0f, -100.0f); // bottom right
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0.0770, 0.790, 0.0395);
  glVertex2f(100.0f, -200.0f);  // bottom right
  glVertex2f(-100.0f, -200.0f); // bottom left
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0.0770, 0.790, 0.0395);
  glVertex2f(-200.0f, -100.0f); // bottom left
  glVertex2f(-200.0f, 100.0f);  // top left
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0.0470, 0.490, 0.0195);
  glVertex2f(-130.0f, -130.0f); // top left
  glVertex2f(130.0f, 130.0f);   // top right
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0.0470, 0.490, 0.0195);
  glVertex2f(-130.0f, 130.0f); // top left
  glVertex2f(130.0f, -130.0f); // top right
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Mid Point Circle Drawing Algorithm");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();

  return 0;
}