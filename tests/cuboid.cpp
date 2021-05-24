#include "../tests/doctest/doctest.h"
#include "example.h"
#include "cuboid.hh"

TEST_CASE("KONSTRUKTOR PARAMETRYCZNY")
{ 
  double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
  double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
  double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
  double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
  Vector3D arr[8];
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid C(arr);
  CHECK(C == arr);
}
TEST_CASE("KONSTRUKTOR BEZPARAMETRYCZNY")
{
  Cuboid C; Vector3D arr[8];
  CHECK(C == arr);
}
TEST_CASE("ROTATION OX")
{
  double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
  double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
  double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
  double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
  Vector3D arr[8];
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid C(arr);
  Matrix3x3 M('x', 45);
  C = C.rotation(M);
  double k1[3] {20.0, 49.4974746851, 91.9238815531};
  double k2[3] {20.0, 91.9238815573, 134.3502884234};
  double k3[3] {140.0, 91.9238815573, 134.3502884234};
  double k4[3] {140.0, 49.4974746851, 91.9238815531};
  double k5[3] {20.0, -7.0710678085, 148.4924240493};
  double k6[3] {20, 35.3553390636, 190.9188309196};
  double k7[3] {140, 35.3553390636, 190.9188309196};
  double k8[3] {140, -7.0710678085, 148.4924240493};
  Vector3D arr2[8];
  Vector3D p1(k1); Vector3D p2(k2); Vector3D p3(k3); Vector3D p4(k4);
  Vector3D p5(k5); Vector3D p6(k6); Vector3D p7(k7); Vector3D p8(k8);
  arr2[0] = p1; arr2[1] = p2; arr2[2] = p3; arr2[3] = p4; arr2[4] = p5;
  arr2[5] = p6; arr2[6] = p7; arr2[7] = p8;
  CHECK( C == arr2);
  
}
TEST_CASE("ROTATION OY")
{
  double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
  double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
  double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
  double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
  Vector3D arr[8];
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid C(arr);
  Matrix3x3 M('y', 45);
  C = C.rotation(M);
  double k1[3] {35.3553390592, 100, 7.0710678127};
  double k2[3] {35.3553390592, 160, 7.0710678127};
  double k3[3] {120.2081528035, 160, -77.7817459278};
  double k4[3] {120.2081528035, 100, -77.7817459278};
  double k5[3] {91.9238815528, 100, 63.6396103089};
  double k6[3] {91.9238815528, 160, 63.6396103089};
  double k7[3] {176.7766952971, 160, -21.2132034316};
  double k8[3] {176.7766952971, 100, -21.2132034316};
  Vector3D arr2[8];
  Vector3D p1(k1); Vector3D p2(k2); Vector3D p3(k3); Vector3D p4(k4);
  Vector3D p5(k5); Vector3D p6(k6); Vector3D p7(k7); Vector3D p8(k8);
  arr2[0] = p1; arr2[1] = p2; arr2[2] = p3; arr2[3] = p4; arr2[4] = p5;
  arr2[5] = p6; arr2[6] = p7; arr2[7] = p8;
  CHECK( C == arr2);
  
}
TEST_CASE("OPERATOR <<")
{
  std::stringstream str1, str2;
  double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
  double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
  double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
  double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
  Vector3D arr[8];
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid C1(arr), C2(arr);
  str1 << C1; str2 << C2;
  CHECK( str1.str() == str2.str());
}