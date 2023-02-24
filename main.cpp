#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include <ctime>

int shift=0;
//basic settings
void init(void){
    glClearColor(0,0,0.6,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void delay(int milliseconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < milliseconds) {}
}

void disableInput() {
    glutPassiveMotionFunc(NULL);
    glutKeyboardFunc(NULL);
}

//used to display texts
void displayText(char *text,int length,int x,int y){
    int i;
    for(i=0;i<length;i++){
        glRasterPos2f(x+i,y);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
}

void drawing_moving_boats() {
	// we want to draw moving boat
        //water
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.3, 0.3, 1);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0, 12);
        glVertex2f(75, 12);
        glVertex2f(75, 0);

        glEnd();

        //boat trapezium
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(22 + shift, 20);
        glVertex2f(2 + shift, 20);
        glVertex2f(7 + shift, 10);
        glVertex2f(17 + shift, 10);

        glEnd();

        //black stick
        glColor3f(0.160, 0.658, 0.203);
        glBegin(GL_POLYGON);
        glVertex2f(12 + shift, 30);
        glVertex2f(12 + shift, 25);
        glVertex2f(9 + shift, 25.019);

        glEnd();

        // fourth regular shape is octagon
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(12 + shift, 25.0);
        glVertex2f(12 + shift, 20);
        glVertex2f(11 + shift, 20);
        glVertex2f(11 + shift, 25);


        glEnd();

	glutSwapBuffers();
}

void newDisplay(){
    init();
    glutInitWindowPosition(20,20);
    glutInitWindowSize(1920,1080);
    glutFullScreen();
    disableInput();
    glClear(GL_COLOR_BUFFER_BIT);
    while(shift!=24){
        drawing_moving_boats();
        shift=shift+1;
        delay(200);
    }
    glEnd();
    glFlush();
}


// Mouse click event handler function
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            //printf("Inside the button\n");
            printf("%d  %d\n",x,y);
        // Check if the mouse is inside the rectangle
        if (x >= 563 && x <= 691 && y >= 460 && y <= 517) {
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
    glVertex2f(22,14);
    glVertex2f(22,18);
    glVertex2f(27,18);
    glVertex2f(27,14);
    glEnd();
    glColor3b(0,0,0);
    displayText(next,next_length,22.5,15.75);
    glFlush();
    glEnd();
}



//main display and entry function
//add all components as functions here to display
void drawMyDesign(){
    char ajn[]="Aaron Jevil Nazareth   4nm20cs005";
    char afd[]="Aaron Francis Dsouza   4nm20cs004";
    char sirs[]="Guided by:";
    char sir1[]="Dr. PRADEEP KANCHAN";
    char sir2[]="Mr. PUNEETH R P";
    char projectName[]=" The Island";
    int i,name_usn_length=33, projectName_length=11,sirs_length=10,sir1_length=19,sir2_length=15;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(254, 126, 159);
    displayText(projectName,projectName_length,19,32);
    glColor3b(127,127,127);
    displayText(ajn,name_usn_length,10,27);
    displayText(afd,name_usn_length,10,25);
    displayText(sirs,sirs_length,10,23);
    displayText(sir1,sir1_length,10,21);
    displayText(sir2,sir2_length,10,19);
    Button();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(20,20);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("The Island");
    init();
    glutFullScreen();
    glutDisplayFunc(drawMyDesign);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
