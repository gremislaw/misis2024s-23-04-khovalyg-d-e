#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rational/rational.hpp"

TEST_CASE("rational io") {
  CHECK(testParse("1/0") == false);
  CHECK(testParse("1/2"));
  CHECK(testParse(" 1/2"));
  CHECK(testParse("1/2 "));
  CHECK(testParse(" 1/2 "));
  CHECK(testParse(" 1 /2 ") == false);
}

TEST_CASE("rational constructor move") {
  Rational r1(1, 2);
  Rational r2(std::move(r1));
  CHECK(r2 == Rational(1, 2));

  Rational r3(3, 4);
  r2 = std::move(r3);
  CHECK(r2 == Rational(3, 4));

  Rational&& r4 = Rational(5, 6);
  CHECK(r4 == Rational(5, 6));
}

TEST_CASE("rational constructor ") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(13);
  CHECK(13 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("rational comparison") {
  Rational lhs(5, 17);
  Rational rhs(-2, 8);
  CHECK(rhs != lhs);

  CHECK(rhs == Rational(-1, 4));
  CHECK((-rhs == Rational(1, 4)));

  CHECK(lhs >= Rational(5, 19));
  CHECK(lhs <= Rational(6, 17));

  CHECK(lhs > Rational(-3, 2));
  CHECK(lhs > Rational(3, -2));

  CHECK((Rational(-3, -5) > rhs));
}

TEST_CASE("rational arithmetics") {
  Rational lhs(13, 15);
  Rational rhs(17, 12);

  CHECK(((lhs + rhs) == Rational(137, 60)));
  CHECK(((lhs - rhs) == Rational(-11, 20)));
  CHECK(((lhs * rhs) == Rational(221, 180)));
  CHECK(((lhs / rhs) == Rational(52, 85)));

  Rational r_negative(2, -1);
  CHECK(((lhs + r_negative) == Rational(-17, 15)));
  CHECK(((lhs - r_negative) == Rational(43, 15)));
  CHECK(((lhs * r_negative) == Rational(-26, 15)));
  CHECK(((lhs / r_negative) == Rational(-13, 30)));

  CHECK_THROWS(lhs / Rational(0, 1));
}
