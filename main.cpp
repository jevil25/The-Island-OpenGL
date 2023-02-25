#include<windows.h>
#include<GL/freeglut.h>
#include<stdio.h>
#include <ctime>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

float s=-40.0; // Global Variable for sun.
float m=190.0; // Global Variable for moon.
float c=200.0; // Global Variable for cloud.
float cs=300.0; // Global Variable for small cloud.
float cl=400.0; // Global Variable for last cloud.
float w=-20.0; // Global Variable for wave.
float b=-30.0; // Global Variable for boat.
float sh=200.0; // Global Variable for ship.
float car=150.0; // Global Variable for car.
float h=40.0; // Global Variable for human.
float h2=-12.0; // Global Variable for human.
float ball=0; // Global Variable for Football.
float h1=75.0; // Global Variable for sun.

int shift=0,flag=0;
//basic settings
void init(void){
    glClearColor(0,0,0.6,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}

void initDesign(void)
{
    glClearColor(0.58, 0.97,1, 0.0);
    glOrtho(-100,100,-100,100,-100,100);

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
    int i,len=0;
    for(i=0;i<length;i++){
            if(len==44){
                y=y-2;
                x=x-44;
                len=0;
            }
            glRasterPos2f(x+i,y);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
            len++;
    }
}

// create circle for wave
void wave(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=180;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void sky(){
    //Sky
    glBegin(GL_QUADS);
       glColor3f(0.58, 0.97,1);
    glVertex3f(-100,100, 0);
        glColor3f(0.01, 0.35, 1);
    glVertex3f(100.0,100.0,0);
        glColor3f(0.33, 0.55, 1);
    glVertex3f(100.0,0.-6,0.0);
        glColor3f(0.54, 0.68, 0.95);
    glVertex3f(-100.0,-2,0);
    glEnd();

    //Grass
    glBegin(GL_QUADS);
       glColor3f(0.17, 0.49, 0);
    glVertex3f(-100.0,-15.0,0);
    glVertex3f(100.0,-15.0,0.0);
     glVertex3f(100.0,-5.0,0.0);
    glVertex3f(-100.0,0.0,0);
    glEnd();

        glBegin(GL_QUADS);
       glColor3f(0.17, 0.49, 0);
    glVertex3f(-100.0,-5.0,0);
    glVertex3f(100.0,-5.0,0.0);
     glVertex3f(100.0,-7.0,0.0);
    glVertex3f(-100.0,-10.0,0);
    glEnd();

    //sea beach
    glBegin(GL_QUADS);
       glColor3f(0.89, 0.89, 0.89);
    glVertex3f(-100.0,-10.0,0);
    glVertex3f(100.0,-5.0,0.0);
     glColor3f(1, 1, 1);
    glVertex3f(100.0,-40.0,0);
    glVertex3f(-100.0,-40.0,0.0);
    glEnd();


//sea water BOTTOM
    glBegin(GL_QUADS);
     glColor3f(0, 0.64, 0.97);
    glVertex3f(-100.0,-80.0,0);
    glVertex3f(100.0,-80.0,0.0);
     glColor3f(0, 0.53, 0.8);
    glVertex3f(100.0,-100.0,0.0);
    glVertex3f(-100.0,-100.0,0.0);
    glEnd();


//sea water MIDDLE
    glBegin(GL_QUADS);
           glColor3f(0.16, 0.72, 1);
    glVertex3f(-100.0,-60.0,0);
    glVertex3f(100.0,-60.0,0.0);
         glColor3f(0, 0.64, 0.97);
    glVertex3f(100.0,-80.0,0);
    glVertex3f(-100.0,-80.0,0.0);
    glEnd();

    //wave Left
    glColor3f(0.51, 0.83, 1);
    wave(50,15,w-100.0,-50.0);



//wave middle
        glColor3f(0.51, 0.83, 1);
    wave(50,15,w-3,-52.0);


//wave Right
    glColor3f(0.51, 0.83, 1);
    wave(35,15,w+90.0,-50.0);


//sea water UP
    glBegin(GL_QUADS);
       glColor3f(0.51, 0.83, 1);
    glVertex3f(-100.0,-40.0,0);
    glVertex3f(100.0,-40.0,0.0);
     glColor3f(0.16, 0.72, 1);
    glVertex3f(100.0,-60.0,0);
    glVertex3f(-100.0,-60.0,0.0);
    glEnd();
//Island
    glColor3f(0.89, 0.89, 0.89);



//Boat
   glBegin(GL_QUADS);
       glColor3f(1,1, 1);
    glVertex3f(b-80.0,-70.0,0);
    glVertex3f(b-60.0,-70.0,0.0);
     glVertex3f(b-64.0,-75.0,0.0);
    glVertex3f(b-79.0,-75.0,0);
    glEnd();

    glutPostRedisplay();
    glFlush();
}



void newDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    glEnd();
    glFlush();
    glEnd();
    glFlush();
}

// Mouse click event handler function
void mousenew(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            //printf("Inside the button\n");
            printf("%d  %d\n",x,y);
        // Check if the mouse is inside the rectangle
        if (x >= 563 && x <= 691 && y >= 460 && y <= 517) {
            // Call function to create a new window
            printf("New window Created");
            if(flag==1)
            {
                printf("2");
                glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
                glutInitWindowPosition(10,10);
                glutInitWindowSize(1920,1080);
                glutFullScreen();
                glutCreateWindow("Island View");
                initDesign();
                glutFullScreen();
                glutDisplayFunc(newDisplay);
            }
        }
    }
}

//draws next button
void Button(char next[],int next_length){
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

void newDisplaySmall(){
    init();
    glutInitWindowPosition(20,20);
    glutInitWindowSize(960,540);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMouseFunc(mousenew);
    char descrip[]="The island is surrounded by clear blue water that sparkles in the sunlight. On the beach, a small village with a few huts is visible, scattered around a central square. In the middle of the square is a small hut made of straw and wood. Further up the beach, a lighthouse stands tall and proud, with its beam of light sweeping across the sea. You can see the figure of a lighthouse keeper inside, tending to the light and watching for ships in the distance. The lighthouse is an important landmark on the island, guiding sailors safely to shore. As you leave the island, you realize that it's a special place, a hidden gem in the vast expanse of the sea. You feel lucky to have had the chance to visit, and you vow to return someday, to soak up more of its beauty and charm.";
    int despLen=372;
    displayText(descrip,despLen,2,40);
    glEnd();
    glFlush();
    Button("Next",5);
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
            printf("New window Created");
            if(flag==0){
                printf("1");
                glutCreateWindow("Island Description");
                glutDisplayFunc(newDisplaySmall);
                flag=1;
            }
        }
    }
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
    Button("Next",5);
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,0);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("The Island");
    init();
    glutFullScreen();
    glutDisplayFunc(drawMyDesign);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
