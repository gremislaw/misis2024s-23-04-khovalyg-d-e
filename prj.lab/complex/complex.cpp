#include "complex.hpp"

Complex::Complex(): re(0.0), im(0.0) {}

Complex::Complex(const Complex& other): re(other.re), im(other.im) {}

Complex::Complex(const double real) : re(real), im(0.0) {}

Complex::Complex(const double real, const double imaginary)
    : re(real), im(imaginary) {}
Complex& Complex::operator=(const Complex& other) {
  re = other.re;
  im = other.im;
  return *this;
}

Complex Complex::operator-() const { return Complex(-re, -im); }

Complex& Complex::operator+=(const Complex& other) {
  re += other.re;
  im += other.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& other) {
  re -= other.re;
  im -= other.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) {
  re -= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& other) {
  double denominator = other.re * other.re + other.im * other.im;
  if (denominator == 0.0) {
    throw std::string("Division by zero");
  }
  double temp_re = (re * other.re + im * other.im) / denominator;
  im = (im * other.re - re * other.im) / denominator;
  re = temp_re;
  return *this;
}

Complex& Complex::operator/=(const double rhs) {
  if (rhs == 0.0) {
    throw std::string("Division by zero");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& other) {
  double temp_re = re * other.re - im * other.im;
  im = re * other.im + im * other.re;
  re = temp_re;
  return *this;
}

Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

bool Complex::operator==(const Complex& other) const {
  return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex& other) const {
  return !(*this == other);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char rightBrace(0);

  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) &&
        (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) += rhs;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) -= rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) /= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) *= rhs;
}

Complex operator+(double lhs, const Complex& rhs) {
  return Complex(lhs) += Complex(rhs);
}

Complex operator-(double lhs, const Complex& rhs) {
  return Complex(lhs) -= Complex(rhs);
}

Complex operator/(double lhs, const Complex& rhs) {
  return Complex(lhs) /= Complex(rhs);
}

Complex operator*(double lhs, const Complex& rhs) {
  return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator+(const Complex& lhs, double rhs) {
  return Complex(lhs) += Complex(rhs);
}

Complex operator-(const Complex& lhs, double rhs) {
  return Complex(lhs) -= Complex(rhs);
}

Complex operator/(const Complex& lhs, double rhs) {
  return Complex(lhs) /= Complex(rhs);
}

Complex operator*(const Complex& lhs, double rhs) {
  return Complex(lhs) *= Complex(rhs);
}

bool testParse(const std::string& str) noexcept {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good() || istrm.eof()) {
    std::cout << "Read Success: ";
  }
  else {
    std::cout << "Read Error: ";
  }
  std::cout << "read " << z << " from " << str << '\n';
  return istrm.good();
}
