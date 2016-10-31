#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const int global_count = 5;
const int max_count = 1000000;



TEST(MathTest, TwoPlusTwoEqualsFour)
{
    for (int i = 0; i < 10000000; ++i)
    {
        int ii = i*i;
    }
}

TEST(MathTest, TwoPlusTwoEqualsFour_2)
{
    for (int i = 0; i < 100000000; ++i)
    {
        int ii = i*i;
    }
}


