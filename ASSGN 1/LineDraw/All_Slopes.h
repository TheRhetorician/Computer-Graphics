void slopeMore_above(int x0,int y0,int y1,int dy,int dx)
{
	// if the slope of the line doesn't lie in [-1,+1] and
    // the second point lies above the first along y axis
	int d= dy-2*dx;
	int incN = -2*dx;
	int incNE = 2*(dy-dx);
	int y =y0;
	int x=x0;
	glVertex2i (x,y);                   // plot the pixel
	
	while(y<y1)
	{
		if(d<=0)                       // in case North East pixel is selected
		{
			d+=incNE;
			x++;
		}
		else 						   // in case North pixel is selected
		{
			d+=incN;
		}
		y++;
		glVertex2i (x,y);			   //plot the pixel
	}
}
	
void slopeMore_below(int x0,int y0,int y1,int dy,int dx)
{
	// if the slope of the line doesn't lie in [-1,+1] and
    // the second point lies above the first along y axis
	int d = 2*dx - dy;
	int incSE = 2*dx + 2*dy;
	int decS = 2*(dx);
	int x = x0;
	int y = y0;
	glVertex2i (x,y);                  // plot the pixel
	while(y>y1)
	{
		if (d>0)					   // in case South East pixel is selected
		{
			x++;
			d+=incSE;
		}
		else						   // in case South pixel is selected
		{
			d+=decS;
		}
		y--;
		glVertex2i (x,y);			   // plot the pixel
	}
}	
	
void slopeLess_below(int x0,int y0,int x1,int dy,int dx)	
{
	// if the slope of the line lies in [-1,+1] and
    // the second point lies below the first along y axis
	int d = 2*dy + dx;
	int incE = 2*dy;
	int decSE = 2*(dy+dx);
	int x=x0;
	int y=y0;
	glVertex2i (x,y);  				   // plot the pixel
	while(x<=x1)
	{
		if(d>0)						  // in case East pixel is selected
			d+=incE;
		else						  // in case North East pixel is selected
		{
			d+=decSE;
			y--;
		}	
		x++;
		glVertex2i (x,y);			   // plot the pixel
	}
}
	
void slopeLess_above(int x0,int y0,int x1,int dy,int dx)
{
	// if the slope of the line lies in [1,+1] and
    // the second point lies above the first along y axis
	int d = 2*dy - dx;
	int incNE = 2*(dy-dx);
	int incE = 2*dy;
	int y=y0;
	int x=x0;
	glVertex2i (x,y);    			   // plot the pixel
	while(x<=x1)
	{
		if(d<=0)					   // in case East pixel is selected
			d+=incE;
		else						   //in case North East pixel is selected
		{
			d+=incNE;
			y++;
		}	
		x++;
		glVertex2i (x,y);			   // plot the pixel
	}
}	
	
void vertical_above(int x0,int y0,int y1)
{
	// if second point is vertically above the first then..
	// plot the pixels from bottom to top i.e. first pt. to second pt.
	int y=y0;
	int x=x0;
	while(y<y1)
	{
		glVertex2i (x,y);
		y++;
	}
}	

void vertical_below(int x0,int y0,int y1)
{
	// if second point is vertically below the first then..
	// plot the pixels from top to bottom i.e. first pt. to second pt.
	int y=y0;
	int x=x0;
	while(y>y1)
	{
		glVertex2i (x,y);
		y--;
	}
}
