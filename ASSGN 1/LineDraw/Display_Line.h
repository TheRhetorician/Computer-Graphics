void swap(int* x0, int* y0,int* x1, int * y1,int* dx,int* dy)
{
	// swaps the starting and end points using a temporary variable
	int temp = *x0;
	*x0=*x1;
	*x1=temp;
	(*dx)*=(-1);
	(*dy)*=(-1);
	temp = *y0;
	*y0=*y1;
	*y1=temp;
}

void display(void)
{   
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glColor3f(1, 0, 0); 	
	glPointSize(3);							 				//sets default pixel/point size to 3
    	glBegin(GL_POINTS);
    	
		int dy = y1-y0;
		int dx=x1-x0;
		int flag=0;
		if(dx==0)							  				// checks if the line will be vertical
		{
			if(y1>y0)						  				// if second point is vertically above the first
				vertical_above(x0,y0,y1);
			else							  				// if second point is vertically below the first
				vertical_below(x0,y0,y1);
			flag=1;							  				// sets flag
		}
		if(flag==0)							  				// if the line is not vertical
		{
			float m = dy/dx;			
			if(abs(m)<=1)					  				// divide the algo into two parts part 
			{												//one is when slope lies in the range [-1,+1].
				if(x1<x0)									// checks if line needs to be drawn in reverse				
					swap(&x0,&y0,&x1,&y1,&dx,&dy);			// swaps the point for complexity ease
				if(y1>y0)									// the second point is higher than the first on the y axis
					slopeLess_above(x0,y0,x1,dy,dx);
				else										// the second point is lower than the first on the y axis
					slopeLess_below(x0,y0,x1,dy,dx);
			}	
			else											// part two when slope doesn't lie in [-1,+1]
			{
				if(x1<x0)									// checks if line needs to be drawn in reverse
					swap(&x0,&y0,&x1,&y1,&dx,&dy);
				if(y1>y0)									// the second point is higher than the first on the y axis
					slopeMore_above(x0,y0,y1,dy,dx);
				else										// the second point is lower than the first on the y axis
					slopeMore_below(x0,y0,y1,dy,dx);		
			}
		}
	glEnd();
	glFlush();	
}
