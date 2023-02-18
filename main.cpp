#include<windows.h>
#include<GL/glut.h>

char ajn[]="Aaron Jevil Nazareth   4nm20cs005";
int length=33;

void init(void){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void display(){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    for(i=0;i<length;i++){
        glRasterPos2i(10+i,20);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
    glEnd();
    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("The Island");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
