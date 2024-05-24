#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

float tx = 0, ty = 0;

float trianglePosX = 0.0f;  // Initial X position for the triangle
float rectanglePosX = 0.0f; // Initial X position for the rectangles
float speed = 1.1f;         // Speed of movement

float posX = -700.0f; // Initial X position for all shapes
float fspeed1 = 0.1f;
float fspeed2 = 0.1f;
float fspeed3 = 0.1f;
float cloudSpeed1 = 0.1f;
float cloudSpeed2 = 0.1f;
float cloudSpeed3 = 0.1f;
float cloudSpeed4 = 0.1f;

void drawTree(float x, float y, float crownWidth, float crownHeight) {
  // Draw crown with gradient from green to gray
  glBegin(GL_TRIANGLES);
  glColor3f(0.00340, 0.340, 0.0932); // Dark green color
  glVertex2f(x - crownWidth / 2, y);
  glColor3f(0, 0, 0); // Gray color
  glVertex2f(x + crownWidth / 2, y);
  glColor3f(0.00340, 0.340, 0.0932); // Dark green color
  glVertex2f(x, y + crownHeight);
  glEnd();
}

void drawRectangleNO(float x, float y, float width, float height,
                     float fillColor[3]) {
  // Draw the filled rectangle
  glColor3f(fillColor[0], fillColor[1], fillColor[2]);
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  glVertex2f(x + width, y);
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();
}

void drawCurvedLine(float startX, float startY, float endX, float endY,
                    int segments, float outlineColor[3], float lineWidth) {
  float controlX = (startX + endX) / 2;
  float controlY = (startY + endY) / 2 + 350; // Control point for Bezier curve

  // Set the line width
  glLineWidth(lineWidth);

  // Draw the curve
  glColor3f(outlineColor[0], outlineColor[1], outlineColor[2]);
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i <= segments; ++i) {
    float t = (float)i / (float)segments;
    float x =
        (1 - t) * (1 - t) * startX + 2 * (1 - t) * t * controlX + t * t * endX;
    float y =
        (1 - t) * (1 - t) * startY + 2 * (1 - t) * t * controlY + t * t * endY;
    glVertex2f(x, y);
  }
  glEnd();

  // Reset the line width to default
  glLineWidth(1.0f);
}

void drawRectangle(float x, float y, float width, float height,
                   float fillColor[3], float outlineColor[3]) {
  // Draw the filled rectangle
  glColor3f(fillColor[0], fillColor[1], fillColor[2]);
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  glVertex2f(x + width, y);
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();

  // Draw the rectangle outline
  glColor3f(outlineColor[0], outlineColor[1], outlineColor[2]);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x, y);
  glVertex2f(x + width, y);
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();
}

void drawRandomTrees(float minX, float maxX, int numTrees) {
  srand(time(0)); // Seed the random number generator

  for (int i = 0; i < numTrees; ++i) {
    float x = minX +
              rand() % (int)(maxX - minX + 1); // Random x between minX and maxX
    float crownWidth = rand() % 41 + 10;       // Random width between 10 and 50
    float crownHeight = rand() % 41 + 80; // Random height between 80 and 120

    drawTree(x, -100, crownWidth, crownHeight);
  }
}

void DrawCircleWithDig(int radious, int x, int y, int degree) {
  float theta;
  glBegin(GL_POLYGON);
  glColor3f(1, 1, 1);
  for (int i = 0; i < degree; i++) {
    theta = i * 3.1416 / 180;
    glVertex2f(x + radious * cos(theta), y + radious * sin(theta));
  }
  glEnd();
}

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

void drawTopHalfOval(int x, int y, int width, int height) {
  // Draw the top half of the oval
  glBegin(GL_POLYGON);
  for (int i = 0; i <= 180; i += 10) {
    float theta = i * 3.1416 / 180.0;
    float x1 = x + width * cosf(theta) / 2;
    float y1 = y + height * sinf(theta) / 2;
    glVertex2f(x1, y1);
  }
  glEnd();
}

void drawGradientBackground() {
  glShadeModel(GL_SMOOTH); // Enable smooth shading

  // Set the color for the top-left vertex (light blue)
  glColor3f(0.53, 0.81, 0.92);
  glBegin(GL_QUADS);
  glVertex2f(-600, 350); // Top-left

  // Set the color for the top-right vertex (light blue)
  glColor3f(0.53, 0.81, 0.92);
  glVertex2f(600, 350); // Top-right

  // Set the color for the bottom-right vertex (darker blue)
  glColor3f(0.13, 0.45, 0.76);
  glVertex2f(600, -350); // Bottom-right

  // Set the color for the bottom-left vertex (darker blue)
  glColor3f(0.13, 0.45, 0.76);
  glVertex2f(-600, -350); // Bottom-left

  glEnd();
}

void init(void) {
  glClearColor(0, 0, 0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-600, 600, -350, 350, -1.0, 1.0);

  // Check OpenGL version and extensions
  const GLubyte *renderer = glGetString(GL_RENDERER);
  const GLubyte *version = glGetString(GL_VERSION);
  const GLubyte *extensions = glGetString(GL_EXTENSIONS);

  printf("Renderer: %s\n", renderer);
  printf("OpenGL Version: %s\n", version);
  printf("Extensions: %s\n", extensions);
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw the gradient background
  drawGradientBackground();

  // Draw the bottomleft cloud
  glColor3f(1, 1, 1);
  drawTopHalfOval(-320 + cloudSpeed1, 180, 100, 50);
  drawTopHalfOval(-400 + cloudSpeed1, 180, 70, 40);
  drawTopHalfOval(-440 + cloudSpeed1, 180, 130, 30);

  // Draw the topleft cloud
  glColor3f(1, 1, 1);
  drawTopHalfOval(-600 + cloudSpeed2, 270, 200, 140);
  drawTopHalfOval(-460 + cloudSpeed2, 270, 170, 80);
  drawTopHalfOval(-320 + cloudSpeed2, 270, 230, 50);
  drawTopHalfOval(-150 + cloudSpeed2, 270, 170, 30);

  // Draw the topright cloud
  glColor3f(1, 1, 1);
  drawTopHalfOval(150 + cloudSpeed3, 240, 170, 30);
  drawTopHalfOval(320 + cloudSpeed3, 240, 230, 50);
  drawTopHalfOval(460 + cloudSpeed3, 240, 170, 80);
  drawTopHalfOval(600 + cloudSpeed3, 240, 200, 140);

  // Draw the bottomright cloud
  glColor3f(1, 1, 1);
  drawTopHalfOval(200 + cloudSpeed4, 120, 120, 60);
  drawTopHalfOval(130 + cloudSpeed4, 120, 90, 50);
  drawTopHalfOval(300 + cloudSpeed4, 120, 200, 50);
  drawTopHalfOval(40 + cloudSpeed4, 120, 200, 30);

  // CENTER HORIZON CIRCLE
  glColor3f(0.270, 0.373, 0.540);
  drawTopHalfOval(100, -100, 400, 300);

  // Draw the horizon mountain

  glColor3f(0.239, 0.309, 0.420);
  glBegin(GL_POLYGON);
  // circle(300, 200, -600, -100); // Original circle
  // circle(-300, 200, 600, -100); // Mirrored circle

  // circle(250, 140, -400, -100); // Original circle
  // circle(-250, 140, 400, -100); // Mirrored circle

  // circle(200, 60, -240, -100); // Original circle
  // circle(-200, 60, 240, -100); // Mirrored circle

  drawTopHalfOval(-700, -100, 700, 600);
  drawTopHalfOval(-600, -100, 500, 500);
  drawTopHalfOval(-400, -100, 500, 400);
  drawTopHalfOval(-200, -100, 400, 200);

  // Additional mirrored circles
  drawTopHalfOval(700, -100, 700, 600); // Mirror horizontally
  drawTopHalfOval(600, -100, 500, 500); // Mirror horizontally
  drawTopHalfOval(400, -100, 500, 400); // Mirror horizontally
  drawTopHalfOval(200, -100, 400, 200);

  // far tree line

  drawRandomTrees(-600, 600, 100);

  // bridge top line
  glColor3f(0.545, 0.271, 0.075);
  float fillColor[3] = {0.220, 0.257, 0.360};
  float outlineColor[3] = {1, 1, 1};

  // Draw a rectangle at position (50, 50) with width 100 and height 50
  drawRectangle(-600, 60, 1240, 30, fillColor, outlineColor);

  float fillColorx[3] = {0.0342, 0.0757, 0.190};
  float outlineColorx[3] = {1, 1, 1};
  drawRectangle(-600, 60, 1240, 10, fillColorx, outlineColorx);

  // draw curved line
  float fillColorxx[3] = {1, 0.0757, 0.190};
  float outlineColorxx[3] = {0, 0, 0};
  drawCurvedLine(-300, -130, 300, -130, 122, outlineColorxx, 15.0f);
  drawCurvedLine(-300, -120, 300, -120, 122, outlineColorxx, 15.0f);

  drawCurvedLine(-600, -130, -300, -130, 122, outlineColorxx, 15.0f);
  drawCurvedLine(-600, -120, -300, -120, 122, outlineColorxx, 15.0f);

  drawCurvedLine(300, -130, 600, -130, 122, outlineColorxx, 15.0f);
  drawCurvedLine(300, -120, 600, -120, 122, outlineColorxx, 15.0f);

  // centerbox
  drawRectangleNO(-100, 30, 200, 30, outlineColorxx);
  drawRectangleNO(-160, 10, 10, 50, outlineColorxx);
  drawRectangleNO(160, 0, 10, 60, outlineColorxx);
  drawRectangleNO(250, -100, 40, 160, outlineColorxx);
  drawRectangleNO(-290, -100, 40, 160, outlineColorxx);

  // train
  // Draw a triangle
  glBegin(GL_TRIANGLES);
  glColor3f(0.900, 0.893, 0.765); // Light blue color
  glVertex2f(280 + trianglePosX, 111);
  glColor3f(0.2, 0.4, 0.6); // Darker blue color
  glVertex2f(280 + trianglePosX, 70);
  glColor3f(0.690, 0.661, 0.110); // Blue color
  glVertex2f(320 + trianglePosX, 70);
  glEnd();

  // Define colors
  float fillColorxxxx[3] = {0.239, 0.309, 0.420};
  float fillColorInside[3] = {1.0f, 1.0f, 1.1f};
  float yellostripes[3] = {0.840, 0.830, 0.260};
  float windowscolor[3] = {0.228, 0.503, 0.760};
  float jointColor[3] = {0.231, 0.0240, 0.400};

  // boggy 1
  drawRectangleNO(100 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(103 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(103 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(120 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(160 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(200 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(240 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(80 + rectanglePosX, 74, 20, 30, jointColor);

  // boggy 2
  drawRectangleNO(-100 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-97 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-97 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-90 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-50 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-10 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(30 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-120 + rectanglePosX, 74, 20, 30, jointColor);

  // boggy 3
  drawRectangleNO(-300 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-297 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-297 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-290 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-250 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-210 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-170 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-320 + rectanglePosX, 74, 20, 30, jointColor);

  // boggy 4
  drawRectangleNO(-500 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-497 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-497 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-490 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-450 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-410 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-370 + rectanglePosX, 80, 30, 20, windowscolor);

  // boggy 5
  drawRectangleNO(-700 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-697 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-697 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-690 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-650 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-610 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-570 + rectanglePosX, 80, 30, 20, windowscolor);

  // boggy 6
  drawRectangleNO(-900 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-897 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-897 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-890 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-850 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-810 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-770 + rectanglePosX, 80, 30, 20, windowscolor);

  // boggy 7
  drawRectangleNO(-1100 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-1097 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-1097 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-1090 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-1050 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-1010 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-970 + rectanglePosX, 80, 30, 20, windowscolor);

  // boggy 8
  drawRectangleNO(-1300 + rectanglePosX, 70, 185, 40, fillColorxxxx);
  drawRectangleNO(-1297 + rectanglePosX, 73, 180, 35, fillColorInside);
  drawRectangleNO(-1297 + rectanglePosX, 80, 180, 20, yellostripes);
  drawRectangleNO(-1290 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-1250 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-1210 + rectanglePosX, 80, 30, 20, windowscolor);
  drawRectangleNO(-1170 + rectanglePosX, 80, 30, 20, windowscolor);

  // Draw the horizon mountain
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-700, -100, 700, 400);
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(-680, -100, 700, 600);
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-600, -100, 500, 500);
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(-400, -100, 500, 300);
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-400, -100, 500, 200);

  // Additional mirrored circles for the mountains
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(700, -100, 700, 400); // Mirror horizontally
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(680, -100, 700, 600); // Mirror horizontally
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(600, -100, 500, 500); // Mirror horizontally
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(400, -100, 500, 300); // Mirror horizontally
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(400, -100, 500, 200); // Mirror horizontally

  // white foam
  // Trees behind the foam layer
  glColor3f(1, 1, 1);
  circle(500, 40, -600, -100);  // Original circle
  circle(450, 240, -700, -300); // Original circle
  circle(500, 40, 600, -100);   // Mirrored circle
  circle(450, 240, 700, -300);  // Mirrored circle

  drawTree(-580, 80, 30, 100);
  drawTree(-570, 80, 30, 100);
  drawTree(-560, 60, 30, 70);
  drawTree(-550, 60, 30, 80);
  drawTree(-540, 50, 30, 100);
  drawTree(-530, 50, 30, 70);
  drawTree(-520, 50, 30, 100);
  drawTree(-510, 40, 30, 100);
  drawTree(-500, 40, 30, 80);
  drawTree(-490, 40, 30, 100);
  drawTree(-480, 40, 30, 100);

  drawTree(-440, 30, 30, 90);
  drawTree(-430, 20, 30, 70);
  drawTree(-420, 20, 30, 80);
  drawTree(-410, 10, 30, 90);
  drawTree(-400, 10, 30, 100);
  drawTree(-390, 10, 30, 70);
  drawTree(-360, -10, 30, 80);
  drawTree(-350, -10, 30, 100);

  drawTree(-320, -20, 30, 90);
  drawTree(-310, -30, 30, 100);
  drawTree(-300, -30, 30, 100);
  drawTree(-290, -30, 30, 70);
  drawTree(-280, -40, 30, 100);

  drawTree(-250, -50, 30, 80);
  drawTree(-240, -50, 30, 100);
  drawTree(-230, -60, 30, 80);

  drawTree(-200, -70, 30, 60);
  drawTree(-190, -70, 30, 70);
  drawTree(-180, -70, 30, 50);

  drawTree(580, 80, 30, 100);
  drawTree(570, 80, 30, 100);
  drawTree(560, 60, 30, 70);
  drawTree(550, 60, 30, 80);
  drawTree(540, 50, 30, 100);
  drawTree(530, 50, 30, 70);
  drawTree(520, 50, 30, 100);
  drawTree(510, 40, 30, 100);
  drawTree(500, 40, 30, 80);
  drawTree(490, 40, 30, 100);
  drawTree(480, 40, 30, 100);

  drawTree(440, 30, 30, 90);
  drawTree(430, 20, 30, 70);
  drawTree(420, 20, 30, 80);
  drawTree(410, 10, 30, 90);
  drawTree(400, 10, 30, 100);
  drawTree(390, 10, 30, 70);
  drawTree(360, -10, 30, 80);
  drawTree(350, -10, 30, 100);

  drawTree(320, -20, 30, 90);
  drawTree(310, -30, 30, 100);
  drawTree(300, -30, 30, 100);
  drawTree(290, -30, 30, 70);
  drawTree(280, -40, 30, 100);

  drawTree(250, -50, 30, 80);
  drawTree(240, -50, 30, 100);
  drawTree(230, -60, 30, 80);

  drawTree(200, -70, 30, 60);
  drawTree(190, -70, 30, 70);
  drawTree(180, -70, 30, 50);

  // Draw Triangle over the foam
  glBegin(GL_TRIANGLES);
  glColor3f(0.0232, 0.580, 0.218); // Dark green color
  glVertex2f(-100, -100);
  glColor3f(0.0, 0.5, 0.0); // Light green color
  glVertex2f(-600, 100);
  glColor3f(0.0440, 0.220, 0.106); // Dark green color
  glVertex2f(-600, -100);
  glEnd();

  // Draw Triangle over the foam
  glBegin(GL_TRIANGLES);
  glColor3f(0.0232, 0.580, 0.218); // Dark green color
  glVertex2f(100, -100);
  glColor3f(0.0, 0.5, 0.0); // Light green color
  glVertex2f(600, 100);
  glColor3f(0.0440, 0.220, 0.106); // Dark green color
  glVertex2f(600, -100);
  glEnd();

  // Draw a horizontal line
  glBegin(GL_LINES);
  glColor3f(1, 1, 1);               // Set line color to white
  glVertex2f(-160 + fspeed1, -220); // Starting point of the line
  glVertex2f(-130 + fspeed1, -220); // Ending point of the line
  glEnd();
  glBegin(GL_LINES);
  glColor3f(1, 1, 1);               // Set line color to white
  glVertex2f(-100 + fspeed3, -230); // Starting point of the line
  glVertex2f(-150 + fspeed3, -230); // Ending point of the line
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1, 1, 1);              // Set line color to white
  glVertex2f(160 + fspeed2, -220); // Starting point of the line
  glVertex2f(130 + fspeed2, -220); // Ending point of the line
  glEnd();
  glBegin(GL_LINES);
  glColor3f(1, 1, 1);              // Set line color to white
  glVertex2f(100 + fspeed3, -230); // Starting point of the line
  glVertex2f(130 + fspeed3, -230); // Ending point of the line
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1, 1, 1);             // Set line color to white
  glVertex2f(60 + fspeed2, -180); // Starting point of the line
  glVertex2f(30 + fspeed2, -180); // Ending point of the line
  glEnd();
  glBegin(GL_LINES);
  glColor3f(1, 1, 1);              // Set line color to white
  glVertex2f(0 + fspeed1, -170);   // Starting point of the line
  glVertex2f(140 + fspeed1, -170); // Ending point of the line
  glEnd();

  // Draw the bottomleft cloud
  // Draw the horizon mountain
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-600, -400, 700, 400);
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(-580, -400, 700, 600);
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-500, -400, 500, 500);
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(-400, -400, 500, 300);
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(-400, -400, 500, 200);

  // Additional mirrored circles for the mountains
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(600, -400, 700, 400); // Mirror horizontally
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(580, -400, 700, 600); // Mirror horizontally
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(500, -400, 500, 500); // Mirror horizontally
  glColor3f(0.370, 0.342, 0.248);
  drawTopHalfOval(400, -400, 500, 300); // Mirror horizontally
  glColor3f(0.210, 0.193, 0.139);
  drawTopHalfOval(400, -400, 500, 200); // Mirror horizontally

  glBegin(GL_LINE_STRIP);

  glColor3f(1, 1, 1);
  glVertex2f(600, -100);
  glVertex2f(-600, -100);
  glEnd();
  glutSwapBuffers();
}

void update(int value) {
  // Update the positions of the shapes
  trianglePosX += speed;
  rectanglePosX += speed;

  // Reset positions if they move off screen (for continuous movement)
  if (trianglePosX > 500)
    trianglePosX = -500;
  if (rectanglePosX > 500)
    rectanglePosX = -500;

  
  fspeed1 += 0.5f;
  fspeed2 += 0.3f;
  fspeed3 += 0.1f;

  if (fspeed1 > 60) {
    fspeed1 = -60;
  }
  if (fspeed2 > 40) {
    fspeed2 = -40;
  }
  if (fspeed3 > 60) {
    fspeed3 = -60;
  }
  
  cloudSpeed1 += 0.1f;
  cloudSpeed2 += 0.3f;
  cloudSpeed3 -= 0.1f;
  cloudSpeed4 -= 0.3f;

  // Redisplay the scene
  glutPostRedisplay();

  // Call update again after 16 milliseconds (about 60 frames per second)
  glutTimerFunc(16, update, 0);
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(500, 200);
  glutInitWindowSize(1200, 700);
  glutCreateWindow("Lab Final");
  init();
  glutDisplayFunc(Draw);
  glutTimerFunc(16, update, 0);
  glutMainLoop();
  return 0;
}
