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

float sun=-40.0;                    // Global Variable for sun.
float moon=190.0;                   // Global Variable for moon.
float cloud=200.0;                  // Global Variable for cloud.
float smallCloud=300.0;             // Global Variable for small cloud.
float lastCloud=400.0;              // Global Variable for last cloud.
float wave=-20.0;                   // Global Variable for wave.
float boat=-30.0;                   // Global Variable for boat.
float ship=200.0;                   // Global Variable for ship.
float car=150.0;                    // Global Variable for car.
float secondHuman=-12.0;            // Global Variable for human.
float football=0;                   // Global Variable for Football.
float h1=75.0;                      // Global Variable for sun.

int shift=0,flag=0;

/*basic settings*/

void init(void){
    glClearColor(0.82,0.63,0.41,1);
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
void displayText(char *text,float length,float x,float y){
    int i;
    float len=0,dx=0,x1;
    x1=(float)x;
    for(i=0;i<length;i++){
            if(len>=70){
                y=y-2;
                x1=x1-42;
                len=0;
            }
            glRasterPos2f(x1+dx,y);
            dx+=0.6;
            if(text[i]=='2'){
                dx-=0.2;
                glRasterPos2f(x1+dx,y);
                dx+=0.4;
            }
            if(text[i]=='i' || text[i]=='I' || text[i]=='r'){
                dx-=0.4;
                glRasterPos2f(x1+dx,y);
                dx+=0.4;
            }
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
            len++;
    }
}

// create circle for left sail
void sailL(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=90;i<=180;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}
// create circle for right sail
void sailR(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=90;i>=0;i--)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

//for lines
void drawLine(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

// create circle for sun
void sunFunc(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=360;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

// create circle for wave
void waveFunc(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
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

void humanFunc(float humanx,float humany)
{
        //MAN LEFT
//man head
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5,1.5,humanx-80.0,humany-20.5);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25,humany-19.25);
    glVertex2f(humanx-81.25,humany-18);
    glVertex2f(humanx-78.75,humany-18);
    glVertex2f(humanx-78.75,humany-19.25);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75,humany-20);
    glVertex2f(humanx-79.25,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();
//man t-shirt
    glColor3f(0.0f, 0.0f, 1.0f); //red
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-28.0,0);
    glVertex3f(humanx-82.0,humany-28.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-82.0,humany-22.0,0.0);
    glVertex3f(humanx-82.0,humany-24.0,0);
    glVertex3f(humanx-83.0,humany-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-24.0,0);
    glVertex3f(humanx-77.0,humany-24.0,0.0);
    glEnd();

//man pent
    glBegin(GL_QUADS);
       glColor3f(1.0, 0.0, 0);
    glVertex3f(humanx-82.0,humany-28.0,0);
    glVertex3f(humanx-78.0,humany-28.0,0.0);
    glVertex3f(humanx-78.0,humany-35.0,0);
    glVertex3f(humanx-82.0,humany-35.0,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5,humany-35.0,0);
    glVertex3f(humanx-78.5,humany-35.0,0.0);
    glVertex3f(humanx-78.5,humany-38.0,0);
    glVertex3f(humanx-81.5,humany-38.0,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0,humany-32.0,0);
    glVertex3f(humanx-80.0,humany-38.0,0.0);
    glEnd();
}

//circles
void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=360;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}


//lighthouse
void lightHouse(int x,int y)
{
    // Draw the lighthouse body
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_POLYGON);
    glVertex2f(-5+x, -5+y);
    glVertex2f(-5+x, 5+y);
    glVertex2f(5+x, 5+y);
    glVertex2f(5+x, -5+y);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_POLYGON);
    glVertex2f(-5+x, 5+y);
    glVertex2f(-5+x, 15+y);
    glVertex2f(5+x, 15+y);
    glVertex2f(5+x, 5+y);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_POLYGON);
    glVertex2f(-5+x, 15+y);
    glVertex2f(-5+x, 25+y);
    glVertex2f(5+x, 25+y);
    glVertex2f(5+x, 15+y);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_POLYGON);
    glVertex2f(-5+x, 25+y);
    glVertex2f(-5+x, 35+y);
    glVertex2f(5+x, 35+y);
    glVertex2f(5+x, 25+y);
    glEnd();


    // Draw the lighthouse top
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-3+x, 35+y);
    glVertex2f(-3+x, 40+y);
    glVertex2f(3+x, 40+y);
    glVertex2f(3+x, 35+y);
    glEnd();

    //door
    glBegin(GL_POLYGON);
    glVertex2f(-1.75+(float)x,-5+y);
    glVertex2f(-1.75+(float)x,0+y);
    glVertex2f(1.75+(float)x,0+y);
    glVertex2f(1.75+(float)x,-5+y);
    glEnd();

    glBegin(GL_POLYGON);
    float angle;
    int i;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(-1.25+(float)x,0+y);
    for(i=0;i<=180;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*2),y+(sin(angle)*2));
    }
    glEnd();

    // circles
    circle(1,1,x,y+10);
    circle(1,1,x,y+20);
    circle(1,1,x,y+30);

    // Draw the lighthouse roof
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_TRIANGLES);
    glVertex2f(-3+x, 40+y);
    glVertex2f(3+x, 40+y);
    glVertex2f(0.0+x, 43+y);
    glEnd();

    glFlush();
}

//shops
void shop(int x,int y){
    char text1[]="C   O   C   O";

    //shopkeeper
    humanFunc(150,20);
    // Draw the shop body
    glColor3f(0.96f, 0.87f, 0.70f); // brown
    glBegin(GL_POLYGON);
    glVertex2d(x,y);
    glVertex2d(x,y+10);
    glVertex2d(x+20,y+10);
    glVertex2d(x+20,y);
    glEnd();

    glColor3f(0, 0, 0); // black
    displayText(text1,14,x+5,y+2.5);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(x+0.3,y+10);
    glVertex2f(x+0.3,y+16);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(x+19.6,y+10);
    glVertex2d(x+19.6,y+16);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(x-4,y+12);
    glVertex2d(x+10,y+28);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(x+10,y+28);
    glVertex2d(x+24,y+12);
    glEnd();

    glColor3f(0, 0, 0); // black
    circle(1.5,1.5,x+2,y);
    circle(1.5,1.5,x+18,y);

    //lighthouse
    lightHouse(50,0);

    glFlush();
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

    //sun
    glColor3f(1, 0.36, 0);
    sunFunc(12,20,sun-30.0,70.0);

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
    waveFunc(50,15,wave-100.0,-50.0);



//wave middle
        glColor3f(0.51, 0.83, 1);
    waveFunc(50,15,wave-3,-52.0);


//wave Right
    glColor3f(0.51, 0.83, 1);
    waveFunc(35,15,wave+90.0,-50.0);


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
    glVertex3f(boat-40.0,-70.0,0);
    glVertex3f(boat-20.0,-70.0,0.0);
     glVertex3f(boat-24.0,-75.0,0.0);
    glVertex3f(boat-39.0,-75.0,0);
    glEnd();

    //sail bamboo
   glBegin(GL_QUADS);
       glColor3f(0.49, 0.32, 0.21);
    glVertex3f(boat-71.0,-44.0,0);
    glVertex3f(boat-71.5,-44.0,0.0);
     glVertex3f(boat-71.5,-70.0,0.0);
    glVertex3f(boat-71.0,-70.0,0);
    glEnd();

    //sail
    glColor3f(0.9, 0.9, 0.9);
    sailL(2,22,boat-31.5,-69.0);
    sailR(3,25,boat-31.0,-69.0);

    shop(60,-20);

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
void keyboard(unsigned char key,int x, int y){
    if(key == 'e' || key == 'E'){
        exit(0);
    }
}

void mousenew(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            //printf("Inside the button\n");
            //printf("%d  %d\n",x,y);
        // Check if the mouse is inside the rectangle
        if (x >= 563 && x <= 691 && y >= 460 && y <= 517) {
            // Call function to create a new window
            //printf("New window Created");
            if(flag==1)
            {
                glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
                glutInitWindowPosition(0,0);
                glutInitWindowSize(2200,1200);
                glutFullScreen();
                glutCreateWindow("Island View");
                initDesign();
                glutFullScreen();
                glutDisplayFunc(newDisplay);
                glutKeyboardFunc(keyboard);
            }
        }
    }
}

//draws next button
void Button(char next[],int next_length){
    glBegin(GL_POLYGON);
    glVertex2f(22,14);
    glVertex2f(22,18);
    glVertex2f(27,18);
    glVertex2f(27,14);
    glEnd();
    glColor3b(0,0,0);
    displayText(next,next_length,23.3,15.7);
    glFlush();
    glEnd();
}

void newDisplaySmall(){
    glutFullScreen();
    init();
    glClearColor(0.82,0.63,0.41,1);
    glutMouseFunc(mousenew);
    char title[]="DESCRIPTION";
    int num=11;
    displayText(title,num,20,47);
    drawLine(20,46,27,46);
    char descrip[]="The island is surrounded by clear blue water that sparkles in the sunlight. On the beach, a small village with a grasslands is visible, scattered around a central square. Further up the beach, a lighthouse stands tall and proud, with its beam of light sweeping across the sea. You can see the figure of a lighthouse keeper inside, tending to the light and watching for ships in the distance. The lighthouse is an important landmark on the island, guiding sailors safely to shore. As you leave the island, you realize that it's a special place, a hidden gem in the vast expanse of the sea.";
    int despLen=590;
    displayText(descrip,despLen,3,43);
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
            //printf("%d  %d\n",x,y);
        // Check if the mouse is inside the rectangle
        if (x >= 563 && x <= 691 && y >= 460 && y <= 517) {
            // Call function to create a new window
            //printf("New window Created");
            if(flag==0){
                glutInitWindowPosition(10,0);
                glutInitWindowSize(2020,1080);
                glutCreateWindow("Island Description");
                glutDisplayFunc(newDisplaySmall);
                glutKeyboardFunc(keyboard);
                flag=1;
            }
        }
    }
}

//main display and entry function
//add all components as functions here to display
void drawMyDesign(){
    char ajn[]="AARON JEVIL NAZARETH            4NM20CS005";
    char afd[]="AARON FRANCIS DSOUZA            4NM20CS004";
    char sirs[]="Guided by:";
    char sir1[]="Dr. PRADEEP KANCHAN";
    char sir1des[]="Assistant Professor Gd-III";
    char sir2[]="Mr. PUNEETH R P";
    char sir2des[]="Assistant Professor Gd-II";
    char projectName[]=" VINLAND ISLAND";
    int i,name_usn_length=42, projectName_length=15,sirs_length=10,sir1_length=19,sir2_length=15,sir1des_length=26,sir2des_length=25;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(2, 200, 159);
    displayText(projectName,projectName_length,20,42);
    drawLine(20,41,29,41);
    glColor3b(127,127,127);
    displayText(ajn,name_usn_length,8,35);
    displayText(afd,name_usn_length,8,30);
    displayText(sirs,sirs_length,20,25);
    displayText(sir1,sir1_length,8,23);
    displayText(sir1des,sir1des_length,8,21);
    displayText(sir2,sir2_length,26,23);
    displayText(sir2des,sir2des_length,26,21);
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
