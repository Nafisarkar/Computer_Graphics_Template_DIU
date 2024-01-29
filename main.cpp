#include <GL/glew.h>
#include <GL/freeglut.h>
#include <cstdio>

void display() {
    // OpenGL rendering code goes here
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Window");
    glutDisplayFunc(display);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        return 1;
    }

    glutMainLoop();
    return 0;
}
