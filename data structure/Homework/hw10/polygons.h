#include <iostream>
#include <vector>
#include "utilities.h"
class Polygon{  //Declaration of the polygon class 
public:
	Polygon(const std::string &name, const std::vector<Point> &pts);
	const std::string & getName() const {
    return name;
  }
	virtual bool HasAllEqualSides(); 
	virtual bool HasAllEqualAngles();
	virtual bool HasARightAngle();
	virtual bool HasAnObtuseAngle();
	virtual bool HasAnAcuteAngle();
  virtual bool IsConvex();
	virtual bool IsConcave(){ 
    return !IsConvex();
     }

	
protected:
	std::vector<Point> vertices;
	std::string name;
};
//Declaration of the triangle class
class Triangle: public Polygon{
public:
	Triangle(const std::string &name, const std::vector<Point> &pts);
	 virtual bool HasAllEqualAngles();
	 virtual bool HasAllEqualSides(); 
	 virtual bool HasARightAngle() ;
	 virtual bool HasAnObtuseAngle() ;
	 bool HasAnAcuteAngle(); 
	  bool IsConvex();
};
// Right Angle class
class RightTriangle:virtual public Triangle{
public:
	
  RightTriangle(const std::string &name, const std::vector<Point> &pts);  
  virtual bool HasARightAngle() ;
};
//Isosceles Triangle class

class IsoscelesTriangle : virtual public Triangle {
 public:
  
  IsoscelesTriangle(const std::string &name, const std::vector<Point> &pts);
};
//Obtuse Traingle Class
class ObtuseTriangle : virtual public Triangle {
 public:
  
  ObtuseTriangle(const std::string &name, const std::vector<Point> &pts);  
  virtual bool HasAnObtuseAngle();
};

// Isosceles Right triangle class
class IsoscelesRightTriangle : public IsoscelesTriangle, public RightTriangle {
 public:
  IsoscelesRightTriangle(const std::string &name, const std::vector<Point> &pts);
};
//Isosceles Obtuse Triangle class

class IsoscelesObtuseTriangle : public IsoscelesTriangle, public ObtuseTriangle {
 public:
  IsoscelesObtuseTriangle(const std::string &name, const std::vector<Point> &pts);
};

//Equi;lateral triangle class
class EquilateralTriangle : public IsoscelesTriangle {
 public:
  
  EquilateralTriangle(const std::string &name, const std::vector<Point> &pts);
  virtual bool HasAllEqualSides() ;
  virtual bool HasAllEqualAngles() ;
  virtual bool HasARightAngle() ;

};
//Quadrilateral class

class Quadrilateral : public Polygon {
 public:
  
  Quadrilateral(const std::string &name, const std::vector<Point> &pts);
  
  virtual bool HasAllEqualAngles();
  virtual bool HasAllEqualSides();
};
//Trapezoid class


class Kite : virtual public Quadrilateral {
 public:
  
  Kite(const std::string &name, const std::vector<Point> &pts);
  virtual bool IsConvex();
};
//Trapezoid class inherited from quadrilateral


class Trapezoid : virtual public Quadrilateral {
 public:
  Trapezoid(const std::string &name, const std::vector<Point> &pts);
  
  virtual bool IsConvex() ;
  virtual bool HasAnObtuseAngle();
};
//Arrow class

class Arrow : public Quadrilateral {
 public:
  
  Arrow(const std::string &name, const std::vector<Point> &pts);
  virtual bool IsConvex();
};



// Isosceles Trapezoid class inherited from trapezoid
class IsoscelesTrapezoid : virtual public Trapezoid {
 public:
  
  IsoscelesTrapezoid(const std::string &name, const std::vector<Point> &pts);
  virtual bool HasARightAngle();
};
class Parallelogram : virtual public Trapezoid {
 public:
  
  Parallelogram(const std::string &name, const std::vector<Point> &pts);
  virtual bool HasARightAngle();
};
//Rhombus class
class Rhombus : virtual public Parallelogram, public Kite {
 public:
  Rhombus(const std::string &name, const std::vector<Point> &pts);
  
  virtual bool HasAllEqualSides();
  virtual bool HasARightAngle();
  virtual bool IsConvex();
};
//Rectangle class
class Rectangle : virtual public Parallelogram, public IsoscelesTrapezoid {
    public:
  Rectangle(const std::string &name, const std::vector<Point> &pts);
  
  virtual bool HasAllEqualAngles() ;
  virtual bool HasARightAngle();
  virtual bool HasAnObtuseAngle();
};
//Square class
class Square : public Rectangle, public Rhombus {
 public:
  
  Square(const std::string &name, const std::vector<Point> &pts);
  virtual bool HasARightAngle();
};

