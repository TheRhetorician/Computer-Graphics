#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h>

#include<conio.h>
#include<math.h>
#include<time.h>
int radius=20;
#include "struct.h"
node *root;
#include "Shift.h"
#include "Height_tree.h"
#include "Print.h"
#include "All_Slopes.h"
#include "Draw.h"


void main(int argc,char** argv)
{
	clock_t t;
//Notes the start time
    t = clock();
    
//Creates Binary Tree
	root = create();
	int x = maxDepth(root);
	h = x;
	counter = x;
// Find height of the  Binary Tree	
	giveheight(root,h);
	int j,k;

//Find the coordinates of each node	
	giveCoord(root,h,0,1);

//Makes the Binary Tree narrow
	
	int r =findRight(root);
	printf("%d\nbye\n",r);
	int l= findLeft(root);
	printf("%d\nhello\n",l);
	int shiftln=0;
	if(r!=-1 && l!=-1)
		shiftln = (r-l-2)/2;
	shiftNode(shiftln,root);

//Shifts the Binary Tree to left as much as possible 

	findmin(root);
	shift(root);

//Prints final coordinates of each node

	print(root);
		glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_SINGLE);
   	glutInitWindowSize(1920, 1080);
    	glutCreateWindow("Binary Tree");
    	glClearColor(0,0,0,0);	
	glClear(GL_COLOR_BUFFER_BIT);
 	glutDisplayFunc(display);
   	glutMainLoop();
//Notes the end time  
	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("took %f seconds to execute \n", time_taken);
}

