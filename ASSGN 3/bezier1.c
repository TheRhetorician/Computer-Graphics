#include "calc.h"
#include "plot.h"

/* COMPUTER GRAPHICS ASSIGNMENT 3
	
	MUDIT CHATURVEDI 2018A7PS0248H
	TANAY GUPTA      2018AAPS0343H
	HARDIK PARNAMI   2018A7PS0062H
	
*/

// calc.h contains the deCasteljau algo based curve point calculation 
// and linear interpolation functions


// plot.h contains the mouse Action Listener and Keyboard Action Listeners
// along with the interactive addition and modifications


void myInit() 
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);

}
void myDisplay() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");

    glutMouseFunc(myMouse);
    glutKeyboardFunc(handleKeypress);
    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();

    return 0;
}
