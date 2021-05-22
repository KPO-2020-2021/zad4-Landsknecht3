#include "../tests/doctest/doctest.h"
#include "example.h"
#include "matrix2x2.hh"
#include "matrix3x3.hh"

TEST_CASE("kONSTRUKTOR MACIERZY")
{
  double tmp1[2][2] {2.1456, 3.2654, -6.6524, 4.36250}, tmp2[2][2] {2.1456, 3.2654, -6.6524, 4.36250};
    Matrix2x2 m1(tmp1), m2(tmp2);
    CHECK(m1 == m2);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU")
{
    double degr = 45;
    Matrix2x2 m1(degr);
    double tmp [2][2] ={sqrt(2)/2, -sqrt(2)/2, sqrt(2)/2, sqrt(2)/2};
    Matrix2x2 m2(tmp);
    CHECK(m1 == m2);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU 3X3")
{
  double degr = 45;
  Matrix3x3 m1('x', degr);
  double tmp[3][3] = {{1, 0, 0}, {0, sqrt(2)/2, -sqrt(2)/2}, {0, sqrt(2)/2, sqrt(2)/2}};
  Matrix3x3 m2(tmp);
  std::cout << m1 << std::endl << m2;
  CHECK(m1 == m2);
}