/*******************************************
   More advanced example: template.cpp
   A simple example of template for functions.
	 Chensong Zhang Feb/08/2011.	 
********************************************/

#include <iostream>

using namespace std;

// Find max of two numbers. They could be of different types. 
template <class A, class B>
A GetMax (A a, B b) {
  return (a>b?a:b);
}

int main () {
  int   i=5,  j=6, k;
  float l=10, m=5, n;

  k=GetMax<int, float>(i,l);
  n=GetMax<float, int>(m,j);

  cout << k << endl;
  cout << n << endl;

  return 0;
}

