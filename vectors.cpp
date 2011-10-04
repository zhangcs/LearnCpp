/*******************************************
   More advanced example: vectors.cpp
   An example for a simple vector class.
	 Chensong Zhang Feb/08/2011.
********************************************/  

#include <iostream>
#include <new>

using namespace std;

// Define a new vector class ...
class dvector {

public:
  static int num_dvector;

  int      length;
  double * value;

  dvector ();    // do nothing
  dvector (int); // initialize memory
  ~dvector ();   // dereference memory

  void setvalue (int, double);
  void prtvalue ();
  void sum (dvector&, dvector&);
};

dvector::dvector () {
  length = 0;
  value  = 0;
  num_dvector++;
}

dvector::dvector (int l) {
  length = l;
  value  = new (nothrow) double[l];
  num_dvector++;
}

dvector::~dvector () {
  length = 0;
  delete[] value;
  num_dvector--;
}

void dvector::setvalue (int l, double v) {
  int i;

  length = l;
  for (i=0; i<l; i++) value[i] = v;
}

void dvector::prtvalue () {
  int i;
  
  cout << "Length = " << length << endl;
  for (i=0; i<length; i++) cout << "X" << i << " = " << value[i] << endl;
}

void dvector::sum (dvector& a, dvector& b) {

  if (a.length != b.length) {
    cout << "Error: vectors of different length cannot be added!" << endl;
    return;
  }
  
  {
    int i;
    length = a.length;
    for (i=0; i<length; i++) value[i] = a.value[i] + b.value[i];
  }
}

int dvector::num_dvector = 0;

int main () {
  dvector a(3), b(3);

  cout << dvector::num_dvector << endl;

  // initialization
  a.setvalue(3,10.0);
  b.setvalue(3,2.0);

  // summation 
  dvector c(3);
  c.sum (a, b);

  // print out values
  c.prtvalue();

  return 0;
}
