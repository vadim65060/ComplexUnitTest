#ifndef COMPLEXUNITTEST_COMPLEXTEST_H
#define COMPLEXUNITTEST_COMPLEXTEST_H

#include<iostream>
#include"Complex.h"

#ifndef TEST_ASSERT
#define TEST(x)                     \
    if (!(x)) std::cerr << "check " \
    << #x << " "                    \
    << " failed in file "           \
    << __FILE__                     \
    << " at line "                  \
    << __LINE__ << std::endl
#else
#define TEST(x) assert(x);
#endif


#define EXCEPT_EQ(x, y) TEST((x)==(y))
#define EXCEPT_NQ(x, y) TEST((x)!=(y))
#define EXCEPT_NAN(x) TEST((x)!=(x))
#define EXCEPT_INF(x) TEST((x) == 1.0/0.0 || (x) == -1.0/0.0)
#define EXCEPT_PINF(x) TEST((x) == 1.0/0.0)
#define EXCEPT_NINF(x) TEST((x) == -1.0/0.0)
#define EXCEPT_APPR(x, y, eps)        \
    TEST(std::abs((x-y)/std::max(x,y)) < eps)
#define EXCEPT_NEG(x, y) TEST((x)==(-y))


void test_getValue();

void test_unarOperator();

void test_assignment();

void test_binOperator();

void test_inoutOperator();

#endif //COMPLEXUNITTEST_COMPLEXTEST_H
