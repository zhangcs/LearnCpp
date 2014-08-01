// This is an example to try out different features of object-oriented programming

// Some header files needed
#include <iostream>
#include <sstream>    
#include <cmath>

#define MY_PI 3.1415926

using namespace std; // use a specific name space

// Define a simple d-dimensional Point class
class Point {

public:
    Point(double, double); // constructor
    Point(double, double, double); // overload constructor
    Point(const Point &); // copy constructor
    ~Point(); // destructor

    void set_value(int, double); // set value of one coordinate
    int get_dim() const { return dim; } // dim of space (define in-place)
    double get_length() const; // length of point vector 
    string disp_Point() const; // show Point (const method)
    friend ostream & operator <<(ostream &, const Point &); // overload <<

private:
    int     dim;
    double *coor;

};

// Define a d-dimensional Circle class derived from Point
class Circle : public Point {

public:
    Circle(double x=0, double y=0, double r=1); // constructor with default value
    Circle(double, double, double, double); // overload constructor
    Circle(const Circle &); // copy constructor
    ~Circle(); // destructor

    void set_radius(double); // set value of radius
    double get_radius() const { return radius; } // radius of circle
    double get_area() const; // area of circle
    friend ostream & operator <<(ostream &, const Circle &); // overload <<

private: 
    double radius; // radius of the circle

};

// constructor: create a new Point
Point :: Point(double x, double y) {
    dim = 2;
    coor = new double[dim];
    coor[0] = x; coor[1] = y;
}

// constructor: create a new Point
Point :: Point(double x, double y, double z) {
    dim = 3;
    coor = new double[dim];
    coor[0] = x; coor[1] = y; coor[2] = z;
}

// copy constructor
Point :: Point(const Point & pt) {
    dim = pt.dim;
    coor = new double[dim];
    for ( int i = 0; i < dim; i++ ) coor[i] = pt.coor[i];
}

// destructor: remove a Point
Point :: ~Point() {
    cout << "Point " << disp_Point() << " is removed!" << endl;
    delete coor;
}

// show a Point
string Point :: disp_Point() const {
    ostringstream s;
    if ( dim == 2 ) {
        s << "(" << coor[0] << ", " << coor[1] << ")";
    }
    else if ( dim == 3 ) {
        s << "(" << coor[0] << ", " << coor[1] << ", " << coor[2] << ")";
    }
    return s.str();
}

// change value of a coordinate
void Point :: set_value(int i, double value) {
    coor[i] = value;
}

// compute length of vector
double Point :: get_length() const {
    if ( dim == 2 ) {
        return sqrt(pow(coor[0],2)+pow(coor[1],2));
    }
    else if ( dim == 3 ) {
        return sqrt(pow(coor[0],2)+pow(coor[1],2)+pow(coor[2],2));
    }
}

// constructor: create a new circle
Circle :: Circle(double x, double y, double r) : Point(x,y) {
    radius = r;
}

// constructor: create a new Point
Circle :: Circle(double x, double y, double z, double r) : Point(x,y,z) {
    radius = r;
}

// copy constructor
Circle :: Circle(const Circle & c) : Point(c) {
    radius = c.radius;
}

// destructor: remove a circle: simple!
Circle :: ~Circle() {
    cout << "Circle is removed!" << endl;
}

// set radius of a circle 
void Circle :: set_radius(double r) {
    radius = r;
}

// get area of a circle 
double Circle :: get_area() const {
    return MY_PI * pow(radius, 2);
}

// overload << opeartor -- This is outside of the Point class, as friend!
// Here we use "const Point & pt". So it can only access const methods. 
ostream & operator <<(ostream & out, const Point & pt) {
    out << pt.disp_Point();
    return out; 
}

ostream & operator <<(ostream & out, const Circle & c) {
    out << c.disp_Point() << "--" << c.radius;
    return out; 
}

// test function
int main()
{
    double xcoor[3] = {1.0, -1.0, 0.0};

    cout << "Test begin ..." << endl;

    cout << "Outside: " << xcoor[0] << ", " << xcoor[1] << ", " << xcoor[2] << endl;

    Point pt1 (xcoor[0], xcoor[1]);
    cout << "Point 1: " << pt1 << " = " << pt1.get_length() << endl;

    Point pt2 (xcoor[0], xcoor[1], xcoor[2]);
    cout << "Point 2: " << pt2 << " = " << pt2.get_length() << endl;

    Point pt3 = pt2; pt3.set_value(2, 1.0/3.0);
    cout << "Point 3: " << pt3 << " = " << pt3.get_length() << endl;

    Circle c1;
    cout << "Circle 1:" << c1 << endl;

    c1.set_radius(1.5);

    Circle c2 = c1;
    cout << "Circle 2:" << c2 << endl;

    cout << "Test finished!" << endl;
}
