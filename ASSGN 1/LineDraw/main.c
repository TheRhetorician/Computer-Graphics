#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
int x1,y0,x0,y1;
#include "All_Slopes.h"
#include "Display_Line.h"

/*
Assignment 1 Q1 Computer Graphics

Code for implementing midpoint line drawing algorithm to plot a line having any slope
using OpenGL and FreeGlut
By-

Mudit Chaturvedi
Tanay Gupta
Hardik Parnami

*/

int main(int argc,char** argv)
{
	printf("Please input the Starting and Ending points for the line\nEnter only integer points for proper visualization!\n");
	printf("Enter initial coordinates!\n");
	scanf("%d%d",&x0,&y0);										 //gets initial coordinates from the user
	printf("Enter final coordinates!\n");
	scanf("%d%d",&x1,&y1); 										 // gets the final coordinates from the user
	glutInit(&argc,argv);										 //initialization
    	glutInitDisplayMode(GLUT_SINGLE);						 
   	glutInitWindowSize(640, 480);								 // sets default window size to 640 x 480
    	glutCreateWindow("Line Drawing");
    	glClearColor(0,0,0,0);									// repaints the window as black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
 	glutDisplayFunc(display);									// calls display() method to plot the pixels
//	glutIdleFunc(idle);
   	glutMainLoop();
}
