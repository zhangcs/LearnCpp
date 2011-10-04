/*******************************************
   Third example: third.cpp
   An example for simple math calculations. 
	 Chensong Zhang Feb/08/2011.	 
********************************************/  

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  int i,j,a=1,b=1;
  float c=1.0,d=1.0;
  double e=1.0,f=1.0;
  double start, finish;

  // start timing
  start=clock();

  // computation part
	// make it intensive to compare compiler performance.
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 100000; j++) {
      a = a + 50;
      b = a - 100;
      a = b * 20;
      c = a + 300.89;
      d = c - 600.89;
      c = d * 90.89;
      d = c / 55.89;
      e = c * 90.89;
      f = e / 55.89;
    }
  }
  
  // stop timing
  finish=clock();

  cout << "Results " << scientific << f << endl;
  cout << "Computation costs " << (finish-start)/CLOCKS_PER_SEC << " seconds" 
       << endl;

  return 0;
}
