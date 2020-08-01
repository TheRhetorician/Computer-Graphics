/*
COMPUTER GRAPHICS ASSIGNMENT 2
SCENE- CLASSROOM

Made By:
	Mudit Chaturvedi  2018A7PS0248H
	Hardik Parnami    2018A7PS0062H
	Tanay Gupta		  2018AAPS0343H
*/
#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "display.h"






//Initializes 3D rendering
void initRendering() 
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    //glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h)
 {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}



int main(int argc, char** argv) 
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);

    //Create the window
    glutCreateWindow("Classroom");
    initRendering();

    //Set handler functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(specialInput);
    glutReshapeFunc(handleResize);

    glutMainLoop();
}

