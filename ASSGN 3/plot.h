#include<GL/glut.h>
#include<windows.h>
//#include "calc.h"

char feat = 'i'; //default add
// feat stores the current mode of operation i.e 
// i for add
// j for delete
// k for move


void myMouse(int button, int state, int x, int y);

void drawpt(float x, float y) 
{   //plot points
    glBegin(GL_POINTS);
    	glColor3f(1.0,0.0,0.0);
    	glVertex2f(x,y);
    glEnd();
    glFlush(); 
}
void drawLines(float x1, float y1, float x2, float y2)
{	// draw lines between control points
	glBegin(GL_LINES);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{   // check which key is pressed and proceed accordingly
	switch(key)
	{
		case 27 :
			exit(0);
			break;
		case 'i' :             // add point
			feat = 'i';
			glutMouseFunc(myMouse);
			break;
		case 'j' :             // delete point
			feat = 'j';
			glutMouseFunc(myMouse);
			break;
		case 'k' :             // move point
			feat = 'k';
			glutMouseFunc(myMouse);
			break;
			
	}
}

void myMouse(int button, int state, int x, int y)
{	// function to deal with mouse clicks, releases and drags
	glClear(GL_COLOR_BUFFER_BIT);
	// ADD POINTS
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && feat=='i') 
	{	// adds current point to control points
		arr[pts][0]=x;
		arr[pts][1]= screen-y;
		pts++;
		
		drawpt((float) x,(float) screen-y);
		glColor3f(1.0,1.0,1.0);
		if(pts>1)
		{	// prints the control points and curve points
			float xc[pts];
			float yc[pts];
			xc[0]=arr[0][0];
			yc[0]=arr[0][1];
			for(int i=1;i<pts;i++)
			{
				drawLines(arr[i-1][0],arr[i-1][1],arr[i][0],arr[i][1]);
				xc[i]=arr[i][0];
				yc[i]=arr[i][1];
			}
			for(float t=0;t<1;t+=0.001)
			{	// draw curve points for varying t values
				float a = deCast(t,xc,pts);
				float b = deCast(t,yc,pts);
				drawpt(a,b);
			}
			
			glColor3f(1.0,0.0,0.0);
			//pts=0;
		}
	}
	// MOVE POINTS
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && feat=='k')
	{	// move the selected control point
		int g = closest(x,screen-y);
		arr[g][0]=x;
		arr[g][1]=screen-y;  // update the shifted points coordinates
		drawpt((float) x,(float) screen-y);
		glColor3f(1.0,1.0,1.0);
		if(pts>1)
		{
			float xc[pts];
			float yc[pts];
			xc[0]=arr[0][0];
			yc[0]=arr[0][1];
			for(int i=1;i<pts;i++)
			{
				drawLines(arr[i-1][0],arr[i-1][1],arr[i][0],arr[i][1]);
				xc[i]=arr[i][0];
				yc[i]=arr[i][1];
			}
			for(float t=0;t<1;t+=0.001)
			{	// draws curve points for varying t values
				float a = deCast(t,xc,pts);
				float b = deCast(t,yc,pts);
				drawpt(a,b);
			}
			
			glColor3f(1.0,0.0,0.0);
			//pts=0;
		}
	}
	// DELETE POINTS
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && feat=='j')
	{	// delete the selected control point
		int g = closest(x,screen-y);
		//float tmp = 0;
		for(int j=g;j<pts-1;j++)
		{	//shift the values in after deletion
			arr[j][0]=arr[j+1][0];
			arr[j][1]=arr[j+1][1];
		}
		pts--;
		drawpt((float) x,(float) screen-y);
		glColor3f(1.0,1.0,1.0);
		if(pts>1)
		{
			float xc[pts];
			float yc[pts];
			xc[0]=arr[0][0];
			yc[0]=arr[0][1];
			for(int i=1;i<pts;i++)
			{
				drawLines(arr[i-1][0],arr[i-1][1],arr[i][0],arr[i][1]);
				xc[i]=arr[i][0];
				yc[i]=arr[i][1];
			}
			for(float t=0;t<1;t+=0.001)
			{	//draw curve points for varying t values
				float a = deCast(t,xc,pts);
				float b = deCast(t,yc,pts);
				drawpt(a,b);
			}
			
			glColor3f(1.0,0.0,0.0);
			//pts=0;
		}
	}
	//glutKeyboardFunc(handleKeypress);
	glFlush();
}
