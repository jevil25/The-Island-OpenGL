#include<windows.h>
#include<GL/glut.h>

void init(void){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void display(){
    char ajn[]="Aaron Jevil Nazareth   4nm20cs005";
    char afd[]="Aaron Francis Dsouza   4nm20cs004";
    char projectName[]="The Island";
    int i,name_usn_length=33, projectName_length=10;
    glClear(GL_COLOR_BUFFER_BIT);
    for(i=0;i<projectName_length;i++){
        glRasterPos2i(20+i,45);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,projectName[i]);
    }
    for(i=0;i<name_usn_length;i++){
        glRasterPos2i(10+i,40);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ajn[i]);
    }
    for(i=0;i<name_usn_length;i++){
        glRasterPos2i(10+i,38);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,afd[i]);
    }
    glEnd();
    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(900,500);
    glutCreateWindow("The Island");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
