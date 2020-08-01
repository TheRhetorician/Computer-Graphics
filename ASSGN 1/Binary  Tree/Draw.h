//Plots 8 symmetric points of a circle

void plotCirclePoints(int x,int y,int xcentre,int ycentre)
{
	glVertex2i (x+xcentre,y+ycentre);
	glVertex2i (x*(-1)+xcentre,y+ycentre);
	glVertex2i (x+xcentre,y*(-1)+ycentre);
	glVertex2i ((-1)*x+xcentre,y*(-1)+ycentre);
	glVertex2i (y+xcentre,x+ycentre);
	glVertex2i (y*(-1)+xcentre,x+ycentre);
	glVertex2i (y+xcentre,(-1)*x+ycentre);
	glVertex2i ((-1)*y+xcentre,(-1)*x+ycentre);
}

//Bresenham's midpoint algorithm for circle drawing

void DrawCircle(int x,int y,int rad)
{
	printf("%d %d\n",x,y);
	int x1=0,y1=rad;
	int d =1-rad;
	int deltaE= 3;
	int deltaSE = 2*(-1)*rad + 5;
	plotCirclePoints(x1,y1,x,y);
	
	while(y1>x1)
	{
		if(d<0)
		{
			d+=deltaE;
			deltaE+=2;
			deltaSE+=2;
		}
		else
		{
			d+=deltaSE;
			deltaSE+=4;
			deltaE+=2;
			y1--;
		}
		plotCirclePoints(x1,y1,x,y);
		x1++;
	}
}

//Swaps points to make above point as point 2 and below point as point 1

void swap(int* x0, int* y0,int* x1, int * y1,int* dx,int* dy)
{
	int temp = *x0;
	*x0=*x1;
	*x1=temp;
	(*dx)*=(-1);
	(*dy)*=(-1);
	temp = *y0;
	*y0=*y1;
	*y1=temp;
}

//Bresenham's midpoint drawing algorithm for line

void DrawLine(int x0,int y0,int x1,int y1)
{
	int dy = y1-y0;
	int dx=x1-x0;
	int flag=0;
	if(dx==0)
	{
		if(y1>y0)
			vertical_above(x0,y0,y1);
		else
			vertical_below(x0,y0,y1);
		flag=1;	
	}
	if(flag==0)
	{
		float m = dy/dx;
		if(abs(m)<=1)
		{
			if(x1<x0)
				swap(&x0,&y0,&x1,&y1,&dx,&dy);
			if(y1>y0)
				slopeLess_above(x0,y0,x1,dy,dx);
			else
				slopeLess_below(x0,y0,x1,dy,dx);
		}	
		else
		{
			if(x1<x0)
				swap(&x0,&y0,&x1,&y1,&dx,&dy);
			if(y1>y0)
				slopeMore_above(x0,y0,y1,dy,dx);
			else
				slopeMore_below(x0,y0,y1,dy,dx);		
		}
	}
}

//Draws Binary Tree

void Draw(node* root)
{
	int rad=radius;
	glColor3f(1, 0, 0);
	if(root->left!=NULL)
		DrawLine((root->c[0])*35,(root->c[1])*35,(root->left->c[0])*35,(root->left->c[1])*35);
	if(root->right!=NULL)
		DrawLine((root->c[0])*35,(root->c[1])*35,(root->right->c[0])*35,(root->right->c[1])*35);	
	glColor3f(0, 0, 1);	
	while(rad>0)
		DrawCircle((root->c[0])*35,(root->c[1])*35,rad--);
	if(root->left!=NULL)
	Draw(root->left);
	if(root->right!=NULL)
	Draw(root->right);
}

//Functions used by OpenGL

void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
    glColor3f(1, 0, 0); 	
	glPointSize(3);
    	glBegin(GL_POINTS);
    Draw(root);
		glEnd();

	glFlush();
}
