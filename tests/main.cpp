#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "dummy.cpp"
#include "vector2D.hh"
#include "matrix2x2.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
TEST_CASE("Porownanie wektora i tablicy")
{   
    double tmp[2] {2,4};
    Vector2D v(tmp);
    CHECK(v == tmp);
}
TEST_CASE("Porownanie dwoch wektorow")
{
    double tmp[2] {3.146, -5.3648};
    Vector2D v1(tmp), v2(tmp);
    CHECK(v1 == v2);
}
TEST_CASE("Dodawanie")
{
    double tmp1[2] {3.146, -5.3648}, tmp2[2] {2.365, 6.12539},
    ans[2] {5.511, 0.76059};
    Vector2D v1(tmp1), v2(tmp2), v3(ans), v4;
    v4 = v1 + v2;
    CHECK(v4 == v3);
}
TEST_CASE("Odejmowanie")
{
    double tmp1[2] {3.146, -5.3648}, tmp2[2] {2.365, 6.12539},
    ans[2] {0.781, -11.49019};
    Vector2D v1(tmp1), v2(tmp2), v3(ans), v4;
    v4 = v1 - v2;
    CHECK(v4 == v3);
}
TEST_CASE("Porownanie dwoch macierzy")
{
    double tmp1[2][2] {2.1456, 3.2654, -6.6524, 4.36250}, tmp2[2][2] {2.1456, 3.2654, -6.6524, 4.36250};
    Matrix2x2 m1(tmp1), m2(tmp2);
    CHECK(m1 == m2);
}