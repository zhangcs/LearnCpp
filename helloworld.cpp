/*******************************************
   First example: first.cpp
   A simple example for i/o.
	 Chensong Zhang Feb/08/2011.
********************************************/

#include <iostream>

// main program here ...
int main()
{
  // output
  std::cout << "Hello, world! This is the first example." << "\n";

  // input
  std::cout << "Hit ENTER to continue ...";
  std::cin.get();

  return 0;
}
