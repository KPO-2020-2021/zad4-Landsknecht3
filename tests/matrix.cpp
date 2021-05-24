#include "../tests/doctest/doctest.h"
#include "example.h"
#include "matrix2x2.hh"
#include "matrix3x3.hh"
#include "vector2D.hh"
#include "vector3D.hh"

TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY MACIERZY 2X2 POROWNANIE Z TABLICA")
{
  Matrix2x2 m; double tmp[2][2] {0, 0, 0, 0};
  CHECK(m == tmp);
}
TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY MACIERZY 3X3 POROWNANIE Z TABLICA")
{
  Matrix3x3 m; double tmp[3][3] {{0,0,0}, {0,0,0}, {0,0,0}};
  CHECK(m == tmp);
}
TEST_CASE("KONSTRUKTOR PARAMETRYCZNY MACIERZY 2X2 POROWNANIE DWOCH MACIERZY")
{
    double tmp1[2][2] {2.1456, 3.2654, -6.6524, 4.36250}, tmp2[2][2] {2.1456, 3.2654, -6.6524, 4.36250};
    Matrix2x2 m1(tmp1), m2(tmp2);
    CHECK(m1 == m2);
}
TEST_CASE("kONSTRUKTOR MACIERZY 2x2")
{
  double tmp1[2][2] {2.1456, 3.2654, -6.6524, 4.36250};
    Matrix2x2 m1(tmp1);
    CHECK(m1 == tmp1);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU 2x2")
{
    double degr = 45;
    Matrix2x2 m1(degr);
    double tmp [2][2] ={sqrt(2)/2, -sqrt(2)/2, sqrt(2)/2, sqrt(2)/2};
    CHECK(m1 == tmp);
}
TEST_CASE("KONSTRUKTOR MACIERZY 3x3")
{
  double tmp[3][3] = {{2.3654, 25.365, -5.3654}, {78.654, 8.3641, -82.3645}, {0.36541, -0.65423, 80.1431}};
  Matrix3x3 m1(tmp);
  CHECK(m1 == tmp);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU 3X3 OX")
{
  double degr = 45;
  Matrix3x3 m1('x', degr);
  double tmp[3][3] = {{1, 0, 0}, {0, sqrt(2)/2, -sqrt(2)/2}, {0, sqrt(2)/2, sqrt(2)/2}};
  CHECK(m1 == tmp);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU 3X3 OY")
{
  double degr = 45;
  Matrix3x3 m1('y', degr);
  double tmp[3][3] = {{sqrt(2)/2, 0, sqrt(2)/2}, {0, 1, 0}, {-sqrt(2)/2, 0, sqrt(2)/2}};
  CHECK(m1 == tmp);
}
TEST_CASE("KONSTRUKTOR MACIERZY OBROTU 3X3 OZ")
{
  double degr = 45;
  Matrix3x3 m1('z', degr);
  double tmp[3][3] = {{sqrt(2)/2, -sqrt(2)/2, 0}, {sqrt(2)/2, sqrt(2)/2, 0}, {0, 0, 1}};
  CHECK(m1 == tmp);
}
TEST_CASE("ILOCZYN MACIERZY 2X2 I WEKTORA2D")
{
  double tmp1[2] {2, 4}; double tmp2[2][2] = {{5, 12}, { -9, 7}}; double tmp3[2] {58, 10};
  Vector2D v(tmp1); Matrix2x2 m(tmp2);
  Vector2D v2 = m*v;
  CHECK(v2 == tmp3);
}
TEST_CASE("ILOCZYN MACIERZY 3X3 I WEKTORA3D")
{
  double tmp1[3] {2, 4, 7}; double tmp2[3][3] = {{5, 12, -8}, { -9, 7, 13}, {4, -5, 3}}; double tmp3[3] {2, 101, 9};
  Vector3D v(tmp1); Matrix3x3 m(tmp2);
  Vector3D v2 = m*v;
  CHECK(v2 == tmp3);
}
TEST_CASE("ILOCZYN DWOCH MACIERZY2X2")
{
  double degr = 45; double tmp[2][2] {1, 0, 0, 1};
  Matrix2x2 m1(degr), m2(-degr);
  Matrix2x2 m3 = m1*m2;
  CHECK(m3 == tmp);
}
TEST_CASE("ILOCZYN DWOCH  OBROTUMACIERZY3X3 X")
{
  double degr = 45; double tmp[3][3] {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Matrix3x3 m1('x', degr), m2('x', -degr);
  Matrix3x3 m3 = m1*m2;
  CHECK(m3 == tmp);
}
TEST_CASE("ILOCZYN DWOCH OBROTU MACIERZY3X3 Y")
{
  double degr = 45; double tmp[3][3] {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Matrix3x3 m1('y', degr), m2('y', -degr);
  Matrix3x3 m3 = m1*m2;
  CHECK(m3 == tmp);
}
TEST_CASE("ILOCZYN DWOCH OBROTU MACIERZY3X3 Z")
{
  double degr = 45; double tmp[3][3] {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Matrix3x3 m1('z', degr), m2('z', -degr);
  Matrix3x3 m3 = m1*m2;
  CHECK(m3 == tmp);
}
TEST_CASE("SUMA DWOCH MACIERZY 2X2")
{
  double tmp1[2][2] {2, 4, 6, 7}; double tmp2[2][2] = {{5, 12}, { -9, 7}}; double tmp3[2][2] {7, 16, -3, 14};
  Matrix2x2 m1(tmp1); Matrix2x2 m2(tmp2);
  Matrix2x2 m3 = m1 + m2;
  CHECK(m3 == tmp3);
}
TEST_CASE("SUMA DWOCH MACIERZY 2X2")
{
  double tmp1[3][3] {{2, 4, 6}, {7, -10, 12}, {5, -14, 63}}; double tmp2[3][3] = {{5, 12, -9},{7, 5, -43}, {63, 24, -9}};
  double tmp3[3][3] {{7, 16, -3}, {14, -5, -31}, {68, 10, 54}};
  Matrix3x3 m1(tmp1); Matrix3x3 m2(tmp2);
  Matrix3x3 m3 = m1 + m2;
  CHECK(m3 == tmp3);
}
TEST_CASE("OPERATOR <<")
{
  std::stringstream str1, str2;
  double tmp1[3][3] {{2, 4, 6}, {7, -10, 12}, {5, -14, 63}};
  Matrix3x3 m1(tmp1), m2(tmp1);
  str1 << m1; str2 << m2;
  CHECK( str1.str() == str2.str());
}