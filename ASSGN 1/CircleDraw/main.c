#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h> 
int radius,xcentre,ycentre;	
#include "PlotCircle.h"
#include "Display.h"
	
/*
Computer Graphics Assignment 1  Question 2
Code for plotting a circle using midpoint circle drawing algorithm
By-

Tanay Gupta
Hardik Parnami
Mudit Chaturvedi

*/

int main(int argc,char** argv)
{
	printf("Enter the coordinates of the centre\n");
	scanf("%d%d",&xcentre,&ycentre);
	printf("Please enter radius\nIt should be an integer between 0 and 150\n");
	scanf("%d",&radius);								// accepts coordinates of centre of the circle 
	glutInit(&argc,argv);								// and value of radius from the user and initialization
    	glutInitDisplayMode(GLUT_SINGLE);
   	glutInitWindowSize(640,480); 						// sets default window size to 640 x 480
    	glutCreateWindow("Circle Drawing");
    	glClearColor(0,0,0,0);							// repaints the window to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
 	glutDisplayFunc(display);							// calls the display() method to plot the circle
   	glutMainLoop();
}
