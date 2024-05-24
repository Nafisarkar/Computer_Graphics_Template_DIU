#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

float p=-60.0;
float b=-60.0;
float c=-50.0;
float m=-5.0;
float w=-5;
float f=-5;

int d =1;
int n =0;

void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-50,50,-60,60,-50,50);
}
//stars
void star(int x, int y)
{
    glColor3f(0.91, 0.91, 0.93);
    glBegin(GL_QUADS);
    glVertex2d(x,y);
    glVertex2d(x+0.5,y+0.5);
    glVertex2d(x+1,y);
    glVertex2d(x+0.5,y-0.5);
    glEnd();
}
void starPack()
{
    star(47,40);
    star(28,58);
    star(36,47);
    star(48,50);
    star(20,52);
    star(10,49);
    star(-50,45);
    star(-45,53);
    star(-40,55);
    star(-7,54);
    star(-22,54);

}

void circle (GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI=3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0; i<361; i++)
    {
        angle = i*PI/180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void leaf()
{
    //green
    if(d==1)
        glColor3f(0,0.5,0);
    else if(n==1)
        glColor3f (0, .3, 0);

    glBegin(GL_POLYGON);
    glVertex3f (21,3.5, 0.0);
    glVertex3f (20.5,4, 0.0);
    glVertex3f (20,3.5, 0.0);
    glVertex3f (20.5,3, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (20,3.5, 0.0);
    glVertex3f (19.5,4, 0.0);
    glVertex3f (19,3.5, 0.0);
    glVertex3f (19.5,3, 0.0);
    glEnd();

    //brown
    if(d==1)
        glColor3f(0.8,0.7,0.1);
    else if(n==1)
        glColor3f (.5, .3, 0.1);

    glBegin(GL_POLYGON);
    glVertex3f (20.5,2.5, 0.0);
    glVertex3f (20,3.5, 0.0);
    glVertex3f (19.5,2.5, 0.0);
    glVertex3f (20,2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (20.5,4.5, 0.0);
    glVertex3f (20,5, 0.0);
    glVertex3f (19.5,4.5, 0.0);
    glVertex3f (20,3.5, 0.0);
    glEnd();
}

void box()
{
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(16,-5,0.0);
    glVertex3f(16,5,0.0);
    glVertex3f(24,5,0.0);
    glVertex3f(24,-5,0.0);
    glEnd();
}

void shams()
{
    if ( d == 1)
    {
        //background sky
        glColor3f(0.35, 0.74, 0.85);
        glBegin(GL_QUADS);
        glVertex3f(-50,-5.0,0.0);
        glVertex3f(-50,60.0,0.0);
        glColor3f(0, 0.74, 1);
        glVertex3f(50,60.0,0.0);
        glColor3f(0.11, 0.64, 0.93);
        glVertex3f(50.0,-5.0,0.0);
        glEnd();

        //rainbow
        //red
        glColor3f(1, 0, 0);
        circle(19,24,-27,35);

        //orange
        glColor3f(1, 0.5, 0);
        circle(18.5,24,-27,34.5);

        //yellow
        glColor3f(1, 1, 0);
        circle(18.0,24,-27,34);

        //green
        glColor3f(0, 1, 0);
        circle(18.0,24,-27,33.5);

        //blue
        glColor3f(0, 0, 1);
        circle(18.0,24,-27,33);

        //indigo
        glColor3f(0.29, 0, 0.51);
        circle(18.0,24,-27,32.5);

        //violet
        glColor3f(0.58, 0, 0.83);
        circle(18.0,24,-27,32);

        //lower background
        glColor3f(0.35, 0.74, 0.85);
        circle(18.0,24,-27,31.5);

        //top middle building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_POLYGON);
        glVertex3f(-5,33.5,0.0);
        glVertex3f(-20,34.0,0.0);
        glVertex3f(-20,42.0,0.0);
        glVertex3f(-11.0,45.0,0.0);
        glVertex3f(11,45.0,0.0);
        glVertex3f(20.0,42.0,0.0);
        glVertex3f(20,34.0,0.0);
        glVertex3f(15.0,33.5,0.0);
        glVertex3f(15,40.0,0.0);
        glVertex3f(5.0,37,0.0);
        glVertex3f(-5,37.0,0.0);
        glVertex3f(-15.0,40.0,0.0);
        glEnd();

        //top middle shape
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-5,37,0.0);
        glVertex3f(-10,38,0.0);
        glVertex3f(-10,40.0,0.0);
        glVertex3f(10.0,40.0,0.0);
        glVertex3f(10,38,0.0);
        glVertex3f(5.0,37.0,0.0);
        glEnd();

        //left building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-45,-5,0.0);
        glVertex3f(-45,28.0,0.0);
        glVertex3f(-35,31.5,0.0);
        glEnd();

        //left middle building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-35,31.5,0.0);
        glVertex3f(-25,35,0.0);
        glVertex3f(-25,-5.0,0.0);
        glEnd();

        //border between left & middle left building
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-35.5,-5,0.0);
        glVertex3f(-35.5,31,0.0);
        glVertex3f(-35,31.5,0.0);
        glEnd();

        //left-right building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(-25,-5,0.0);
        glVertex3f(-25,35,0.0);
        glVertex3f(-15,34,0.0);
        glVertex3f(-15,-5.0,0.0);
        glEnd();

        //line between left middle & left-right building
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,-5,0.0);
        glVertex3f(-25,35,0.0);
        glEnd();

        //right building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(35,31.5,0);
        glVertex3f(45,28.0,0.0);
        glVertex3f(45,-5,0.0);
        glEnd();

        //right middle building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(25,-5,0.0);
        glVertex3f(25,35,0.0);
        glVertex3f(35,31.5,0.0);
        glEnd();

        //border between right & middle right building
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(35,31.5,0.0);
        glVertex3f(35.5,31,0.0);
        glVertex3f(35.5,-5,0.0);
        glEnd();

        //right left middle building
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(25,-5,0.0);
        glVertex3f(15,-5,0.0);
        glVertex3f(15,33.5,0.0);
        glVertex3f(25,35,0.0);
        glEnd();

        //lines between right left-middle building
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(25,-5,0.0);
        glEnd();

        //middle left bulding
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(-15,-5,0.0);
        glVertex3f(-15,40,0.0);
        glVertex3f(-5,37,0.0);
        glVertex3f(-5,-5,0.0);
        glEnd();

        //middle right bulding
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(5,-5,0.0);
        glVertex3f(5,37,0.0);
        glVertex3f(15,40,0.0);
        glVertex3f(15,-5,0.0);
        glEnd();

        //middle left bulding left line
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-15,-5,0.0);
        glVertex3f(-15,40,0.0);
        glEnd();

        //middle right bulding right line
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(15,-5,0.0);
        glVertex3f(15,40,0.0);
        glEnd();

        //middle  bulding
        glColor3f(0.6, 0.45, 0.22);
        glBegin(GL_QUADS);
        glVertex3f(-5,-5,0.0);
        glVertex3f(-5,37,0.0);
        glVertex3f(15,37,0.0);
        glVertex3f(5,-5,0.0);
        glEnd();

        //middle bulding letf border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-5,-5,0.0);
        glVertex3f(-5.5,-5,0.0);
        glVertex3f(-5.5,37,0.0);
        glVertex3f(-5,37,0.0);
        glEnd();

        //middle bulding right border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(5,-5,0.0);
        glVertex3f(5,37,0.0);
        glVertex3f(5.5,37,0.0);
        glVertex3f(5.5,-5,0.0);
        glEnd();

        //left building triangle
        glColor3f(0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(-34,7,0.0);
        glVertex3f(-30,32,0.0);
        glVertex3f(-26,7.0,0.0);
        glEnd();

        //right building triangle
        glColor3f(0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(16,7,0.0);
        glVertex3f(20,32,0.0);
        glVertex3f(24,7.0,0.0);
        glEnd();

        //left bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-34,-5,0.0);
        glVertex3f(-34,5,0.0);
        glVertex3f(-26,5,0.0);
        glVertex3f(-26,-5,0.0);
        glEnd();

        //right bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(16,-5,0.0);
        glVertex3f(16,5,0.0);
        glVertex3f(24,5,0.0);
        glVertex3f(24,-5,0.0);
        glEnd();

        //middle bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-4,-5,0.0);
        glVertex3f(-4,5,0.0);
        glVertex3f(4,5,0.0);
        glVertex3f(4,-5,0.0);
        glEnd();

        //middle bulding small box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-2,8,0.0);
        glVertex3f(-2,10,0.0);
        glVertex3f(2,10,0.0);
        glVertex3f(2,8,0.0);
        glEnd();

        //stairs area
        glColor3f(0.64, 0.2, 0.08);
        glBegin(GL_QUADS);
        glVertex3f(-50,-15,0.0);
        glVertex3f(-50,-5,0.0);
        glVertex3f(50,-5,0.0);
        glVertex3f(50,-15.0,0.0);
        glEnd();

        //1st line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-5,0.0);
        glVertex3f(50,-5,0.0);
        glEnd();

        //2nd line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-7,0.0);
        glVertex3f(50,-7,0.0);
        glEnd();

        //3rd line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-9,0.0);
        glVertex3f(50,-9,0.0);
        glEnd();

        //4th line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-11,0.0);
        glVertex3f(50,-11,0.0);
        glEnd();

        //5thth line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-13,0.0);
        glVertex3f(50,-13,0.0);
        glEnd();

        //6th line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-15,0.0);
        glVertex3f(50,-15,0.0);
        glEnd();

        //stairs middle shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-2,-15,0.0);
        glVertex3f(-1,-5,0.0);
        glVertex3f(1,-5,0.0);
        glVertex3f(2,-15.0,0.0);
        glEnd();

        //stairs left shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-33,-15,0.0);
        glVertex3f(-30,-5,0.0);
        glVertex3f(-28,-5,0.0);
        glVertex3f(-31,-15.0,0.0);
        glEnd();

        //stairs right shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(25,-15,0.0);
        glVertex3f(20,-5,0.0);
        glVertex3f(22,-5,0.0);
        glVertex3f(27,-15.0,0.0);
        glEnd();

        //middle field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(-50,-15,0.0);
        glVertex3f(-50,-30,0.0);
        glVertex3f(50,-30,0.0);
        glVertex3f(50,-15.0,0.0);
        glEnd();

        //swimming pool
        glColor3f(0.06, 0.37, 0.61);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glColor3f(0.14, 0.54, 0.85);
        glVertex3f(25,-40,0.0);
        glColor3f(0.11, 0.64, 0.93);
        glVertex3f(36,-60,0.0);
        glColor3f(0.35, 0.74, 0.85);
        glVertex3f(-32,-60.0,0.0);
        glEnd();

        // wave 1st
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-37,-45,0.0);
        glVertex3f(w-33,-45,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-36,-44.5,0.0);
        glVertex3f(w-31,-44.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-36.5,-45.5,0.0);
        glVertex3f(w-33,-45.5,0.0);
        glEnd();

        // wave 2nd
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-39,-55,0.0);
        glVertex3f(w-35,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-38,-54.5,0.0);
        glVertex3f(w-33,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-38.5,-55.5,0.0);
        glVertex3f(w-35,-55.5,0.0);
        glEnd();

        // wave 4th
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-54,-50,0.0);
        glVertex3f(w-49,-50,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-53,-49.5,0.0);
        glVertex3f(w-48,-49.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-53.5,-50.5,0.0);
        glVertex3f(w-50,-50.5,0.0);
        glEnd();

        // wave left
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-22,-50,0.0);
        glVertex3f(w-18,-50,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-21,-49.5,0.0);
        glVertex3f(w-16,-49.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-21.5,-50.5,0.0);
        glVertex3f(w-17,-50.5,0.0);
        glEnd();

        // wave right
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+0,-46,0.0);
        glVertex3f(w+4,-46,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+1,-45.5,0.0);
        glVertex3f(w+6,-45.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+0.5,-46.5,0.0);
        glVertex3f(w+5,-46.5,0.0);
        glEnd();

        //wave lower left
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-7,-55,0.0);
        glVertex3f(w-3,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-6,-54.5,0.0);
        glVertex3f(w-1,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-6.5,-55.5,0.0);
        glVertex3f(w-2,-55.5,0.0);
        glEnd();

        //wave lower right
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+10,-55,0.0);
        glVertex3f(w+14,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+11,-54.5,0.0);
        glVertex3f(w+16,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+11.5,-55.5,0.0);
        glVertex3f(w+15,-55.5,0.0);
        glEnd();

        //left field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(-50,-40,0.0);
        glVertex3f(-30,-40,0.0);
        glVertex3f(-36,-60,0.0);
        glVertex3f(-50,-60.0,0.0);
        glEnd();

        //right field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(30,-40,0.0);
        glVertex3f(50,-40,0.0);
        glVertex3f(50,-60,0.0);
        glVertex3f(38,-60.0,0.0);
        glEnd();

        //swimming pool right border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(23.5,-40,0.0);
        glVertex3f(25,-40,0.0);
        glVertex3f(36,-60,0.0);
        glVertex3f(34.5,-60.0,0.0);
        glEnd();

        //swimming pool left border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glVertex3f(-23.5,-40,0.0);
        glVertex3f(-30.5,-60,0.0);
        glVertex3f(-32,-60.0,0.0);
        glEnd();

        //swimming pool middle border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glVertex3f(25,-40,0.0);
        glVertex3f(25,-42,0.0);
        glVertex3f(-25,-42,0.0);
        glEnd();

        //lamp post 1st
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-40,-30,0.0);
        glVertex3f(-40,-18,0.0);
        glVertex3f(-39,-18,0.0);
        glVertex3f(-39,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-39.5,-18);

        //lamp post 2nd
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-15,-30,0.0);
        glVertex3f(-15,-18,0.0);
        glVertex3f(-14,-18,0.0);
        glVertex3f(-14,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-14.5,-18);

        //lamp post 3rd
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(10,-30,0.0);
        glVertex3f(10,-18,0.0);
        glVertex3f(9,-18,0.0);
        glVertex3f(9,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,9.5,-18);

        //lamp post 4th
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(35,-30,0.0);
        glVertex3f(35,-18,0.0);
        glVertex3f(34,-18,0.0);
        glVertex3f(34,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,34.5,-18);

        //lamp post left
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-35,-42,0.0);
        glVertex3f(-34,-42,0.0);
        glVertex3f(-34,-54,0.0);
        glVertex3f(-35,-54.0,0.0);
        glEnd();

        //lamp post left road circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-34.5,-42);

        //lamp post right
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(37,-42,0.0);
        glVertex3f(38,-42,0.0);
        glVertex3f(38,-54,0.0);
        glVertex3f(37,-54.0,0.0);
        glEnd();

        //lamp post right road circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,37.5,-42);

        //main road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-50,-30,0.0);
        glVertex3f(50,-30,0.0);
        glVertex3f(50,-40,0.0);
        glVertex3f(-50,-40.0,0.0);
        glEnd();

        //main road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-50,-34.5,0.0);
        glVertex3f(-45,-34.5,0.0);
        glVertex3f(-45,-35.5,0.0);
        glVertex3f(-50,-35.5,0.0);
        glEnd();

        //main road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-40,-34.5,0.0);
        glVertex3f(-35,-34.5,0.0);
        glVertex3f(-35,-35.5,0.0);
        glVertex3f(-40,-35.5,0.0);
        glEnd();

        //main road 3rd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-30,-34.5,0.0);
        glVertex3f(-25,-34.5,0.0);
        glVertex3f(-25,-35.5,0.0);
        glVertex3f(-30,-35.5,0.0);
        glEnd();

        //main road 4th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-20,-34.5,0.0);
        glVertex3f(-15,-34.5,0.0);
        glVertex3f(-15,-35.5,0.0);
        glVertex3f(-20,-35.5,0.0);
        glEnd();

        //main road 5th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-10,-34.5,0.0);
        glVertex3f(-5,-34.5,0.0);
        glVertex3f(-5,-35.5,0.0);
        glVertex3f(-10,-35.5,0.0);
        glEnd();

        //main road 6th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(0,-34.5,0.0);
        glVertex3f(5,-34.5,0.0);
        glVertex3f(5,-35.5,0.0);
        glVertex3f(0,-35.5,0.0);
        glEnd();

        //main road 7th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(10,-34.5,0.0);
        glVertex3f(15,-34.5,0.0);
        glVertex3f(15,-35.5,0.0);
        glVertex3f(10,-35.5,0.0);
        glEnd();

        //main road 8th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(20,-34.5,0.0);
        glVertex3f(25,-34.5,0.0);
        glVertex3f(25,-35.5,0.0);
        glVertex3f(20,-35.5,0.0);
        glEnd();

        //main road 9th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(30,-34.5,0.0);
        glVertex3f(35,-34.5,0.0);
        glVertex3f(35,-35.5,0.0);
        glVertex3f(30,-35.5,0.0);
        glEnd();

        //main road 10th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(40,-34.5,0.0);
        glVertex3f(45,-34.5,0.0);
        glVertex3f(45,-35.5,0.0);
        glVertex3f(40,-35.5,0.0);
        glEnd();

        //main road 10th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(49,-34.5,0.0);
        glVertex3f(50,-34.5,0.0);
        glVertex3f(50,-35.5,0.0);
        glVertex3f(49,-35.5,0.0);
        glEnd();

        //left road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-30,-40,0.0);
        glVertex3f(-25,-40,0.0);
        glVertex3f(-32,-60,0.0);
        glVertex3f(-38,-60.0,0.0);
        glEnd();

        //left road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-28.5,-41,0.0);
        glVertex3f(-27.5,-41,0.0);
        glVertex3f(-29.5,-46,0.0);
        glVertex3f(-30.5,-46,0.0);
        glEnd();

        //left road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-32,-52,0.0);
        glVertex3f(-31,-52,0.0);
        glVertex3f(-33,-57,0.0);
        glVertex3f(-34,-57,0.0);
        glEnd();

        //right road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(25,-40,0.0);
        glVertex3f(30,-40,0.0);
        glVertex3f(43,-60,0.0);
        glVertex3f(36,-60.0,0.0);
        glEnd();

        //right road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(27.5,-41,0.0);
        glVertex3f(28.5,-41,0.0);
        glVertex3f(31.5,-46,0.0);
        glVertex3f(30.5,-46.0,0.0);
        glEnd();

        //right road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(33.5,-51,0.0);
        glVertex3f(34.5,-51,0.0);
        glVertex3f(37.5,-56,0.0);
        glVertex3f(36.5,-56.0,0.0);
        glEnd();

        //right road 3rd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(38,-59,0.0);
        glVertex3f(39,-59,0.0);
        glVertex3f(40,-60,0.0);
        glVertex3f(39,-60.0,0.0);
        glEnd();

        //flag stand
        glColor3f(0.85, 0.85, 0.85);
        glBegin(GL_QUADS);
        glVertex3f(-0.2,-5,0.0);
        glVertex3f(-0.2,20,0.0);
        glVertex3f(0.2,20,0.0);
        glVertex3f(0.2,-5.0,0.0);
        glEnd();

        //flag
        glColor3f(0, 0.4, 0.28);
        glBegin(GL_QUADS);
        glVertex3f(0.3,13,0.0);
        glVertex3f(0.3,20,0.0);
        glVertex3f(8,20,0.0);
        glVertex3f(8,13.0,0.0);
        glEnd();

        //flag circle
        glColor3f(0.85, 0.16, 0.11);
        circle(1.8,1.8,4.15,16.5);

        //Border: left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-45,-5,0.0);
        glVertex3f(-45,28,0.0);
        glEnd();

        //Border: top left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,35,0.0);
        glVertex3f(-45,28,0.0);
        glEnd();

        //Border: left right building top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,35,0.0);
        glVertex3f(-15,33.5,0.0);
        glEnd();

        //Border: top middle left end side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-20,34,0.0);
        glVertex3f(-20,42,0.0);
        glEnd();

        //Border: top middle left corner side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-11,45,0.0);
        glVertex3f(-20,42,0.0);
        glEnd();

        //Border: top middle upper side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-11,45,0.0);
        glVertex3f(11,45,0.0);
        glEnd();

        //Border: top middle right corner side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(20,42,0.0);
        glVertex3f(11,45,0.0);
        glEnd();

        //Border: top middel right end side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(20,42,0.0);
        glVertex3f(20,34,0.0);
        glEnd();

        //Border: right-left to middle buliding top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(15,33.5,0.0);
        glEnd();

        //Border: middle to right buliding top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(45,28,0.0);
        glEnd();

        //Border: right side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(45,-5,0.0);
        glVertex3f(45,28,0.0);
        glEnd();

        //Border: middle left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-15,40,0.0);
        glVertex3f(-5,37,0.0);
        glEnd();

        //Border: middle right side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(15,40,0.0);
        glVertex3f(5,37,0.0);
        glEnd();

        //Cloud left: top circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+10,57);

        //Cloud left: left circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+8,55);

        //Cloud left: right circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+12,55);

        //Cloud left: bottom circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+10,53);

        //Cloud right: top circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+22,53);

        //Cloud right: left circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+20,51);

        //Cloud right: right circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+24,51);

        //Cloud right: bottom circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+22,49);

        //car shape
        glColor3f(0.1, 0.11, 0.34);
        glBegin(GL_POLYGON);
        glVertex3f(-p-10,-35,0.0);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-5,-27.0,0.0);
        glVertex3f(-p+1.0,-20.0,0.0);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+20.0,-23.0,0.0);
        glVertex3f(-p+20.0,-35.0,0.0);
        glEnd();

        //car left window
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+4,-20,0.0);
        glVertex3f(-p+5,-20,0.0);
        glVertex3f(-p+5,-27,0.0);
        glVertex3f(-p+4,-27,0.0);
        glEnd();

        //car right window
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+10,-20,0.0);
        glVertex3f(-p+11,-20,0.0);
        glVertex3f(-p+11,-27,0.0);
        glVertex3f(-p+10,-27,0.0);
        glEnd();

        //car middle shape
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p+20,-27,0.0);
        glVertex3f(-p+20,-27.5,0.0);
        glVertex3f(-p-10,-27.5,0.0);
        glEnd();

        //car spare tyre
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-25,0.0);
        glVertex3f(-p+22,-25,0.0);
        glVertex3f(-p+22,-31,0.0);
        glVertex3f(-p+20,-31,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-35,0.0);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-9.8,-27,0.0);
        glVertex3f(-p-9.8,-35,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-5,-27,0.0);
        glVertex3f(-p+1,-20,0.0);
        glVertex3f(-p+1.3,-20,0.0);
        glVertex3f(-p-4.7,-27,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-p+1,-20,0.0);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+15,-20.3,0.0);
        glVertex3f(-p+1,-20.3,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-35,0.0);
        glVertex3f(-p+20,-34.7,0.0);
        glVertex3f(-p-10,-34.7,0.0);
        glVertex3f(-p-10,-35,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-23,0.0);
        glVertex3f(-p+20,-35,0.0);
        glVertex3f(-p+19.8,-35,0.0);
        glVertex3f(-p+19.8,-23,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+20,-23,0.0);
        glVertex3f(-p+20.0,-23.3,0);
        glVertex3f(-p+15,-20.3,0.0);
        glEnd();

        //car left tyre
        glColor3f(0,0,0);
        circle(2.5,2.5,-p-2,-35);

        //car left tyre rim
        glColor3f(1,1,1);
        circle(1.5,1.5,-p-2,-35);

        //car left tyre bottom rim
        glColor3f(0,0,0);
        circle(0.5,0.5,-p-2,-35);

        //car right tyre
        glColor3f(0,0,0);
        circle(2.5,2.5,-p+13.5,-35);

        //car righr tyre rim
        glColor3f(1,1,1);
        circle(1.5,1.5,-p+13.5,-35);

        //car righr tyre bottom rim
        glColor3f(0,0,0);
        circle(0.5,0.5,-p+13.5,-35);

        //car flag stand
        glColor3f(0.85, 0.85, 0.85);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-10,-23,0.0);
        glVertex3f(-p-9.7,-23,0.0);
        glVertex3f(-p-9.7,-27,0.0);
        glEnd();

        //car flag
        glColor3f(0,0.4,0.28);
        glBegin(GL_QUADS);
        glVertex3f(-p-9.7,-23,0.0);
        glVertex3f(-p-7.7,-23,0.0);
        glVertex3f(-p-7.7,-25,0.0);
        glVertex3f(-p-9.7,-25,0.0);
        glEnd();

        //car flag circle
        glColor3f(0.85, 0.16, 0.11);
        circle(0.3,0.3,-p-8.7,-24);

        //left bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+5,46,0.0);
        glVertex3f(b+6,45,0.0);
        glEnd();

        //left bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+6,45,0.0);
        glVertex3f(b+7,46,0.0);
        glEnd();

        //middle bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+8,46,0.0);
        glVertex3f(b+9,45,0.0);
        glEnd();

        //middle bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+9,45,0.0);
        glVertex3f(b+10,46,0.0);
        glEnd();

        //right bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+11,46,0.0);
        glVertex3f(b+12,45,0.0);
        glEnd();

        //right bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+12,45,0.0);
        glVertex3f(b+13,46,0.0);
        glEnd();

        //bottom left bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+6,44,0.0);
        glVertex3f(b+7,43,0.0);
        glEnd();

        //bottom left bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+7,43,0.0);
        glVertex3f(b+8,44,0.0);
        glEnd();

        //bottom middle bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+9,44,0.0);
        glVertex3f(b+10,43,0.0);
        glEnd();

        //bottom middle bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+10,43,0.0);
        glVertex3f(b+11,44,0.0);
        glEnd();

        //bottom right bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+12,44,0.0);
        glVertex3f(b+13,43,0.0);
        glEnd();

        //bottom right bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+13,43,0.0);
        glVertex3f(b+14,44,0.0);
        glEnd();

        //Sun
        glColor3f(0.99, 0.21, 0.09);
        circle(3.2,3.2,42,53);

    }

    else if( n ==1)
    {

        //background sky
        glColor3f(0.28, 0.2, 0.46);
        glBegin(GL_QUADS);
        glVertex3f(-50,-5.0,0.0);
        glColor3f(0.28, 0.2, 0.46);
        glVertex3f(-50,60.0,0.0);
        glColor3f(0.08, 0.09, 0.32);
        glVertex3f(50,60.0,0.0);
        glColor3f(0.03, 0.04, 0.2);
        glVertex3f(50.0,-5.0,0.0);
        glEnd();

        //moon
        glColor3f(0.91, 0.91, 0.93);
        circle(3.2,3.2,-45,m);

        if(m<=55)
            m=m+0.010;

        //top middle building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_POLYGON);
        glVertex3f(-5,33.5,0.0);
        glVertex3f(-20,34.0,0.0);
        glVertex3f(-20,42.0,0.0);
        glVertex3f(-11.0,45.0,0.0);
        glVertex3f(11,45.0,0.0);
        glVertex3f(20.0,42.0,0.0);
        glVertex3f(20,34.0,0.0);
        glVertex3f(15.0,33.5,0.0);
        glVertex3f(15,40.0,0.0);
        glVertex3f(5.0,37,0.0);
        glVertex3f(-5,37.0,0.0);
        glVertex3f(-15.0,40.0,0.0);
        glEnd();

        //top middle shape
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-5,37,0.0);
        glVertex3f(-10,38,0.0);
        glVertex3f(-10,40.0,0.0);
        glVertex3f(10.0,40.0,0.0);
        glVertex3f(10,38,0.0);
        glVertex3f(5.0,37.0,0.0);
        glEnd();

        //left building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-45,-5,0.0);
        glVertex3f(-45,28.0,0.0);
        glVertex3f(-35,31.5,0.0);
        glEnd();

        //left middle building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-35,31.5,0.0);
        glVertex3f(-25,35,0.0);
        glVertex3f(-25,-5.0,0.0);
        glEnd();

        //border between left & middle left building
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-35,-5,0.0);
        glVertex3f(-35.5,-5,0.0);
        glVertex3f(-35.5,31,0.0);
        glVertex3f(-35,31.5,0.0);

        glEnd();

        //left-right building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-25,-5,0.0);
        glVertex3f(-25,35,0.0);
        glVertex3f(-15,34,0.0);
        glVertex3f(-15,-5.0,0.0);
        glEnd();

        //line between left middle & left-right building
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,-5,0.0);
        glVertex3f(-25,35,0.0);
        glEnd();

        //right building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(35,31.5,0);
        glVertex3f(45,28.0,0.0);
        glVertex3f(45,-5,0.0);
        glEnd();

        //right middle building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(25,-5,0.0);
        glVertex3f(25,35,0.0);
        glVertex3f(35,31.5,0.0);
        glEnd();

        //border between right & middle right building
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(35,-5,0.0);
        glVertex3f(35,31.5,0.0);
        glVertex3f(35.5,31,0.0);
        glVertex3f(35.5,-5,0.0);
        glEnd();

        //right left middle building
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(25,-5,0.0);
        glVertex3f(15,-5,0.0);
        glVertex3f(15,33.5,0.0);
        glVertex3f(25,35,0.0);
        glEnd();

        //lines between right left-middle building
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(25,-5,0.0);
        glEnd();

        //middle left bulding
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-15,-5,0.0);
        glVertex3f(-15,40,0.0);
        glVertex3f(-5,37,0.0);
        glVertex3f(-5,-5,0.0);
        glEnd();

        //middle right bulding
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(5,-5,0.0);
        glVertex3f(5,37,0.0);
        glVertex3f(15,40,0.0);
        glVertex3f(15,-5,0.0);
        glEnd();

        //middle left bulding left line
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-15,-5,0.0);
        glVertex3f(-15,40,0.0);
        glEnd();

        //middle right bulding right line
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(15,-5,0.0);
        glVertex3f(15,40,0.0);
        glEnd();

        //middle  bulding
        glColor3f(0.44, 0.34, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-5,-5,0.0);
        glVertex3f(-5,37,0.0);
        glVertex3f(15,37,0.0);
        glVertex3f(5,-5,0.0);
        glEnd();

        //middle bulding letf border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-5,-5,0.0);
        glVertex3f(-5.5,-5,0.0);
        glVertex3f(-5.5,37,0.0);
        glVertex3f(-5,37,0.0);
        glEnd();

        //middle bulding right border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(5,-5,0.0);
        glVertex3f(5,37,0.0);
        glVertex3f(5.5,37,0.0);
        glVertex3f(5.5,-5,0.0);
        glEnd();

        //left building triangle
        glColor3f(0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(-34,7,0.0);
        glVertex3f(-30,32,0.0);
        glVertex3f(-26,7.0,0.0);
        glEnd();

        //right building triangle
        glColor3f(0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex3f(16,7,0.0);
        glVertex3f(20,32,0.0);
        glVertex3f(24,7.0,0.0);
        glEnd();

        //left bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-34,-5,0.0);
        glVertex3f(-34,5,0.0);
        glVertex3f(-26,5,0.0);
        glVertex3f(-26,-5,0.0);
        glEnd();

        //right bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(16,-5,0.0);
        glVertex3f(16,5,0.0);
        glVertex3f(24,5,0.0);
        glVertex3f(24,-5,0.0);
        glEnd();

        //middle bulding box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-4,-5,0.0);
        glVertex3f(-4,5,0.0);
        glVertex3f(4,5,0.0);
        glVertex3f(4,-5,0.0);
        glEnd();

        //middle bulding small box
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-2,8,0.0);
        glVertex3f(-2,10,0.0);
        glVertex3f(2,10,0.0);
        glVertex3f(2,8,0.0);
        glEnd();

        //stairs area
        glColor3f(0.64, 0.2, 0.08);
        glBegin(GL_QUADS);
        glVertex3f(-50,-15,0.0);
        glVertex3f(-50,-5,0.0);
        glVertex3f(50,-5,0.0);
        glVertex3f(50,-15.0,0.0);
        glEnd();

        //1st line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-5,0.0);
        glVertex3f(50,-5,0.0);
        glEnd();

        //2nd line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-7,0.0);
        glVertex3f(50,-7,0.0);
        glEnd();

        //3rd line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-9,0.0);
        glVertex3f(50,-9,0.0);
        glEnd();

        //4th line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-11,0.0);
        glVertex3f(50,-11,0.0);
        glEnd();

        //5thth line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-13,0.0);
        glVertex3f(50,-13,0.0);
        glEnd();

        //6th line stairs
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-50,-15,0.0);
        glVertex3f(50,-15,0.0);
        glEnd();

        //stairs middle shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-2,-15,0.0);
        glVertex3f(-1,-5,0.0);
        glVertex3f(1,-5,0.0);
        glVertex3f(2,-15.0,0.0);
        glEnd();

        //stairs left shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-33,-15,0.0);
        glVertex3f(-30,-5,0.0);
        glVertex3f(-28,-5,0.0);
        glVertex3f(-31,-15.0,0.0);
        glEnd();

        //stairs right shape
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(25,-15,0.0);
        glVertex3f(20,-5,0.0);
        glVertex3f(22,-5,0.0);
        glVertex3f(27,-15.0,0.0);
        glEnd();

        //middle field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(-50,-15,0.0);
        glVertex3f(-50,-30,0.0);
        glVertex3f(50,-30,0.0);
        glVertex3f(50,-15.0,0.0);
        glEnd();

        //swimming pool
        glColor3f(0.06, 0.37, 0.61);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glColor3f(0.14, 0.54, 0.85);
        glVertex3f(25,-40,0.0);
        glColor3f(0.11, 0.64, 0.93);
        glVertex3f(36,-60,0.0);
        glColor3f(0.35, 0.74, 0.85);
        glVertex3f(-32,-60.0,0.0);
        glEnd();

        // wave 1st
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-37,-45,0.0);
        glVertex3f(w-33,-45,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-36,-44.5,0.0);
        glVertex3f(w-31,-44.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-36.5,-45.5,0.0);
        glVertex3f(w-33,-45.5,0.0);
        glEnd();

        // wave 2nd
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-39,-55,0.0);
        glVertex3f(w-35,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-38,-54.5,0.0);
        glVertex3f(w-33,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-38.5,-55.5,0.0);
        glVertex3f(w-35,-55.5,0.0);
        glEnd();

        // wave 4th
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-54,-50,0.0);
        glVertex3f(w-49,-50,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-53,-49.5,0.0);
        glVertex3f(w-48,-49.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-53.5,-50.5,0.0);
        glVertex3f(w-50,-50.5,0.0);
        glEnd();

        // wave left
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-22,-50,0.0);
        glVertex3f(w-18,-50,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-21,-49.5,0.0);
        glVertex3f(w-16,-49.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-21.5,-50.5,0.0);
        glVertex3f(w-17,-50.5,0.0);
        glEnd();

        // wave right
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+0,-46,0.0);
        glVertex3f(w+4,-46,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+1,-45.5,0.0);
        glVertex3f(w+6,-45.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+0.5,-46.5,0.0);
        glVertex3f(w+5,-46.5,0.0);
        glEnd();


        //wave lower left
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-7,-55,0.0);
        glVertex3f(w-3,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-6,-54.5,0.0);
        glVertex3f(w-1,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w-6.5,-55.5,0.0);
        glVertex3f(w-2,-55.5,0.0);
        glEnd();

        //wave lower right
        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+10,-55,0.0);
        glVertex3f(w+14,-55,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+11,-54.5,0.0);
        glVertex3f(w+16,-54.5,0.0);
        glEnd();

        glColor3f(0.28, 0.28, 0.3);
        glBegin(GL_LINES);
        glVertex3f(w+11.5,-55.5,0.0);
        glVertex3f(w+15,-55.5,0.0);
        glEnd();

        //left field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(-50,-40,0.0);
        glVertex3f(-30,-40,0.0);
        glVertex3f(-36,-60,0.0);
        glVertex3f(-50,-60.0,0.0);
        glEnd();

        //right field
        glColor3f(0.18, 0.97, 0.01);
        glBegin(GL_QUADS);
        glVertex3f(30,-40,0.0);
        glVertex3f(50,-40,0.0);
        glVertex3f(50,-60,0.0);
        glVertex3f(38,-60.0,0.0);
        glEnd();

        //swimming pool left border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glVertex3f(-23.5,-40,0.0);
        glVertex3f(-30.5,-60,0.0);
        glVertex3f(-32,-60.0,0.0);
        glEnd();

        //swimming pool right border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(23.5,-40,0.0);
        glVertex3f(25,-40,0.0);
        glVertex3f(36,-60,0.0);
        glVertex3f(34.5,-60.0,0.0);
        glEnd();

        //swimming pool middle border
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-25,-40,0.0);
        glVertex3f(25,-40,0.0);
        glVertex3f(25,-42,0.0);
        glVertex3f(-25,-42,0.0);
        glEnd();

        //lamp post 1st
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-40,-30,0.0);
        glVertex3f(-40,-18,0.0);
        glVertex3f(-39,-18,0.0);
        glVertex3f(-39,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-39.5,-18);

        //lamp post 2nd
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-15,-30,0.0);
        glVertex3f(-15,-18,0.0);
        glVertex3f(-14,-18,0.0);
        glVertex3f(-14,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-14.5,-18);

        //lamp post 3rd
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(10,-30,0.0);
        glVertex3f(10,-18,0.0);
        glVertex3f(9,-18,0.0);
        glVertex3f(9,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,9.5,-18);

        //lamp post 4th
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(35,-30,0.0);
        glVertex3f(35,-18,0.0);
        glVertex3f(34,-18,0.0);
        glVertex3f(34,-30.0,0.0);
        glEnd();

        //lamp post circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,34.5,-18);

        //lamp post left
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-35,-42,0.0);
        glVertex3f(-34,-42,0.0);
        glVertex3f(-34,-54,0.0);
        glVertex3f(-35,-54.0,0.0);
        glEnd();

        //lamp post left road circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,-34.5,-42);

        //lamp post right
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(37,-42,0.0);
        glVertex3f(38,-42,0.0);
        glVertex3f(38,-54,0.0);
        glVertex3f(37,-54.0,0.0);
        glEnd();

        //lamp post right road circle
        glColor3f(1, 0.97, 0.87);
        circle(1.8,1.8,37.5,-42);

        //main road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-50,-30,0.0);
        glVertex3f(50,-30,0.0);
        glVertex3f(50,-40,0.0);
        glVertex3f(-50,-40.0,0.0);
        glEnd();

        //main road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-50,-34.5,0.0);
        glVertex3f(-45,-34.5,0.0);
        glVertex3f(-45,-35.5,0.0);
        glVertex3f(-50,-35.5,0.0);
        glEnd();

        //main road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-40,-34.5,0.0);
        glVertex3f(-35,-34.5,0.0);
        glVertex3f(-35,-35.5,0.0);
        glVertex3f(-40,-35.5,0.0);
        glEnd();

        //main road 3rd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-30,-34.5,0.0);
        glVertex3f(-25,-34.5,0.0);
        glVertex3f(-25,-35.5,0.0);
        glVertex3f(-30,-35.5,0.0);
        glEnd();

        //main road 4th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-20,-34.5,0.0);
        glVertex3f(-15,-34.5,0.0);
        glVertex3f(-15,-35.5,0.0);
        glVertex3f(-20,-35.5,0.0);
        glEnd();

        //main road 5th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-10,-34.5,0.0);
        glVertex3f(-5,-34.5,0.0);
        glVertex3f(-5,-35.5,0.0);
        glVertex3f(-10,-35.5,0.0);
        glEnd();

        //main road 6th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(0,-34.5,0.0);
        glVertex3f(5,-34.5,0.0);
        glVertex3f(5,-35.5,0.0);
        glVertex3f(0,-35.5,0.0);
        glEnd();

        //main road 7th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(10,-34.5,0.0);
        glVertex3f(15,-34.5,0.0);
        glVertex3f(15,-35.5,0.0);
        glVertex3f(10,-35.5,0.0);
        glEnd();

        //main road 8th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(20,-34.5,0.0);
        glVertex3f(25,-34.5,0.0);
        glVertex3f(25,-35.5,0.0);
        glVertex3f(20,-35.5,0.0);
        glEnd();

        //main road 9th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(30,-34.5,0.0);
        glVertex3f(35,-34.5,0.0);
        glVertex3f(35,-35.5,0.0);
        glVertex3f(30,-35.5,0.0);
        glEnd();

        //main road 10th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(40,-34.5,0.0);
        glVertex3f(45,-34.5,0.0);
        glVertex3f(45,-35.5,0.0);
        glVertex3f(40,-35.5,0.0);
        glEnd();

        //main road 10th lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(49,-34.5,0.0);
        glVertex3f(50,-34.5,0.0);
        glVertex3f(50,-35.5,0.0);
        glVertex3f(49,-35.5,0.0);
        glEnd();

        //left road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(-30,-40,0.0);
        glVertex3f(-25,-40,0.0);
        glVertex3f(-32,-60,0.0);
        glVertex3f(-38,-60.0,0.0);
        glEnd();

        //left road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-28.5,-41,0.0);
        glVertex3f(-27.5,-41,0.0);
        glVertex3f(-29.5,-46,0.0);
        glVertex3f(-30.5,-46,0.0);
        glEnd();

        //left road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(-32,-52,0.0);
        glVertex3f(-31,-52,0.0);
        glVertex3f(-33,-57,0.0);
        glVertex3f(-34,-57,0.0);
        glEnd();

        //right road
        glColor3f(0.18, 0.18, 0.18);
        glBegin(GL_QUADS);
        glVertex3f(25,-40,0.0);
        glVertex3f(30,-40,0.0);
        glVertex3f(43,-60,0.0);
        glVertex3f(36,-60.0,0.0);
        glEnd();

        //right road 1st lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(27.5,-41,0.0);
        glVertex3f(28.5,-41,0.0);
        glVertex3f(31.5,-46,0.0);
        glVertex3f(30.5,-46.0,0.0);
        glEnd();

        //right road 2nd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(33.5,-51,0.0);
        glVertex3f(34.5,-51,0.0);
        glVertex3f(37.5,-56,0.0);
        glVertex3f(36.5,-56.0,0.0);
        glEnd();

        //right road 3rd lane
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f(38,-59,0.0);
        glVertex3f(39,-59,0.0);
        glVertex3f(40,-60,0.0);
        glVertex3f(39,-60.0,0.0);
        glEnd();

        //flag stand
        glColor3f(0.85, 0.85, 0.85);
        glBegin(GL_QUADS);
        glVertex3f(-0.2,-5,0.0);
        glVertex3f(-0.2,20,0.0);
        glVertex3f(0.2,20,0.0);
        glVertex3f(0.2,-5.0,0.0);
        glEnd();

        //flag
        glColor3f(0, 0.4, 0.28);
        glBegin(GL_QUADS);
        glVertex3f(0.3,13,0.0);
        glVertex3f(0.3,20,0.0);
        glVertex3f(8,20,0.0);
        glVertex3f(8,13.0,0.0);
        glEnd();

        //flag circle
        glColor3f(0.85, 0.16, 0.11);
        circle(1.8,1.8,4.15,16.5);

        //Border: left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-45,-5,0.0);
        glVertex3f(-45,28,0.0);
        glEnd();

        //Border: top left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,35,0.0);
        glVertex3f(-45,28,0.0);
        glEnd();

        //Border: left right building top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-25,35,0.0);
        glVertex3f(-15,33.5,0.0);
        glEnd();

        //Border: top middle left end side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-20,34,0.0);
        glVertex3f(-20,42,0.0);
        glEnd();

        //Border: top middle left corner side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-11,45,0.0);
        glVertex3f(-20,42,0.0);
        glEnd();

        //Border: top middle upper side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-11,45,0.0);
        glVertex3f(11,45,0.0);
        glEnd();

        //Border: top middle right corner side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(20,42,0.0);
        glVertex3f(11,45,0.0);
        glEnd();

        //Border: top middel right end side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(20,42,0.0);
        glVertex3f(20,34,0.0);
        glEnd();

        //Border: right-left to middle buliding top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(15,33.5,0.0);
        glEnd();

        //Border: middle to right buliding top side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(25,35,0.0);
        glVertex3f(45,28,0.0);
        glEnd();

        //Border: right side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(45,-5,0.0);
        glVertex3f(45,28,0.0);
        glEnd();

        //Border: middle left side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-15,40,0.0);
        glVertex3f(-5,37,0.0);
        glEnd();

        //Border: middle right side
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(15,40,0.0);
        glVertex3f(5,37,0.0);
        glEnd();

        //Cloud left: top circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+10,57);

        //Cloud left: left circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+8,55);

        //Cloud left: right circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+12,55);

        //Cloud left: bottom circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+10,53);

        //Cloud right: top circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+22,53);

        //Cloud right: left circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+20,51);

        //Cloud right: right circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+24,51);

        //Cloud right: bottom circle
        glColor3f(0.95, 0.95, 0.93);
        circle(2.5,2.5,c+22,49);

        //car shape
        glColor3f(0.1, 0.11, 0.34);
        glBegin(GL_POLYGON);
        glVertex3f(-p-10,-35,0.0);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-5,-27.0,0.0);
        glVertex3f(-p+1.0,-20.0,0.0);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+20.0,-23.0,0.0);
        glVertex3f(-p+20.0,-35.0,0.0);
        glEnd();

        //car left window
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+4,-20,0.0);
        glVertex3f(-p+5,-20,0.0);
        glVertex3f(-p+5,-27,0.0);
        glVertex3f(-p+4,-27,0.0);
        glEnd();

        //car right window
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+10,-20,0.0);
        glVertex3f(-p+11,-20,0.0);
        glVertex3f(-p+11,-27,0.0);
        glVertex3f(-p+10,-27,0.0);
        glEnd();

        //car middle shape
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p+20,-27,0.0);
        glVertex3f(-p+20,-27.5,0.0);
        glVertex3f(-p-10,-27.5,0.0);
        glEnd();

        //car spare tyre
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-25,0.0);
        glVertex3f(-p+22,-25,0.0);
        glVertex3f(-p+22,-31,0.0);
        glVertex3f(-p+20,-31,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-35,0.0);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-9.8,-27,0.0);
        glVertex3f(-p-9.8,-35,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p-5,-27,0.0);
        glVertex3f(-p+1,-20,0.0);
        glVertex3f(-p+1.3,-20,0.0);
        glVertex3f(-p-4.7,-27,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-p+1,-20,0.0);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+15,-20.3,0.0);
        glVertex3f(-p+1,-20.3,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-35,0.0);
        glVertex3f(-p+20,-34.7,0.0);
        glVertex3f(-p-10,-34.7,0.0);
        glVertex3f(-p-10,-35,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex3f(-p+20,-23,0.0);
        glVertex3f(-p+20,-35,0.0);
        glVertex3f(-p+19.8,-35,0.0);
        glVertex3f(-p+19.8,-23,0.0);
        glEnd();

        //car border:
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(-p+15,-20,0.0);
        glVertex3f(-p+20,-23,0.0);
        glVertex3f(-p+20.0,-23.3,0);
        glVertex3f(-p+15,-20.3,0.0);
        glEnd();

        //car left tyre
        glColor3f(0,0,0);
        circle(2.5,2.5,-p-2,-35);

        //car left tyre rim
        glColor3f(1,1,1);
        circle(1.5,1.5,-p-2,-35);

        //car left tyre bottom rim
        glColor3f(0,0,0);
        circle(0.5,0.5,-p-2,-35);

        //car right tyre
        glColor3f(0,0,0);
        circle(2.5,2.5,-p+13.5,-35);

        //car righr tyre rim
        glColor3f(1,1,1);
        circle(1.5,1.5,-p+13.5,-35);

        //car righr tyre bottom rim
        glColor3f(0,0,0);
        circle(0.5,0.5,-p+13.5,-35);

        //car flag stand
        glColor3f(0.85, 0.85, 0.85);
        glBegin(GL_QUADS);
        glVertex3f(-p-10,-27,0.0);
        glVertex3f(-p-10,-23,0.0);
        glVertex3f(-p-9.7,-23,0.0);
        glVertex3f(-p-9.7,-27,0.0);
        glEnd();

        //car flag
        glColor3f(0,0.4,0.28);
        glBegin(GL_QUADS);
        glVertex3f(-p-9.7,-23,0.0);
        glVertex3f(-p-7.7,-23,0.0);
        glVertex3f(-p-7.7,-25,0.0);
        glVertex3f(-p-9.7,-25,0.0);
        glEnd();

        //car flag circle
        glColor3f(0.85, 0.16, 0.11);
        circle(0.3,0.3,-p-8.7,-24);

        //left bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+5,46,0.0);
        glVertex3f(b+6,45,0.0);
        glEnd();

        //left bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+6,45,0.0);
        glVertex3f(b+7,46,0.0);
        glEnd();

        //middle bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+8,46,0.0);
        glVertex3f(b+9,45,0.0);
        glEnd();

        //middle bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+9,45,0.0);
        glVertex3f(b+10,46,0.0);
        glEnd();

        //right bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+11,46,0.0);
        glVertex3f(b+12,45,0.0);
        glEnd();

        //right bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+12,45,0.0);
        glVertex3f(b+13,46,0.0);
        glEnd();

        //bottom left bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+6,44,0.0);
        glVertex3f(b+7,43,0.0);
        glEnd();

        //bottom left bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+7,43,0.0);
        glVertex3f(b+8,44,0.0);
        glEnd();

        //bottom middle bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+9,44,0.0);
        glVertex3f(b+10,43,0.0);
        glEnd();

        //bottom middle bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+10,43,0.0);
        glVertex3f(b+11,44,0.0);
        glEnd();

        //bottom right bird left wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+12,44,0.0);
        glVertex3f(b+13,43,0.0);
        glEnd();

        //bottom right bird right wings
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex3f(b+13,43,0.0);
        glVertex3f(b+14,44,0.0);
        glEnd();

        //stars point
        glColor3f(0.91, 0.91, 0.93);
        circle(0.1,0.1, -10,55);
        circle(0.1,0.1, -18,58);
        circle(0.1,0.1, -23,49);
        circle(0.1,0.1, -48,43);
        circle(0.1,0.1, -10,59);
        circle(0.1,0.1, -47,54);
        circle(0.1,0.1, 7,56);
        circle(0.1,0.1, 13,48);
        circle(0.1,0.1, 25,55);
        circle(0.1,0.1, 37,53);
        circle(0.1,0.1, 49,57);
        circle(0.1,0.1, 41,45);

        starPack();
    }

    leaf();

    glPushMatrix();
    glTranslatef(f-40,-50,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f-20,-55,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f+0,-50,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f-30,-53,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f-10,-53,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f-40,-60,0);
    leaf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(f-1,-60,0);
    leaf();
    glPopMatrix();

    box();


    //car
    if(p<=50)
        p=p+0.012;
    else
        p=-50;


    //bird
    if(b<=50)
        b=b+0.010;
    else
        b=-50;


    //cloud
    if(c<=50)
        c=c+0.0035;
    else
        c=-50;


    //wave
    if(w<=42)
        w=w+0.0035;
    else
        w=-5;


    //flower
    if(f<=5)
        f=f+0.00095;
    else
        f=-5;


    glutPostRedisplay();
    glFlush();

}

void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'n'://night view


        n=1;
        d=0;
        glutPostRedisplay();
        break;

    case 'd'://day view
        d=1;
        n=0;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    shams();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(600,50);
    glutInitWindowSize(900,800);
    glutCreateWindow("National Parliament");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
