#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

//basic settings
void init(void){
    glClearColor(0,0,0.6,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

//used to display texts
void displayText(char *text,int length,int x,int y){
    int i;
    for(i=0;i<length;i++){
        glRasterPos2f(x+i,y);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
}


void newDisplay(){
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(254, 126, 159);
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
    char next[]=" Next";
    int next_length=5,i;
    glColor3b(127,127,127);
    glBegin(GL_POLYGON);
    glVertex2f(21,30);
    glVertex2f(21,34);
    glVertex2f(26,34);
    glVertex2f(26,30);
    glEnd();
    glColor3b(0,0,0);
    displayText(next,next_length,21.5,32.75);
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
    glColor3b(254, 126, 159);
    displayText(projectName,projectName_length,19,45);
    glColor3b(127,127,127);
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
