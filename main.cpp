#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include <ctime>

int shift=0,flag=0;
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
                glutCreateWindow("Island View");
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
