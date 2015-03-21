#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

// standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

#endif // MYEXCEPTION_H
