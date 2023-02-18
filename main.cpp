#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

//basic settings
void init(void){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

//used to display texts
void displayText(char *text,int length,int x,int y){
    int i;
    for(i=0;i<length;i++){
        glRasterPos2i(x+i,y);
        glColor3b(1,1,1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
}


void newDisplay(){
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    displayText(" Welcome to the Island",22,10,20);
    glEnd();
    glFlush();
}

// Mouse click event handler function
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            //printf("Inside the button\n");
            //printf("%d  %d\n",x,y);
        // Check if the mouse is inside the rectangle
        if (x >= 439 && x <= 519 && y >= 225 && y <= 279) {
            // Call function to create a new window
            //printf("New window Created");
            glutCreateWindow("Island View");
            glutDisplayFunc(newDisplay);
        }
    }
}

//draws next button
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



//main display and entry function
//add all components as functions here to display
void drawMyDesign(){
    char ajn[]="Aaron Jevil Nazareth   4nm20cs005";
    char afd[]="Aaron Francis Dsouza   4nm20cs004";
    char projectName[]=" The Island";
    int i,name_usn_length=33, projectName_length=11;
    glClear(GL_COLOR_BUFFER_BIT);
    displayText(projectName,projectName_length,19,45);
    displayText(ajn,name_usn_length,10,40);
    displayText(afd,name_usn_length,10,38);
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
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
