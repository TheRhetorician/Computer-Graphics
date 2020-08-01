#include "keys.h"

//note all points need to be sent in clockwise order for clipping

const int MAX_POINTS = 20; 
int final_points[24][2]={0}; //store the points to be returned to suth();
int count=0;
int zcord = 60;
// Returns x-value of point of intersectipn of two 
// lines 
int x_intersect(int x1, int y1, int x2, int y2, 
				int x3, int y3, int x4, int y4) 
{ 
	int num = (x1*y2 - y1*x2) * (x3-x4) - 
			(x1-x2) * (x3*y4 - y3*x4); 
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
	return num/den; 
} 

// Returns y-value of point of intersectipn of 
// two lines 
int y_intersect(int x1, int y1, int x2, int y2, 
				int x3, int y3, int x4, int y4) 
{ 
	int num = (x1*y2 - y1*x2) * (y3-y4) - 
			(y1-y2) * (x3*y4 - y3*x4); 
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
	return num/den; 
} 

// This functions clips all the edges w.r.t one clip 
// edge of clipping area 
void clip(int poly_points[][2], int* poly_size, 
		int x1, int y1, int x2, int y2) 
{ 
	int new_points[MAX_POINTS][2], new_poly_size = 0; 

	// (ix,iy),(kx,ky) are the co-ordinate values of 
	// the points 
	for (int i = 0; i < *poly_size; i++) 
	{ 
		// i and k form a line in polygon 
		int k = (i+1) % *poly_size; 
		int ix = poly_points[i][0], iy = poly_points[i][1]; 
		int kx = poly_points[k][0], ky = poly_points[k][1]; 

		// Calculating position of first point 
		// w.r.t. clipper line 
		int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1); 

		// Calculating position of second point 
		// w.r.t. clipper line 
		int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1); 

		// Case 1 : When both points are inside 
		if (i_pos < 0 && k_pos < 0) 
		{ 
			//Only second point is added 
			new_points[new_poly_size][0] = kx; 
			new_points[new_poly_size][1] = ky; 
			new_poly_size++; 
		} 

		// Case 2: When only first point is outside 
		else if (i_pos >= 0 && k_pos < 0) 
		{ 
			// Point of intersection with edge 
			// and the second point is added 
			new_points[new_poly_size][0] = x_intersect(x1, 
							y1, x2, y2, ix, iy, kx, ky); 
			new_points[new_poly_size][1] = y_intersect(x1, 
							y1, x2, y2, ix, iy, kx, ky); 
			new_poly_size++; 

			new_points[new_poly_size][0] = kx; 
			new_points[new_poly_size][1] = ky; 
			new_poly_size++; 
		} 

		// Case 3: When only second point is outside 
		else if (i_pos < 0 && k_pos >= 0) 
		{ 
			//Only point of intersection with edge is added 
			new_points[new_poly_size][0] = x_intersect(x1, 
							y1, x2, y2, ix, iy, kx, ky); 
			new_points[new_poly_size][1] = y_intersect(x1, 
							y1, x2, y2, ix, iy, kx, ky); 
			new_poly_size++; 
		} 

		// Case 4: When both points are outside 
		else
		{ 
			//No points are added 
		} 
	} 

	// Copying new points into original array 
	// and changing the no. of vertices 
	*poly_size = new_poly_size; 
	for (int i = 0; i < *poly_size; i++) 
	{ 
		poly_points[i][0] = new_points[i][0]; 
		poly_points[i][1] = new_points[i][1]; 
	} 
} 

// Implements Sutherland–Hodgman algorithm 
void suthHodgClip(int poly_points[][2], int poly_size, 
				int clipper_points[][2], int clipper_size,int orig_poly[][2]) 
{ 
	int size=clipper_size;
	int original_poly[poly_size][2];
	for(int i=0;i<poly_size;i++)
	{
		original_poly[i][1]=orig_poly[i][1];
		original_poly[i][0]=orig_poly[i][0];
	}
	//i and k are two consecutive indexes 
	for (int i=0; i<clipper_size; i++) 
	{ 
		int k = (i+1) % clipper_size; 

		// We pass the current array of vertices, it's size 
		// and the end points of the selected clipper line 
		clip(poly_points, &poly_size, clipper_points[i][0], 
			clipper_points[i][1], clipper_points[k][0], 
			clipper_points[k][1]); 
	} 	
	
		
	for(int i=0;i<size;i++)
	{
		float x1,y1,x2,y2;
		x1= original_poly[i][0],y1=original_poly[i][1];
		if(i!=size-1)
		{
			x2= original_poly[i+1][0],y2=original_poly[i+1][1];		
		}	
		else
		{
			x2=original_poly[0][0],y2=original_poly[0][1];
		}
		final_points[count][0]=x1;
		final_points[count++][1]=y1;
		float m=0;
		int slope=-1;
		if(x1!=x2)
			m = (y2-y1)/(x2-x1);
		else
			slope = 0;
		for(int j=0;j<poly_size;j++)
		{
			if((slope==0 && x1==poly_points[j][0]) || (poly_points[j][1]-y1)==m*(poly_points[j][0]-x1))
			{
				final_points[count][0]=poly_points[j][0];
				final_points[count++][1]=poly_points[j][1];
				int p=(j!=0?(j-1):(poly_size-1));
				int flag=0;
				while(1)
				{
					final_points[count][0]=poly_points[p][0];
					final_points[count++][1]=poly_points[p][1];
					for(int k=0;k<size;k++)
					{
						float newx1,newy1,newx2,newy2;
						newx1= original_poly[k][0],newy1=original_poly[k][1];
						if(k!=size-1)
						{
							newx2= original_poly[k+1][0],newy2=original_poly[k+1][1];		
						}	
						else
						{
							newx2=original_poly[0][0],newy2=original_poly[0][1];
						}
						float newm=0;
						int newslope=-1;
						if(newx1!=newx2)
							newm = (newy2-newy1)/(newx2-newx1);
						else
							newslope=0; 
						if((newslope==0 && newx1==poly_points[p][0]) || ((poly_points[p][1]-newy1)==newm*(poly_points[p][0]-newx1)))
						{
							i=k;
							final_points[count][0]=newx2;
							final_points[count++][1]=newy2;
							flag=1;
						}
					}
					
					p!=0 ? p-- : (p = poly_size-1);
					if(flag==1)
						break;
				}
				break;
			}
		}
	}	
	//storing the 2D points as 3D in clipped polygon array cl
	
	for(int i=0;i<=7;i++) //storing the 2D points as 3D in clipped polygon array cl
	{
		cl[k][0]=f[i][0];
		cl[k][1]=f[i][1];
		cl[k++][2]=f[i][2];
	}
	
	//since final_points will be initialized multiple times 
	//we need to store the result somewhere else
	
	//now store the clipped result into the cl array
	
	for(int i=0;i<count;i++)
	{
		cl[k][0]=final_points[i][0];
		cl[k][1]=final_points[i][1];
		cl[k++][2]=zcord;	
	}	

	count = 0;
} 


//Driver code 
void sutherlandclip(int clipper_points[4][2],int poly_points[][2],int s,int z) 
{ 
	// Defining polygon vertices in clockwise order 
	int clipper_size = 4; 
	
	// Defining clipper polygon vertices in clockwise order 
	// square clipper 
	int poly_size = s; 
	zcord = z;
	
	//Calling the clipping function 
	suthHodgClip(poly_points, poly_size, clipper_points, 
				clipper_size,poly_points); 

} 
