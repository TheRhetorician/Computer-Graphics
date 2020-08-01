//When slope is greater than one and point 2 is above point 1 
void slopeMore_above(int x0,int y0,int y1,int dy,int dx)
{
	int d= dy-2*dx;
	int incN = -2*dx;
	int incNE = 2*(dy-dx);
	int y =y0;
	int x=x0;
	glVertex2i (x,y);
	
	while(y<y1)
	{
		if(d<=0)
		{
			d+=incNE;
			x++;
		}
		else
		{
			d+=incN;
		}
		y++;
		glVertex2i (x,y);
	}
}

//When slope is greater than one and point 2 is below point 1 

	
void slopeMore_below(int x0,int y0,int y1,int dy,int dx)
{
	int d = 2*dx - dy;
	int incSE = 2*dx + 2*dy;
	int decS = 2*(dx);
	int x = x0;
	int y = y0;
	glVertex2i (x,y);
	while(y>y1)
	{
		if (d>0)
		{
			x++;
			d+=incSE;
		}
		else
		{
			d+=decS;
		}
		y--;
		glVertex2i (x,y);
	}
}	
	
//When slope is less than or equal to one and point 2 is below point 1 

void slopeLess_below(int x0,int y0,int x1,int dy,int dx)	
{
	int d = 2*dy + dx;
	int incE = 2*dy;
	int decSE = 2*(dy+dx);
	int x=x0;
	int y=y0;
	glVertex2i (x,y);
	while(x<=x1)
	{
		if(d>0)
			d+=incE;
		else
		{
			d+=decSE;
			y--;
		}	
		x++;
		glVertex2i (x,y);
	}
}

//When slope is less than or equal to one and point 2 is above point 1 
	
void slopeLess_above(int x0,int y0,int x1,int dy,int dx)
{
	int d = 2*dy - dx;
	int incNE = 2*(dy-dx);
	int incE = 2*dy;
	int y=y0;
	int x=x0;
	glVertex2i (x,y);
	while(x<=x1)
	{
		if(d<=0)
			d+=incE;
		else
		{
			d+=incNE;
			y++;
		}	
		x++;
		glVertex2i (x,y);
	}
}	

//For vertical lines when point 1 is above point 2
	
void vertical_above(int x0,int y0,int y1)
{
	int y=y0;
	int x=x0;
	while(y<y1)
	{
		glVertex2i (x,y);
		y++;
	}
}	

//For vertical lines when point 1 is below point 2

void vertical_below(int x0,int y0,int y1)
{
	int y=y0;
	int x=x0;
	while(y>y1)
	{
		glVertex2i (x,y);
		y--;
	}
}

