#include "ComplexTest.h"

#include<iostream>
#include<cmath>
#include<sstream>
#include"Complex.h"

void test_getValue() {
    double re1 = 5, im1 = 12, re2 = 1.0 / 0.0, im2 = 0.0 / 0.0;
    double moduleC1 = sqrt(re1 * re1 + im1 * im1);
    Complex c1(re1, im1), c2(re2, im2);
    const double cre = c1.get_Re(), cim = c1.get_Im();
    const double c2re = c2.get_Re(), c2im = c2.get_Im();
    EXCEPT_EQ(cre, re1);
    EXCEPT_EQ(cim, im1);
    EXCEPT_INF(c2re);
    EXCEPT_NAN(c2im);
    EXCEPT_EQ(c1.Module(), moduleC1);
    c1 = c1.Co();
    EXCEPT_EQ(cre, c1.Re());
    EXCEPT_EQ(cim, -c1.Im());
}

void test_unarOperator() {
    double re1 = 5, im1 = 12, re2 = 1.0 / 0.0, im2 = -1.0 / 0.0;
    Complex c1(re1, im1), c2(re2, im2);
    EXCEPT_NEG(c1, -c1);
    EXCEPT_NEG(c2, -c2);
    EXCEPT_EQ(c1, +c1);
    EXCEPT_EQ(c2, +c2);
}

void test_assignment() {
    double re1 = 3, im1 = 34, re2 = 1.0 / 0.0, im2 = -1.0 / 0.0;
    double eps = 1e-14;
    Complex c1(re1, im1), c2(re2, im2);
    Complex c3 = c1, c4 = c2;
    EXCEPT_EQ(c1, c3);
    EXCEPT_EQ(c2, c4);

    double re5 = -7, im5 = 2, re6 = 9, im6 = -1;
    Complex c5(re5, im5), c6(re6, im6);
    c3 = {0, 0};
    c3 += c5;
    c4 = {0, 0};
    c4 -= c6;
    EXCEPT_EQ(c3, c5);
    EXCEPT_NEG(c4, c6);

    c3 *= c1;
    c4 *= c1;
    Complex cBlank3 = c5 * c1, cBlank4 = -c6 * c1;
    EXCEPT_EQ(c3, cBlank3);
    EXCEPT_NEG(c4, cBlank4);

    c3 /= c1;
    EXCEPT_APPR(c3.Re(), c5.Re(), eps);
    EXCEPT_APPR(c3.Im(), c5.Im(), eps);

    c3 /= 2;
    EXCEPT_APPR(c3.Re(), -3.5, eps);
    EXCEPT_APPR(c3.Im(), 1., eps);
}

void test_binOperator() {
    double d = 4;
    Complex c1(5, -12), c2(-8, 6), c3(1, 0);
    Complex c4(0, 2), c5(2, 0), c6(0, 1), c7(0, 2);
    Complex Check(4, -3);
    bool eq37 = (c3 == c5), eq38 = (c3 == c6), eq48 = (c4 == c6), eq47 = (c4 == c5), eq49 = (c4 == c7);
    EXCEPT_EQ(eq37, 0);
    EXCEPT_EQ(eq38, 0);
    EXCEPT_EQ(eq48, 0);
    EXCEPT_EQ(eq47, 0);
    EXCEPT_EQ(eq49, 1);
    EXCEPT_EQ(c2 / (-2), Check);
    Complex res = c1.Module() * c2.Module() - c4 + 3 * c3 + (-d) * c2 + c2 / d * c4;
    Complex Check2(162, -30);
    EXCEPT_EQ(res, Check2);

    Complex c00(0, 0);
    Complex c01(1, 1);
    Complex r0 = c00 / c00, r1 = c01 / c00, d0 = 0 / c00, d1 = 1.0 / c00;
    EXCEPT_NAN(r0.Re());
    EXCEPT_NAN(r0.Im());
    EXCEPT_NAN(r1.Re());
    EXCEPT_NAN(r1.Im());

    EXCEPT_NAN(d0.Re());
    EXCEPT_NAN(d0.Im());
    EXCEPT_NAN(d1.Re());
    EXCEPT_NAN(d1.Im());
}

void test_inoutOperator() {
    int re1 = 1, im1 = -7;
    Complex c1(re1, im1);
    double cre, cim;
    char buffer;
    std::stringstream str;
    str << c1;
    std::string testStr = "(" + std::to_string(re1) + ", " + std::to_string(im1) + ")";
    EXCEPT_EQ(str.str(), testStr);

    std::cout << "io test:\n";
    str >> buffer >> cre >> buffer >> cim >> buffer;
    std::cout << cre << " " << cim << std::endl;
    EXCEPT_EQ(cre, c1.Re());
    EXCEPT_EQ(cim, c1.Im());
}