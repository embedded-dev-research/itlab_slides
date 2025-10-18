#include <fmt/format.h>
#include "add/add.h"

int main() {
  int a = 7, b = 5;
  fmt::print("{} + {} = {}\n", a, b, addlib::add(a, b));
  return 0;
}

