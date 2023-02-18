#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<GL/glut.h>

void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void display(char *text, int length){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    for(i=0;i<length;i++){
        glRasterPos2i(10+i,20);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2i(10,18);
    glVertex2i(18,18);
    glEnd();
    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(200,200);
    glutCreateWindow("The Island");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
