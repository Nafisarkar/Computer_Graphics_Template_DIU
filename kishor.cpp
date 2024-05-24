#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

float tx = 0.0;
float ty = 0.0;

void init(void) {
  glClearColor(0.59, 0.99, 0.33, 1.0); // Set clear color to tia-green
  glMatrixMode(GL_PROJECTION);         // Select the projection matrix
  glLoadIdentity();                    // Reset the projection matrix
  glOrtho(
      0, 100, 0, 65, -1.0,
      1.0); // Set up an orthographic projection with the given clipping volume
}
void drawMountain() {
  glColor3f(0.09, 0.09, 0.3); // darkbluish color
  glBegin(GL_POLYGON);
  glVertex2f(100, 42);
  glVertex2f(100, 55);
  glVertex2f(95, 52);
  glVertex2f(90, 45);
  glVertex2f(85, 42);
  glVertex2f(80, 47);
  glVertex2f(77, 49);
  glVertex2f(75, 50);
  glVertex2f(70, 45);
  glVertex2f(65, 53);
  glVertex2f(57, 42);
  glVertex2f(51, 47);
  glVertex2f(45, 42);
  glEnd();
}
void drawcircle(float x, float y) {
  glTranslatef(0, 0, 0); // Translate to the correct position
  int i;
  float radius = .6f;
  int triangleAmount = 100; // Number of triangles used to draw the circle

  float twicePi = 2.0f * 3.14159265358979323846f;

  glColor3f(0, 0, 0); // Black color
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y); // Center of the circle
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
               y + (radius * sin(i * twicePi / triangleAmount)));
  }
  glEnd();
}
void drawHouse() {

  // house3
  // body
  // leftwall
  glColor3f(0.51, 0.6, 0.62); // dark skyblue color
  glBegin(GL_POLYGON);
  glVertex2f(78, 36);
  glVertex2f(78, 42);
  glVertex2f(89, 43);
  glVertex2f(89, 35.5);
  glEnd();
  // devider
  glColor3f(0, 0, 0); // black color
  glBegin(GL_LINES);
  glVertex2f(89, 35.5);
  glVertex2f(89, 43);
  glEnd();
  // rightwall
  glColor3f(0.62, 0.72, 0.75); // skyblue color
  glBegin(GL_POLYGON);
  glVertex2f(89, 35.5);
  glVertex2f(89, 43);
  glVertex2f(92, 46);
  glVertex2f(97, 43);
  glVertex2f(97, 36);
  glEnd();

  // window
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(93, 39);
  glVertex2f(93, 41);
  glVertex2f(95, 41);
  glVertex2f(95, 39);
  glEnd();
  // door
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(81, 35.9);
  glVertex2f(85, 35.6);
  glVertex2f(85, 40);
  glVertex2f(81, 40);
  glEnd();

  // roof
  // left
  glColor3f(1, 0.48, 0.15); // orange
  glBegin(GL_POLYGON);
  glVertex2f(89, 41);
  glVertex2f(77.5, 41);
  glVertex2f(83, 47);
  glVertex2f(93, 47);
  glEnd();

  // right
  glColor3f(0.65, 0.25, 0); // orange
  glBegin(GL_POLYGON);
  glVertex2f(93, 47);
  glVertex2f(92.2, 46);
  glVertex2f(97, 41);
  glVertex2f(99, 41);
  glEnd();

  // house2
  // body
  // leftwall
  glColor3f(0.62, 0.72, 0.75); // skyblue color
  glBegin(GL_POLYGON);
  glVertex2f(53, 34);
  glVertex2f(65.5, 33);
  glVertex2f(65.5, 42.5);
  glVertex2f(60, 50);
  glVertex2f(53, 42);
  glEnd();
  // rightwall
  glColor3f(0.62, 0.72, 0.75); // skyblue color
  glBegin(GL_POLYGON);
  glVertex2f(65.5, 33);
  glVertex2f(65.5, 42.5);
  glVertex2f(78, 40);
  glVertex2f(78, 33);
  glEnd();
  // devider
  glColor3f(0, 0, 0); // black color
  glBegin(GL_POLYGON);
  glVertex2f(65.5, 33);
  glVertex2f(65.6, 33);
  glVertex2f(65.6, 42.5);
  glVertex2f(65.5, 42.5);
  glEnd();

  // window
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(70, 38);
  glVertex2f(75, 38);
  glVertex2f(75, 35);
  glVertex2f(70, 35);
  glEnd();
  // door
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(57, 33.6);
  glVertex2f(60, 33.5);
  glVertex2f(60, 40);
  glVertex2f(57, 40);
  glEnd();

  glColor3f(0.65, 0.25, 0); // orange
  glBegin(GL_POLYGON);
  glVertex2f(50, 41);
  glVertex2f(53, 41);
  glVertex2f(60, 50);
  glVertex2f(58, 52);
  glEnd();

  // right
  glColor3f(1, 0.48, 0.15); // orange
  glBegin(GL_POLYGON);
  glVertex2f(58, 52);
  glVertex2f(71, 52);
  glVertex2f(80, 40);
  glVertex2f(67, 40);
  glEnd();

  // house5
  // body
  // right wall
  glColor3f(0.57, 0.45, 0.34); // full brown color
  glBegin(GL_POLYGON);
  glVertex2f(36.5, 39);
  glVertex2f(36.5, 43);
  glVertex2f(33, 47);
  glVertex2f(31, 43);
  glVertex2f(31, 39);
  glEnd();
  // left wall
  glColor3f(0.4, 0.32, 0.26); // dark brown color
  glBegin(GL_POLYGON);
  glVertex2f(31, 39);
  glVertex2f(31, 43);
  glVertex2f(25, 43);
  glVertex2f(25, 39);
  glEnd();
  // window circle for 5
  drawcircle(33.4f, 44.0f);

  // door
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(32.5, 39);
  glVertex2f(34, 39);
  glVertex2f(34, 42);
  glVertex2f(32.5, 42);
  glEnd();

  // roof
  // left
  glColor3f(0.65, 0.45, 0.65); // pur
  glBegin(GL_POLYGON);
  glVertex2f(30.4, 42);
  glVertex2f(34, 47.8);
  glVertex2f(28, 47.5);
  glVertex2f(25, 42);
  glEnd();

  // right
  glColor3f(0.44, 0.29, 0.43); // pur
  glBegin(GL_POLYGON);
  glVertex2f(34, 47.8);
  glVertex2f(33.2, 46.6);
  glVertex2f(36.5, 43);
  glVertex2f(38, 43);
  glEnd();

  // house4
  // body
  // right wall
  glColor3f(0.9, 0.94, 0.94); // full WHITE color
  glBegin(GL_POLYGON);
  glVertex2f(19, 37);
  glVertex2f(19, 43);
  glVertex2f(22.5, 48);
  glVertex2f(26.5, 42);
  glVertex2f(26.5, 37);
  glEnd();
  // left wall
  glColor3f(0.78, 0.78, 0.78); // almost white color
  glBegin(GL_POLYGON);
  glVertex2f(19, 37);
  glVertex2f(19, 43);
  glVertex2f(15, 43);
  glVertex2f(15, 37);
  glEnd();
  // devider
  glColor3f(0, 0, 0); // black color
  glBegin(GL_LINES);
  glVertex2f(19, 37);
  glVertex2f(19, 43);
  glEnd();

  // window circle for 4
  drawcircle(22.5f, 45.5f);

  // door
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(22, 37);
  glVertex2f(24, 37);
  glVertex2f(24, 42);
  glVertex2f(22, 42);
  glEnd();

  // roof
  // left
  glColor3f(0.54, 0.76, 0.3); // green
  glBegin(GL_POLYGON);
  glVertex2f(18.5, 41.5);
  glVertex2f(12, 41.5);
  glVertex2f(16, 49.5);
  glVertex2f(23.5, 49.5);
  glEnd();

  // right
  glColor3f(0.28, 0.5, 0.26); // green
  glBegin(GL_POLYGON);
  glVertex2f(23.5, 49.5);
  glVertex2f(22.5, 48);
  glVertex2f(26.5, 42);
  glVertex2f(28, 42);
  glEnd();

  // house1
  // body
  glColor3f(0.56, 0.53, 0.51); // ash color
  glBegin(GL_POLYGON);
  glVertex2f(0, 20);
  glVertex2f(21, 21);
  glVertex2f(21, 35);
  glVertex2f(0, 35);
  glEnd();
  // window
  glColor3f(0, 0, 0); // black
  glBegin(GL_POLYGON);
  glVertex2f(7, 25);
  glVertex2f(15, 25);
  glVertex2f(15, 31);
  glVertex2f(7, 31);
  glEnd();
  // roof
  glColor3f(0.48, 0.15, 0.15); // red
  glBegin(GL_POLYGON);
  glVertex2f(0, 35);
  glVertex2f(23, 35);
  glVertex2f(8, 52.5);
  glVertex2f(0, 52.5);
  glEnd();
}

void sky() {
  glColor3f(0.33, 0.57, 0.9); // Yellow color
  glBegin(GL_POLYGON);
  glVertex2f(0, 42);
  glVertex2f(100, 42);
  glVertex2f(100, 100);
  glVertex2f(0, 100);
  glEnd();
}

void drawPath() {
  glColor3f(1, 0.51, 0.24); // Yellow color
  glBegin(GL_POLYGON);
  glVertex2f(0, 4);
  glVertex2f(100, 23);
  glVertex2f(100, 31);
  glVertex2f(0, 15);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(59, 24);
  glVertex2f(80, 25);
  glVertex2f(15, 38);
  glVertex2f(15, 35);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(40, 32);
  glVertex2f(45, 30);
  glVertex2f(45, 42);
  glVertex2f(43, 42);
  glEnd();
}

void drawWell() {
  glColor3f(0.804, 0.522, 0.247); // Brown color
  glBegin(GL_QUADS);
  glVertex2f(80, 10);
  glVertex2f(90, 10);
  glVertex2f(90, 20);
  glVertex2f(80, 20);
  glEnd();

  glColor3f(0.627, 0.322, 0.176); // Darker brown color
  glBegin(GL_QUADS);
  glVertex2f(78, 18);
  glVertex2f(92, 18);
  glVertex2f(92, 20);
  glVertex2f(78, 20);
  glEnd();
}
void extras() {}

void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y) {
  int i = 0;
  float angle;
  GLfloat PI = 3.1416;
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  for (i = 0; i < 361; i++) {
    angle = i * PI / 180;
    glVertex2f(x + (cos(angle) * rx), y + (sin(angle) * ry));
  }
  glEnd();
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with the current
                                // clearing color
  // draw the sky portion
  sky();
  // draw mountain
  // drawClouds
  glColor3f(1, 1, 1); // White color
  circle(4, 1, 14, 55);
  circle(8, 2, 23, 54);
  circle(8, 2, 32, 55);
  circle(4, 1, 54, 62);
  circle(8, 2, 63, 64);
  circle(8, 2, 72, 63);
  circle(4, 1, 84, 55);
  circle(8, 2, 93, 54);
  circle(8, 2, 102, 55);
  // Draw bird

  drawMountain();
  // Draw the paths
  drawPath();
  // Draw the houses
  drawHouse();
  // drawHouse(, 20, 20, 10,); // House 2
  // drawHouse(80, 34, 20, 20, 10, 0.62, 0.72, 0.75); // House 3
  // Draw the well
  drawWell();
  extras(); // for better finishing

  glColor3f(0, 0, 0); // Black color
  glBegin(GL_LINES);
  glVertex2f(44+tx, 62);
  glVertex2f(46+tx, 60);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(46+tx, 60);
  glVertex2f(48+tx, 62);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(23+tx, 64);
  glVertex2f(25+tx, 62);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(25+tx, 62);
  glVertex2f(27+tx, 64);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(32+tx, 65);
  glVertex2f(34+tx, 63);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(34+tx, 63);
  glVertex2f(36+tx, 65);
  glEnd();
  
  glutSwapBuffers(); // Swap the front and back buffers (double buffering)
}

void update(int value) {
  // Update the positions of the shapes
  tx = tx+0.1;
  ty += 0.1;

  // Redisplay the scene
  glutPostRedisplay();

  // Call update again after 16 milliseconds (about 60 frames per second)
  glutTimerFunc(16, update, 0);
}

// Main function
int main(int argc, char **argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitDisplayMode(
      GLUT_RGB |
      GLUT_DOUBLE); // Set up a display mode with RGB color and double buffering
  glutInitWindowPosition(0, 0);      // Set the initial window position
  glutInitWindowSize(500, 500);      // Set the window size
  glutCreateWindow("Village Scene"); // Create a window with the specified title
  init();                            // Initialize OpenGL state
  glutDisplayFunc(Draw);             // Set the display callback function
  glutTimerFunc(16, update, 0);
  glutMainLoop();                    // Enter the GLUT event processing loop
  return 0;
}