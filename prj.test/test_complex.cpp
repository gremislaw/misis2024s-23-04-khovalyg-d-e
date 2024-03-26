#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "complex/complex.hpp"
#include "doctest.h"

TEST_CASE("complex io") {
  CHECK(testParse("{1, 2}"));
  CHECK(testParse("{1,2}"));
  CHECK(testParse("{1 ,2 }"));
  CHECK(testParse("{1 2}") == false);
  CHECK(testParse("{a, 2}") == false);
}

TEST_CASE("complex constructor move") {
  Complex c1(1, 2);
  Complex c2(std::move(c1));
  CHECK(c2.re == 1);
  CHECK(c2.im == 2);

  Complex c3 = std::move(c2);
  CHECK(c3.re == 1);
  CHECK(c3.im == 2);

  Complex &&c4 = Complex(1, 2);
  CHECK(c4.re == 1);
  CHECK(c4.im == 2);
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
  CHECK((-rhs == Complex(1, -4)));

  CHECK(((lhs + rhs) == Complex(4, 21)));
  CHECK(((lhs - rhs) == Complex(6, 13)));
  CHECK(((lhs * rhs) == Complex(-73, 3)));
  CHECK(((lhs / rhs) == Complex((double)63 / 17, (double)-37 / 17)));

  CHECK_THROWS(lhs / Complex(0, 0));
}
