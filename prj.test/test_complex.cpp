#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "complex/complex.hpp"
#include "doctest.h"

TEST_CASE("complex io") {
  CHECK(testParse("{1, 2}"));
  CHECK(testParse("{1,2}"));
  CHECK(testParse("{1 ,2 }"));
  CHECK(testParse("{1 2}"));
  CHECK(testParse("{a, 2}") == false);
}

TEST_CASE("complex constructor") {
  Complex c2(1);
  CHECK(c2 == Complex(1, 0));

  Complex c3(1, 2);
  CHECK(c3 == Complex(1, 2));

  Complex c4(c3);
  CHECK(c4 == Complex(1, 2));

  Complex c5 = c3;
  CHECK(c5 == Complex(1, 2));

  Complex c6{};
  CHECK(c6 == Complex(0, 0));
}

TEST_CASE("complex arithmetics") {
  Complex lhs(5, 17);
  Complex rhs(-1, 4);
  CHECK(rhs != lhs);

  CHECK(rhs == Complex(-1, 4));
  CHECK((-rhs == Complex(1, 4)));

  CHECK(((lhs + rhs) == Complex(4, 21)));
  CHECK(((lhs - rhs) == Complex(6, 13)));
  CHECK(((lhs * rhs) == Complex(-5, 68)));
  CHECK(((lhs / rhs) == Complex(-5, 17 / 4)));

  CHECK_THROWS(lhs / Complex(0, 0));
}


