#include <gtest/gtest.h>
#include <cmath>

const double getA(const double x, const double y, const double z)
{
    return sqrt((x * x) + y) - (y * y) * sin((x + z) / x) * sin((x + z) / x) * sin((x + z) / x);
}

const double getB(const double x, const double y, const double z)
{
    return cos(x * x * x) * cos(x * x * x) - x / ((z * z) + (y * y));
}

TEST(TestFunctions, TestGetA)
{
    const double x = 1.0;
    const double y = 2.0;
    const double z = 3.0;

    const double expected = sqrt((x * x) + y) - (y * y) * sin((x + z) / x) * sin((x + z) / x) * sin((x + z) / x);
    const double result = getA(x, y, z);

    EXPECT_DOUBLE_EQ(expected, result);
}

TEST(TestFunctions, TestGetB)
{
    const double x = 1.0;
    const double y = 2.0;
    const double z = 3.0;

    const double expected = cos(x * x * x) * cos(x * x * x) - x / ((z * z) + (y * y));
    const double result = getB(x, y, z);

    EXPECT_DOUBLE_EQ(expected, result);
}
