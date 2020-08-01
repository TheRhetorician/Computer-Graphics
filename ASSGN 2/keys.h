#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
//Translation variables
float tX = 0.0f;
float tY = 0.0f;
float tZ = -30.0f;

//Rotation variables
float aX = 0.0f;
float aY = 0.0f;
float aZ = 0.0f;

int dist=20;
int distz=0;
int temp=20;
int tempz=0;

//Called when a key is pressed  **user inateraction**
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
        tZ = -30.0f;
		break;
        //Translation with char keys
        
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

        

    }

    glutPostRedisplay();            //redraw scene
}

void specialInput(int key, int x, int y)   //actionListener for arrow keys **user inateraction**
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
