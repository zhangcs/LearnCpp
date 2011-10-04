/******************************************* 
   Second example: second.cpp
   A simple example for classes and methodes.
	 Chensong Zhang Feb/08/2011.
********************************************/

#include <iostream>
#include <string>

using namespace std;

// class definition ...
class Student {
  string name;
  unsigned short int age;
  short sex; // 1 for male, -1 for female 

public: // public methods
  // constructor with default values
  Student(string myname="Name", int myage=20, short mysex=1) {
    name = myname;
    age  = myage;
    sex  = mysex;
  }

  void   set_name(string givename);
  void   set_age(unsigned short i);
  void   set_sex(int givensex);
  void   output();

private: // private methods 
  string output_name();
  int    output_age();  
  string output_sex();
};

// definitions of the class members ...

void   Student::set_name (string givename) { name.assign(givename); }

string Student::output_name () { return name; }

void   Student::set_age (unsigned short i) { age = i; }

int    Student::output_age () { return age; }

void   Student::set_sex (int givensex) { sex = givensex; }

string Student::output_sex () { if (sex) return "male"; else return "female"; }

void   Student::output() {
  cout << output_name() << " is a " 
       << output_sex()  << " of age " 
       << output_age()  << "."
       << endl;
}

// main program here ...
int main()
{
  Student Chensong, Yan;

  cout << "Before setting values ..." << endl;
  Chensong.output();
  Yan.output();

  // set values 
  Chensong.set_name("Chensong"); Chensong.set_age(33); Chensong.set_sex(1);
  Yan.set_name("Yan"); Yan.set_age(28); Yan.set_sex(0);

  cout << "After setting values ..." << endl;
  Chensong.output();
  Yan.output();

  return 0;
}
