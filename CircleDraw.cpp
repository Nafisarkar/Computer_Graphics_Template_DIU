#include <GL/glut.h>
#include <iostream>
#include <windows.h>



void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-4, 4, -4, 4, -4, 4);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(G);



}


int main(){
    glutInit(&argc, argv);
    glutCreateWindow("Simple Circle");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}