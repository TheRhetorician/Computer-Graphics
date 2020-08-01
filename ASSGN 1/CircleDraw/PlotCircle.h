void plotCirclePoints(int x,int y)
{
	// makes use of circle's 8 way symmetry to plot points
	glVertex2i (x+xcentre,y+ycentre);
	glVertex2i (x*(-1)+xcentre,y+ycentre);
	glVertex2i (x+xcentre,y*(-1)+ycentre);
	glVertex2i ((-1)*x+xcentre,y*(-1)+ycentre);
	glVertex2i (y+xcentre,x+ycentre);
	glVertex2i (y*(-1)+xcentre,x+ycentre);
	glVertex2i (y+xcentre,(-1)*x+ycentre);
	glVertex2i ((-1)*y+xcentre,(-1)*x+ycentre);
}
