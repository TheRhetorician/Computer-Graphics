#include "keys.h"


void drawRoom()  // draws the classroom
{    
	glBegin(GL_QUADS);
	// Floor /
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(-100,-5,-100);
	glVertex3f(100,-5,-100);
	glVertex3f(100,-5,60);
	glVertex3f(-100,-5,60);
	//Ceiling /
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(-100,100,-100);
	glVertex3f(100,100,-100);
	glVertex3f(100,100,60);
	glVertex3f(-100,100,60);
	// Walls 
	glColor3f(0.0f,0.0f,1.0f); //wall with the blackboard
	glVertex3f(-100,-5,60);
	glVertex3f(100,-5,60);
	glVertex3f(100,100,60);
	glVertex3f(-100,100,60);
	
	glColor3f(0.0f,0.0f,0.0f);  //blackboard
	glVertex3f(-20,0,59.9);
	glVertex3f(20,0,59.9);
	glVertex3f(20,20,59.9);
	glVertex3f(-20,20,59.9);
	
	
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-100,-5,-100);
	glVertex3f(100,-5,-100);
	glVertex3f(100,100,-100);
	glVertex3f(-100,100,-100);
	
	glColor3f(1.0f,1.0f,0.0f);
	glVertex3f(100,100,60);
	glVertex3f(100,-5,60);
	glVertex3f(100,-5,-100);
	glVertex3f(100,100,-100);
	
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(-100,100,60);
	glVertex3f(-100,-5,60);
	glVertex3f(-100,-5,-100);
	glVertex3f(-100,100,-100);
	glEnd();

}


void drawCube(float dimn[], float cntr[], float clr[])  //draws the tables and chairs
{

    //Color set here
    glColor3f(clr[0], clr[1], clr[2]);
    glBegin(GL_QUADS);

    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);

    //Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1],tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);

    //Back
    glNormal3f((dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], -(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);

    //Left
    glNormal3f((dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], (dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);

    //Top
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], (dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);

    //Bottom
    glNormal3f((dimn[0]/2)+cntr[0], -1.0f, 0.0f);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz+(dimn[2]/2)+cntr[2]);
    glVertex3f(dist+(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);
    glVertex3f(dist-(dimn[0]/2)+cntr[0], -(dimn[1]/2)+cntr[1], tempz+distz-(dimn[2]/2)+cntr[2]);

    glEnd();

}

//Draws the 3D scene
void drawScene() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Translate the entire system 
    glTranslatef(tX, tY, tZ);
    glRotatef(aX, 1.0f, 0.0f, 0.0f);
    glRotatef(aY, 0.0f, 1.0f, 0.0f);
    glRotatef(aZ, 0.0f, 0.0f, 1.0f);

    //Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	drawRoom();
	
	float dimn[3], cntr[3], clr[3];
	for(dist=20;dist>=-20;dist-=20)
	{
		for(distz=0;distz>=-60;distz-=20)
		{
		    //Chair begin
		
		    //Back brown
		    tempz=0;
		    dimn[0] = 4.0f; dimn[1] = 10.0f; dimn[2] = 0.3f;
		    cntr[0] = 0.0f; cntr[1] = 0.0f; cntr[2] = -7.0f;
		    clr[0] = 0.65f; clr[1] = 0.50f; clr[2] = 0.39f;
		    drawCube(dimn, cntr, clr);
		
		    //Front brown
		    dimn[0] = 4.0f; dimn[1] = 5.0f; dimn[2] = 0.3f;
		    cntr[0] = 0.0f; cntr[1] = -2.5f; cntr[2] = -3.0f;
		    clr[0] = 0.65f; clr[1] = 0.50f; clr[2] = 0.39f;
		    drawCube(dimn, cntr, clr);
		
		    //Seat brown
		    dimn[0] = 4.0f; dimn[1] = 0.3f; dimn[2] = 4.3f;
		    cntr[0] = 0.0f; cntr[1] = 0.0f; cntr[2] = -5.0f;
		    clr[0] = 0.65f; clr[1] = 0.50f; clr[2] = 0.39f;
		    drawCube(dimn, cntr, clr);  
		
		    //Chair  end
		
		    //Table begin
		    dimn[0] = 12.0f; dimn[1] = 0.3f; dimn[2] = 8.6f;   //Top  yellow
		    cntr[0] = 0.0f; cntr[1] = 2.0f; cntr[2] = 0.0f;
		    clr[0] = 1.0f; clr[1] = 1.0f; clr[2] = 0.0f;
		    drawCube(dimn, cntr, clr);  
		
		    dimn[0] = 0.3f; dimn[1] = 7.0f; dimn[2] = 8.6f;
		    cntr[0] = 6.0f; cntr[1] = -1.5f; cntr[2] = 0.0f;
		    clr[0] = 1.0f; clr[2] = clr[1] = 0.0f;    //red
		    drawCube(dimn, cntr, clr); 
		
		    dimn[0] = 0.3f; dimn[1] = 7.0f; dimn[2] = 8.6f;
		    cntr[0] = -6.0f; cntr[1] = -1.5f; cntr[2] = 0.0f;
		    clr[0] = 1.0f; clr[2] = clr[1] = 0.0f;    //red
		    drawCube(dimn, cntr, clr);
		}
	}
	dist=0;
	distz=0;
	tempz=40;
	for(temp=20;temp>=-20;temp-=10)  //Teacher's Table
	{
		dimn[0] = temp+12.0f; dimn[1] = 0.3f; dimn[2] =8.6f;  //Top brown 
	    cntr[0] = 0.0f; cntr[1] = 2.0f; cntr[2] = 0.0f;
	    clr[0] = 0.91f; clr[1] = 0.76f; clr[2] = 0.65f;
	    drawCube(dimn, cntr, clr);  
		
	    dimn[0] = temp+0.3f; dimn[1] = 7.0f; dimn[2] = 8.6f; //black
	    cntr[0] = 6.0f; cntr[1] = -1.5f; cntr[2] = 0.0f;
	    clr[0] = 0.0f; clr[1] = 0.0f; clr[2] = 0.0f;
	    drawCube(dimn, cntr, clr); 
	
	    dimn[0] = temp+0.3f; dimn[1] = 7.0f; dimn[2] = 8.6f; //black
	    cntr[0] = -6.0f; cntr[1] = -1.5f; cntr[2] = 0.0f;
	    clr[0] = 0.0f; clr[1] = 0.0f; clr[2] = 0.0f;
	    drawCube(dimn, cntr, clr);
	}
	glutSwapBuffers();
}
