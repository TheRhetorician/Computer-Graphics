#include <windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

//translation variables
float tX = 0.0f;
float tY = 0.0f;
float tZ = -100.0f;

//Rotation variables
float aX = 0.0f;
float aY = 0.0f;
float aZ = 0.0f;

//Light source
float lX = 0.0f;
float lY = 40.0f;
float lZ = 60.0f;

int index = 12;
int mode = 0; // 0 means normal view, 1 means clipped view
int ch = -1;  // stores value between 1,2,3 or 4 denoting the test case.

// original polygon points
int f[][3] = {{-10,-10,10},{-10,10,10},{10,10,10},{10,-10,10},
			{-10,10,10},{-10,10,-10},{10,10,-10},{10,10,10},
			{10,10,10},{10,-10,10},{10,-10,-10},{10,10,-10},
			{-10,-10,-10},{10,-10,-10},{10,-10,10},{-10,-10,10},			
			{-10,-10,-10},{10,-10,-10},{10,10,-10},{-10,10,-10},	
			{-10,10,10},{-10,-10,10},{-10,-10,-10},{-10,10,-10}};

// hidden/partially hidden polygon points			
int small[][3] = {{-5,-5,-15},{-5,15,-15},{5,15,-15},{5,-5,-15},
			{-5,15,-15},{-5,15,-20},{5,15,-20},{5,15,-15},
			{5,15,-15},{5,-5,-15},{5,-5,-20},{5,15,-20},
			{-5,-5,-20},{5,-5,-20},{5,-5,-15},{-5,-5,-15},			
			{-5,-5,-20},{5,-5,-20},{5,15,-20},{-5,15,-20},	
			{-5,15,-15},{-5,-5,-15},{-5,-5,-20},{-5,15,-20}};
			

int cl[24][3]; // stores the clipped original polygon
int k=0;

float shadow[48][3]; //stores the shadows of the objects obstructing light


int pt[24][3]; // duplicates the original polygon points

int tx[24][2];// stores the 2D coordinates temporarily
int qw=0; // stores length of temporary array

int cx[4][2]; //stores the clipping window coordinates

void cover()
{ // used to change coordinates of case 4 to case 3
	for(int i=0;i<24;i++)
	{
		if(small[i][1]==15)
		small[i][1]=5;
	}
}
void cuboid()
{ // used to change the corrdinates of case 1 to case 2
	for(int i=0;i<24;i++)
	{
		if(f[i][0]==-10)
		f[i][0]=-25;
		if(f[i][0]==10)
		f[i][0]=-15;
	}
	
	for(int i=8;i<=11;i++)
	{
		cl[k][0]=f[i][0];
		cl[k][1]=f[i][1];
		cl[k++][2]=f[i][2];
	}
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) 
{
    switch (key) {
        case 27: //Escape key
        exit(0);
        
		case 'r':                   //Reset Scene to initial state
        aX = 0.0f;
        aY = 0.0f;
        aZ = 0.0f;

        tX = 0.0f;
        tY = 0.0f;
        tZ = -100.0f;
		break;
        //Translation with char keys (arrow keys in separate function below)
        
        case 'i':                   //Scene moves up (Y-axis)
        tY += 1.0f;
        break;

        case 'k':                   //Scene moves down (Y-axis)
        tY -= 1.0f;
        break;        

        //Rotation (follows right hand thumb rule)
        case 'w':                   //Scene rotates about +ve X-axis
        aX += 1.5f;
        break;

        case 's':                   //Scene rotates about -ve X-axis
        aX -= 1.5f;
        break;

        case 'a':                   //Scene rotates about +ve Y-axis
        aY += 1.5f;
        break;

        case 'd':                   //Scene rotates about -ve Y-axis
        aY -= 1.5f;
        break;

        case 'j':                   //Scene rotates about +ve Z-axis 
        aZ += 1.5f;
        break;

        case 'l':                   //Scene rotates about -ve Z-axis
        aZ -= 1.5f;
        break;
        
        //normal mode               // Scene is in normal view
        case 'n':
        mode = 0;
        break;
        // change to post clip mode  // Scene is now in clipped mode
        case 'm':
        mode = 1;
        break;
        
        case 'q' :
        mode = 0;
        aX = 0.0f;
        aY = 0.0f;
        aZ = 0.0f;

        tX = -lX;
        tY = -lY;
        tZ = -lZ;
        break;
        	

        

    }

    glutPostRedisplay();            //redraw scene
}

void specialInput(int key, int x, int y) 
{
    switch(key)
    {
        case GLUT_KEY_UP:           //Scene zooms in (Z-axis)
        tZ += 1.0f;
        break;  
        case GLUT_KEY_DOWN:         //Scene zooms out (Z-axis)
        tZ -= 1.0f;
        break;
        case GLUT_KEY_LEFT:         //Scene goes left (X-Axis)
        tX -= 1.0f;
        break;
        case GLUT_KEY_RIGHT:        //Scene goes right (X-Axis)
        tX += 1.0f;
        break;
    }

    glutPostRedisplay();

}

