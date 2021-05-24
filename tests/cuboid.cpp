#include "../tests/doctest/doctest.h"
#include "example.h"
#include "cuboid.hh"

double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY")
{ 
  Vector3D arr[8];
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid c(arr);
  Matrix3x3 m('x', 45);
  c = c.rotation(m);
  std::cout << c;

}
