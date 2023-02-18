#include<windows.h>
#include<GL/glut.h>

void init(void){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void Button(){
    char next[]="next";
    int next_length=4,i;
    glColor3b(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(22,30);
    glVertex2f(22,34);
    glVertex2f(26,34);
    glVertex2f(26,30);
    glEnd();
    for(i=0;i<next_length;i++){
        glRasterPos2f(22.25+i,31.75);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,next[i]);
    }
    glFlush();
    glEnd();
}

void display(){
    char ajn[]="Aaron Jevil Nazareth   4nm20cs005";
    char afd[]="Aaron Francis Dsouza   4nm20cs004";
    char projectName[]="The Island";
    int i,name_usn_length=33, projectName_length=10;
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
    Button();
    glFlush();
}

void drawMyDesign(){
    glClear(GL_COLOR_BUFFER_BIT);
    display();
    Button();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("The Island");
    init();
    glutDisplayFunc(drawMyDesign);
    Button();
    glutMainLoop();
    return 0;
}
