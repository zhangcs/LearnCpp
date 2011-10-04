/*******************************************
   Fourth example: functions.cpp
   A simple example for function calls:
      - function overload, 
      - recursive calls.
	 Chensong Zhang Feb/08/2011.
********************************************/  

#include <iostream>

using namespace std;

// mult function for int
int mult (int a=0, int b=0)
{
  return (a*b);
}

// mult function reloaded for double
// We can use template to do this to make it more general!!!
double mult (double a=0.0, double b=0.0)
{
  return (a*b);
}

// recursive call
long factorial (long a)
{
  if (a > 1)
    return (a * factorial (a-1));
  else
    return (1);
}

int main ()
{
  double x=5, y=2;
  int    n=5, m=2;

  cout << scientific << mult (x,y) << endl;
  cout << scientific << mult (n,m) << endl;
  cout << scientific << factorial ( mult (n,m) ) << endl;

  return 0;
}
