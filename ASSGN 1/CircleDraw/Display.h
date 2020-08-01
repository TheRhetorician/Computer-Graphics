void display(void)
{
    //makes use of midpoint circle drwaing algorithm
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    	glColor3f(0,1, 0); 	
	glPointSize(3);									//sets default point/pixel size to 3
    	glBegin(GL_POINTS);
	int x=0,y=radius;
	int d =1-radius;
	int deltaE= 3;									// stores the net change in the value of d when East pixel is selected
	int deltaSE = 2*(-1)*radius + 5;				// stores the net change in the value of d when South East pixel is selected
	plotCirclePoints(x,y);							//calls function to plot the pixels
	while(y>x)
	{
		if(d<0)										// selects East pixel
		{
			d+=deltaE;
			deltaE+=2;
			deltaSE+=2;
		}
		else										// selects South East pixel
		{
			d+=deltaSE;
			deltaSE+=4;
			deltaE+=2;
			y--;
		}
		plotCirclePoints(x,y);						//calls function to plot the pixels
		x++;
	}
	glEnd();

	glFlush();	
}
