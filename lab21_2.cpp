#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1 ,Rect *R2)
{
	double x2 = R1->x + R1->w;
	double y2 = R1->y - R1->h;
	double x3 = R2->x + R2->w;
	double y3 = R2->y - R2->h;
	
	if (R1->x <= R2->x && R1->y >= R2->y && x2 >= x3 && y2 <= y3 ) //R2 อยู่ใน R1
	{
		return R2->h*R2->w;
	}

	if (R1->x >= R2->x && R1->y <= R2->y && x2 <= x3 && y2 >= y3 ) //R1 อยู่ใน R2
	{
		return R1->h*R1->w;
	}
	if (R1->x <= R2->x && R1->y <= R2->y && x2 <= x3 && y3 >= y2 && R2->x <= x2 && y3 <= R1->y)	
	{
		return ((R1->w-(R2->x - R1->x))*(R2->h-(R2->y-R1->y)));
	}
	if (R1->x >= R2->x && R1->y >= R2->y && x2 >= x3 && y3 <= y2 && x3 >= R1->x && R2->y >= y2)	
	{
		return ((R2->w-(R1->x - R2->x))*(R1->h-(R1->y-R2->y)));
	}
	if (R2->x <= R1->x && R2->y >= R1->y && x3 <= x2 && y3 >= y2 && x3 >= R1->x && y3 <= R1->y)
	{
		return ((x3-R1->x)*(R1->y-y3));
	}
	if (R2->x >= R1->x && R2->y <= R1->y && R2->x <= x2  && R2->y >= y2 && x3 >= x2 && y3 <= y2 )
	{
		return ((x2-R2->x)*(R2->y-y2));
	}
	if (R2->x <= R1->x && R2->y >= R1->y && x3 >= x2 && y3 >= y2  && y3 <= R1->y)
	{
		return (R1->w*(R1->y-y3));
	}
	if (R2->x <= R1->x && R2->y <= R1->y && x3 >= x2 && y3 <= y2  && y3 <= R1->y)
	{
		return (R1->w*(R2->y-y2));
	}
	if (R2->y >= R1->y && y3 <= y2 && R1->x >= R2->x && x3 >= R1->x && x3 <= x2 )
	{
		return (R1->h*(x3-R1->x));
	}
	if (R2->y >= R1->y && y3 <= y2 && R1->x <= R2->x && x3 >= R1->x && x3 >= x2 )
	{
		return (R1->h*(x2-R2->x));
	}

	if (R1->x <= R2->x && R1->y >= R2->y && x2 <= x3 && y2 <= y3)
	{
		return (R2->h*(x2-R2->x));
	}

	if (R1->x >= R2->x && R1->y >= R2->y && x2 >= x3 && y2 <= y3)
	{
		return (R2->h*(x3-R1->x));
	}
	
	if (R1->x <= R2->x && R1->y >= R2->y && x2 >= x3 && y2 >= y3)
	{
		return (R2->w*(R2->y-y2));
	}

	if (R1->x <= R2->x && R1->y <= R2->y && x2 >= x3 && y3 >= y2)
	{
		return (R2->w*(R1->y-y3));
	}
	
	else
	{
	    return 0;
	}
	
	return 0;
}