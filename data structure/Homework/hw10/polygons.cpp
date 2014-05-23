#include "polygons.h"
#include <iostream>
#include <cstdlib>
#include "utilities.h"

Polygon::Polygon(const std::string &namestr, const std::vector<Point> &pts) {
	vertices=pts;
	name=namestr;
}
bool Polygon::HasAllEqualSides(){
	int num=vertices.size();
	double n1=DistanceBetween(vertices[0],vertices[1]);

	for(int i=1;i< num;i++){
		double n2=DistanceBetween(vertices[i],vertices[(i+1)%num]);
		if(EqualSides(n1,n2)){

		}
		else{
			return false;
		}
	}
	return true;
}


bool Polygon::HasAllEqualAngles(){
	int num=vertices.size();
	double p1=Angle(vertices[0],vertices[1],vertices[2]);

	for(int i=1;i<num;i++){
		double p2=Angle(vertices[i],vertices[(i+1)%num],vertices[(i+2)%num]);
		// we are comparing first vertices with each of the other vertices.
		if(EqualAngles(p1,p2)){

		}
		else{
			return false;
		}
	}	
	return true;
}


bool Polygon::HasARightAngle(){
	
	int num=vertices.size();
	

	for(int i=0;i<num;i++){
		double r=Angle(vertices[i],vertices[(i+1)%num],vertices[(i+2)%num]);
		// we are comparing first vertices with each of the other vertices.
		if(RightAngle(r)){
			return true;
		}
		
	}	
	return false;
}


bool Polygon::HasAnObtuseAngle(){
	int num=vertices.size();
	

	for(int i=0;i<num;i++){
		double r=Angle(vertices[i],vertices[(i+1)%num],vertices[(i+2)%num]);
		// we are comparing first vertices with each of the other vertices.
		if(ObtuseAngle(r)){

		return true;
		}
		
	}	
	return false;
}
bool HasAConcaveAngle(std::vector<Point> &vertices){
	int num=vertices.size();
	

		for(int i=0;i<num;i++){
		double r=Angle(vertices[i],vertices[(i+1)%num],vertices[(i+2)%num]);
		// we are comparing first vertices with each of the other vertices.
		if(ReflexAngle(r)){

			return true;
		}
		
	}	
	return false;
}


bool Polygon::HasAnAcuteAngle(){
	int num=vertices.size();
	

	for(int i=0;i<num;i++){
		double r=Angle(vertices[i],vertices[(i+1)%num],vertices[(i+2)%num]);
		// we are comparing first vertices with each of the other vertices.
		if(AcuteAngle(r)){

			return true;
		}
		
	}	
	return false;
}
//Check whether it is convex

bool Polygon::IsConvex() {
	
	return !HasAConcaveAngle(vertices);
}

Triangle::Triangle(const std::string &name, const std::vector<Point> &pts):Polygon(name,pts) { 
	//Triangle Constructor
	// A triangle has 3 sides, so i will check if it has 3 vertices
	if(pts.size() != 3){
		throw -1;
	}
}

bool Triangle::HasAllEqualAngles() { 
    return false; 
   } 
bool Triangle::HasAllEqualSides() { 
    return false; 
   }
 bool Triangle::HasARightAngle() { 
    return false; 
   }
 bool Triangle::HasAnObtuseAngle() { 
    return false;
    }
    
 bool Triangle::HasAnAcuteAngle() { 
    return true; 
   }

  bool Triangle::IsConvex() { 
      return true; 
    }
RightTriangle::RightTriangle(const std::string &name, const std::vector<Point> &pts) : Triangle(name,pts) { 
	
	double p1=Angle(pts[0],pts[1],pts[2]);
	double p2=Angle(pts[1],pts[2],pts[0]);
	double p3=Angle(pts[2],pts[0],pts[1]);

	if(RightAngle(p1) || RightAngle(p2) || RightAngle(p3) ){
		//std::cout<<p1<<"space"<<p2<<"space"<<p3<<"space"<<"dara";
		//Test will pass if it has one angle as 90
	}
	else{
		throw -1;
	}

}

bool RightTriangle::HasARightAngle() {
	return true;
}
IsoscelesTriangle::IsoscelesTriangle(const std::string &name, const std::vector<Point> &pts):Triangle(name,pts) { 
  double is1 = DistanceBetween(pts[0],pts[1]);
  double is2 = DistanceBetween(pts[1],pts[2]);
  double is3 = DistanceBetween(pts[2],pts[0]);
// Isosceles Triangle must have two sides as equal
  if(EqualSides(is1,is2) || EqualSides(is2,is3) || EqualSides(is1,is3)){
  	
  }	
  else{
  	throw -1;
  }
}
// Isosceles triangle must have equal sides with right angle-it will follow the property of both isosceles and right triangle.
IsoscelesRightTriangle::IsoscelesRightTriangle(const std::string &name, const std::vector<Point> &pts):Triangle(name,pts), IsoscelesTriangle(name,pts), RightTriangle(name,pts) {

 }

EquilateralTriangle::EquilateralTriangle(const std::string &name, const std::vector<Point> &pts):Triangle(name,pts), IsoscelesTriangle(name,pts) {

  double eq1 = DistanceBetween(pts[0],pts[1]);
  double eq2 = DistanceBetween(pts[1],pts[2]);
  double eq3 = DistanceBetween(pts[2],pts[0]);
  if(EqualSides(eq1,eq2) && EqualSides(eq1,eq3)){
  	// All three sides equal
  }	
  else{
  	throw -1;
  }
  //Equilateral traingle has all sides equal. So, if there is one unequal side, then it is not a equilateral traingle.
  }

bool EquilateralTriangle::HasAllEqualSides() { 
    return true; 
  } 
   bool EquilateralTriangle::HasAllEqualAngles() { 
    return true;
     } 
   bool EquilateralTriangle::HasARightAngle() { 
    return false; 
  } 


ObtuseTriangle::ObtuseTriangle(const std::string &name, const std::vector<Point> &pts):Triangle(name,pts) {

  	double o1=Angle(pts[0],pts[1],pts[2]);
	double o2=Angle(pts[1],pts[0],pts[2]);
	double o3=Angle(pts[1],pts[2],pts[0]);
	if(ObtuseAngle(o1) || ObtuseAngle(o2) || ObtuseAngle(o3)){
		//Test will pass if it has one angle greater than 90
	}
	else{
		throw -1;
	}

  } 
  bool ObtuseTriangle::HasAnObtuseAngle() { 
  	return true; 
  } 
IsoscelesObtuseTriangle::IsoscelesObtuseTriangle(const std::string &name, const std::vector<Point> &pts):Triangle(name,pts), IsoscelesTriangle(name,pts), ObtuseTriangle(name,pts) {
  	
  	//We donot need to implement anything in the IsoscelesObtise Triangle because it is inherited from IsosclesTraingles and 
  	// Obtuse Traingle

  }


Quadrilateral::Quadrilateral(const std::string &name, const std::vector<Point> &pts):Polygon(name,pts) {
  	if(pts.size()!=4){
  		throw -1;
  	}
   }
  bool Quadrilateral::HasAllEqualAngles() { 
  	return false; 
  } 
  bool Quadrilateral::HasAllEqualSides() { 
  	return false;
   }
Trapezoid::Trapezoid(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts) {
  	// this helper function will tell that trapezoid is there or not
  	//by checking that opposite sides are parallel to each other
  		
		bool t2=Parallel(Vector(pts[1],pts[2]),Vector(pts[3],pts[0]));
  		bool t1=Parallel(Vector(pts[0],pts[1]),Vector(pts[2],pts[3]));
  		
  		
  		if(t1 || t2){
  			
  		}
  		else{
  			throw -1;
  		}

  } 
 //kites have 2 equal pairs of length and eacj edge shares a vertex 
Kite::Kite(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts) {
  	double k1 = DistanceBetween(pts[0],pts[1]);
  	double k2 = DistanceBetween(pts[1],pts[2]);
  	double k3 = DistanceBetween(pts[2],pts[3]);
  	double k4 = DistanceBetween(pts[3],pts[0]);
// std::cout<<"======================================================Kite"
  if (EqualSides(k1,k2) || EqualSides(k3,k4) || EqualSides(k2,k3) || EqualSides(k4,k1) ) 
  {
   
    
  } 
  else{
  	throw -1;
  } 
  //kite has one convex angle
	  if (HasAConcaveAngle(vertices)) 
	  	{ 
	  		throw -1;
	  	 }
 }

 // parallellogram has opposites parallel so we need to check that opposites are paraalel or not
 bool Kite::IsConvex() { return true; 
  }

Parallelogram::Parallelogram(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts), Trapezoid(name,pts) {
  bool c = Parallel(Vector(pts[0],pts[1]),Vector(pts[2],pts[3]));
  bool d = Parallel(Vector(pts[1],pts[2]),Vector(pts[3],pts[0]));
 
  if (c || d) {
   
   // opposite parallel
  }
  else{
  	throw -1;
  }  
  }  

Arrow::Arrow(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts) {
  // Arrow and kite in only aspect that it has one convex angle


  } 
  bool Arrow::IsConvex() { return false;
   }
// rhombuses must ahve all sides equal
Rhombus::Rhombus(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts), Trapezoid(name,pts), Parallelogram(name,pts), Kite(name,pts) {
  double m1 = DistanceBetween(pts[0],pts[1]);
  double m2 = DistanceBetween(pts[1],pts[2]);
  double m3 = DistanceBetween(pts[2],pts[3]);
  double m4 = DistanceBetween(pts[3],pts[0]);
 // we compare one side with all other sides 
  if (EqualSides(m1,m2) && EqualSides(m2,m3) && EqualSides(m3,m4)) {
    
    
  }
  else{
  	throw -1;
  }
}
 bool Trapezoid::IsConvex() { return true; 
  }
  bool Trapezoid::HasAnObtuseAngle() { return true; 
  } 
IsoscelesTrapezoid::IsoscelesTrapezoid(const std::string &name, const std::vector<Point> &pts):Quadrilateral(name,pts), Trapezoid(name,pts) {
  

  double u1 = Angle(pts[3],pts[0],pts[1]);
  double u2 = Angle(pts[0],pts[1],pts[2]);
  double u3 = Angle(pts[1],pts[2],pts[3]);  
  	if (EqualAngles(u1,u2) && EqualAngles(u2,u3)) {
      
  }  
  else{
  	throw -1;
  }
  double is1 = DistanceBetween(pts[0],pts[1]);
  double is2 = DistanceBetween(pts[1],pts[2]);
  double is3 = DistanceBetween(pts[2],pts[3]);
  double is4 = DistanceBetween(pts[3],pts[0]);
  // isosceles trapezoids must have a pair of equal length edges
  	if (EqualSides(is1,is3) && EqualSides(is2,is4)) {
    
    	
  	}  
  	else{
  		throw -1;
  	}
  
 }
 bool IsoscelesTrapezoid::HasARightAngle() { return false; } 
Rectangle::Rectangle(const std::string &name, const std::vector<Point> &pts) :Quadrilateral(name,pts), Trapezoid(name,pts), Parallelogram(name,pts), IsoscelesTrapezoid(name,pts) {
  	// Rectangle has all angles equal to 90 degrees

  double r1 = Angle(pts[0],pts[1],pts[2]);
  double r2 = Angle(pts[1],pts[2],pts[3]);
  double r3 = Angle(pts[2],pts[3],pts[1]);  
  double r4 = Angle(pts[3],pts[0],pts[1]);  
  
  if (RightAngle(r1) || RightAngle(r2) || RightAngle(r3) || RightAngle(r4)) { 
	 
  }
  else{
  	throw -1;
  }
}
bool Parallelogram::HasARightAngle() { return false;
   } 
 bool Rhombus::HasAllEqualSides() { return true; } 
   bool Rhombus::HasARightAngle() { return false; } 
   bool Rhombus::IsConvex() { return true; }
Square::Square(const std::string &name, const std::vector<Point> &pts) 
  : Quadrilateral(name,pts), Trapezoid(name,pts), Parallelogram(name,pts), Rectangle(name,pts), Rhombus(name,pts) {
  	// Does not need any implementation since it is inherited from many classes and those classes will take care of its implementation

  }
   bool Square::HasARightAngle() { return true; }
   bool Rectangle::HasAllEqualAngles() { return true; } 
   bool Rectangle::HasARightAngle() { return true; } 
   bool Rectangle::HasAnObtuseAngle() { return false; }
