#include "zsunsort.h"

void drawRoom()  // draws the polygons original and hidden/partially hideen and their shadows
{  
 	if(mode==1)  //for clipped scene shadows
 	{
		for(int i=0;i<24;i++)
		{
			float t = (-15-lY)/(f[i][1]-lY);
			shadow[i][1] = -15;
			shadow[i][0] = (int) (t*(f[i][0]-lX)+lX);
			shadow[i][2] = (int) (t*(f[i][2]-lZ)+lZ);
		} 
		glBegin(GL_QUADS);
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(shadow[i][0],shadow[i][1],shadow[i][2]);
		}
		glEnd();
		
		for(int i=0;i<24;i++)
		{
			float t = (-30-lZ)/(f[i][2]-lZ);
			shadow[i][2] = -30;
			shadow[i][0] = (int) (t*(f[i][0]-lX)+lX);
			shadow[i][1] = (int) (t*(f[i][1]-lY)+lY);
		}
		glBegin(GL_QUADS);
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(shadow[i][0],shadow[i][1],shadow[i][2]);
		}
		glEnd();
	}
	glBegin(GL_QUADS);
	if(mode==0)  // for drawing the original polygon 
	{
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,1.0f,0.0f);			
			glVertex3i(f[i][0],f[i][1],f[i][2]);
		}
	}
	glEnd();
	
	if(mode==0 && ((ch==3 ) || (ch==4)))  // hidden and partially hidden objects
	{ // for test cases 3 and 4
		if(ch==3)
		cover();
		glBegin(GL_QUADS);
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3i(small[i][0],small[i][1],small[i][2]);
		}
		glEnd();
	}

	glBegin(GL_QUADS);
	if(mode==1) // for printing the clipped original polygon
	{
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,1.0f);			
			glVertex3i(f[i][0],f[i][1],f[i][2]);
		}
		if(k<12)
		index = k;
		for(int i=0;i<index;i++)
		{
			glColor3f(1.0f,0.0f,0.0f);
			glVertex3f(cl[i][0]+0.05,cl[i][1]+0.05,cl[i][2]+0.05);
		}
	}
	if(mode==1 && ch==3)  // for printing the clipped hidden polygon in case 3
	{
		
		int z =  -15;
		while(z>=-20)
		{
			for(int i=0;i<24;i++)
			{
				if(small[i][2]== z) // generate shadows of hidden polygon
				{
					if(shadow[i][0]>small[i][0] && small[i][0]>0)
					shadow[i][0] = small[i][0];
					if(shadow[i][0]<small[i][0] && small[i][0]<0)
					shadow[i][0] = small[i][0];
					
					if(shadow[i][1]>small[i][1] && small[i][1]>0)
					shadow[i][1] = small[i][1];
					if(shadow[i][1]<small[i][1] && small[i][1]<0)
					shadow[i][1] = small[i][1];
				}
			}
			z-=5;
		}
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3i(small[i][0],small[i][1],small[i][2]);
		}

	}
	glEnd();
	
	if(mode == 1 && ch == 4)  // printing the clipped partially hidden polygon in case 4
	{
		int z = -15 ;
		while(z>=-15)
		{
			for(int i=0;i<24;i++) // generating shadows of partially hidden polygon in case 4
			{
				
					float t = (z-lZ)/(f[i][2]-lZ);
					shadow[i][2] = z;
					shadow[i][0] = (int) (t*(f[i][0]-lX)+lX);
					shadow[i][1] = (int) (t*(f[i][1]-lY)+lY);
				
			}	
			for(int i=0;i<24;i++)
			{
				if(small[i][2] == z)
				{
					if(shadow[i][0]>small[i][0] && small[i][0]>0)
					shadow[i][0] = small[i][0];
					if(shadow[i][0]<small[i][0] && small[i][0]<0)
					shadow[i][0] = small[i][0];
					
					if(shadow[i][1]>small[i][1] && small[i][1]>0)
					shadow[i][1] = small[i][1];
					if(shadow[i][1]<small[i][1] && small[i][1]<0)
					shadow[i][1] = small[i][1];
				}
			}
			z-=5;
		}
		glBegin(GL_QUADS); //printing the clipped partially hidden polygon
		for(int i=0;i<24;i++)
		{
			if(i<8)
			glColor3f(1.0f,0.0f,0.0f);
			else
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(small[i][0],small[i][1],small[i][2]);
		}
		glEnd();
		
		glBegin(GL_QUADS); // clipping the shadows falling on the partially hidden polygon
		for(int i=0;i<24;i++)
		{
			if(shadow[i][0]<small[i][0] && small[i][0]<0)
			shadow[i][0] = small[i][0];
			if(shadow[i][0]>small[i][0] && small[i][0]>0)
			shadow[i][0] = small[i][0];
			if(shadow[i][1]<small[i][1] && small[i][1]<0)
			shadow[i][1] = small[i][1];
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(shadow[i][0]+0.005,shadow[i][1]+0.005,shadow[i][2]+0.005);
		}
		glEnd();
		for(int i=0;i<24;i++)
		{
			float t = (-15-lY)/(small[i][1]-lY);
			shadow[i][1] = -15;
			shadow[i][0] = (int) (t*(small[i][0]-lX)+lX);
			shadow[i][2] = (int) (t*(small[i][2]-lZ)+lZ);
		} 
		glBegin(GL_QUADS);
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(shadow[i][0],shadow[i][1],shadow[i][2]);
		}
		glEnd();
		for(int i=0;i<24;i++)
		{
			float t = (-30-lZ)/(small[i][2]-lZ);
			shadow[i][2] = -30;
			shadow[i][0] = (int) (t*(small[i][0]-lX)+lX);
			shadow[i][1] = (int) (t*(small[i][1]-lY)+lY);
		}
		glBegin(GL_QUADS);
		for(int i=0;i<24;i++)
		{
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(shadow[i][0],shadow[i][1],shadow[i][2]);
		}
		glEnd();
	}
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
    

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {lX,lY-5.0,lZ-50, 1.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    
    GLfloat lightColor2[] = {0.5f, 0.2f, 0.2f, 0.5f};
    GLfloat lightPos2[] = {lX,lY-5.0,lZ-5.0, 1.0f};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
    glColor3f(1.0f,1.0f,0.0f);
	glTranslatef(lX,lY,lZ);
	glutSolidSphere(5.0f,50,50);
	glTranslatef(-lX,-lY,-lZ);
	
	if(mode==1)  // adding the planes to observe the shadows
	{
		glBegin(GL_QUADS);  //floor plane
		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(-50,-15.05,-30.05);
		glVertex3f(50,-15.05,-30.05);
		glVertex3f(50,-15.05,30.05);
		glVertex3f(-50,-15.05,30.05);
		glEnd();
		
		glBegin(GL_QUADS);  // back plane
		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(-50,-15.05,-30.05);
		glVertex3f(50,-15.05,-30.05);
		glVertex3f(50,35.05,-30.05);
		glVertex3f(-50,35.05,-30.05);
		glEnd();
	}
	
	drawRoom(); // calling the polygon printing method

	glutSwapBuffers();
}
