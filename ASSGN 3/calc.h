#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float arr[100][100];  // store control points
int pts = 0;
int screen=480;

int closest(float x,float y)
{	// calculates the point closest to mouse click
	float min = 100000000;
	int pos = 200;
	for(int i=0;i<pts;i++)
	{
		float dist = ((x-arr[i][0])*(x-arr[i][0])) + ((y-arr[i][1])*(y-arr[i][1]));
		dist = sqrt(dist);
		if(dist<min)
		{
			min = dist;
			pos = i;			
		}
	}
	min = 100000000;
	return pos;
}

float Lerp(float x,float y, float t)
{	// calculate point q0 for each p0 and p1
	// use linear interpolation
	return (1-t)*x + t*y;
}

float deCast(float t, float temp[], int size)
{	//implement deCasteljau's algorithm to calculate curve points recursively
	if(size == 1)
	return temp[0];
	float st[40];
	int k=0;
	for(int i=1;i<size;i++)
	{
		st[k++] = Lerp(temp[i-1],temp[i],t); //store intermediate curve points
	}
	return deCast(t,st,k);
	
}
