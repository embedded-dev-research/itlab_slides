#include <iostream>
#include "add/add.h"

int main() {
  const int a = 5;
  const int b = 3;
  std::cout << a << " + " << b << " = " << addlib::add(a, b) << std::endl;
  return 0;
}

