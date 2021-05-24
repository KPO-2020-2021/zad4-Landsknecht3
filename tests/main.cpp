#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "dummy.cpp"
#include "vector2D.hh"
#include "vector3D.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY WEKTORA 2X2 POROWNANIE Z TABLICA")
{
    double tmp[2] {0, 0};
    Vector2D v;
    CHECK(v == tmp);
}
TEST_CASE("KONSTRUKTOR PARAMETRYCZNY WEKTORA 2X2 POROWNANIE Z TABLICA")
{   
    double tmp[2] {2,4};
    Vector2D v(tmp);
    CHECK(v == tmp);
}
TEST_CASE("KONSTRUKTOR PARAMETRYCZNY WEKTORA 2X2 POROWNANIE DWOCH WEKTOROW 2X2")
{
    double tmp[2] {3.146, -5.3648};
    Vector2D v1(tmp), v2(tmp);
    CHECK(v1 == v2);
}
TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY WEKTORA 3X3 WEKTORA 3X3 POROWNANIE Z TABLICA")
{
    double tmp[3] {0, 0, 0};
    Vector3D v;
    CHECK(v == tmp);
}
TEST_CASE("KONSTRUKTOR PARAMETRYCZNY WEKTORA 3X3 POROWNANIE Z TABLICA")
{   
    double tmp[3] {2,4, 6};
    Vector3D v(tmp);
    CHECK(v == tmp);
}
TEST_CASE("KONSTRUKTOR PARAMETRYCZNY WEKTORA 3X3 POROWNANIE DWOCH WEKTOROW 2X2")
{
    double tmp[3] {3.146, -5.3648, 3.125547};
    Vector3D v1(tmp), v2(tmp);
    CHECK(v1 == v2);
}
TEST_CASE("DODAWANIE WEKTOROW 2X2")
{
    double tmp1[2] {3.146, -5.3648}, tmp2[2] {2.365, 6.12539},
    ans[2] {5.511, 0.76059};
    Vector2D v1(tmp1), v2(tmp2), v3(ans), v4;
    v4 = v1 + v2;
    CHECK(v4 == v3);
}
TEST_CASE("ODEJMOWANIE WEKTOROW 2X2")
{
    double tmp1[2] {3.146, -5.3648}, tmp2[2] {2.365, 6.12539},
    ans[2] {0.781, -11.49019};
    Vector2D v1(tmp1), v2(tmp2), v3(ans), v4;
    v4 = v1 - v2;
    CHECK(v4 == v3);
}
TEST_CASE("ILOCZYN WEKTORA 2X2 I LICZBY")
{
    double tmp1[2] {2,4}; double a = 3.2;
    Vector2D v1(tmp1); double tmp[2] {6.4, 12.8};
    Vector2D v2 = v1 * a;
    CHECK(v2 == tmp);
}
TEST_CASE("ILORAZ WEKTORA 2X2 I LICZBY")
{
    double tmp1[2] {32, 84}; double a = 3.2;
    Vector2D v1(tmp1); double tmp[2] {10, 26.25};
    Vector2D v2 = v1 / a;
    CHECK(v2 == tmp);
}
TEST_CASE("TEST FUNKCJI LENGTH")
{
    double tmp[2] {3.45, -5.56}; double tmp2[2] {5.36, -2.7892};
    Vector2D v(tmp); double a = 3.3653280137;
    double l = v.length(tmp2);
    CHECK(l - a < epsilon);
}
TEST_CASE("OPERATOR <<")
{
  std::stringstream str1, str2;
  double tmp1[3] {2, 4, 6};
  Vector3D v1(tmp1), v2(tmp1);
  str1 << v1; str2 << v2;
  CHECK( str1.str() == str2.str());
}