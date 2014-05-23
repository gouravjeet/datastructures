
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

int main(){
	Point2D lower_left(2,4);
	Point2D upper_right(3,5);
	Point2D lower_left2(2,6);
	Point2D upper_right2(5,7);
	Point2D p1(3,9);
	Point2D p2(9,8);
	
	Rectangle r1(lower_left,upper_right);
	//Rectangle r2(lower_left2,upper_right2); 
	bool x=r1.is_point_within(p1);
	if(x)
	{
		std::cout<<x<<std::endl;
	}
	else{
		std::cout<<x;
	}
	//is_point_within(p2);
}