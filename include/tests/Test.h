#pragma once

#include <string>

#define ASSERT_EQUALS(x, y)                                                                                           \
    {                                                                                                                 \
        if ((x) != (y))                                                                                               \
            std::cout << __FUNCTION__ << " failed on line " << __LINE__ << ": " << (x) << " != " << (y) << std::endl; \
    }

#define ASSERT_TRUE(x)                                                                                             \
    {                                                                                                              \
        if (!(x))                                                                                                  \
            std::cout << __FUNCTION__ << " failed on line " << __LINE__ << ": " << #x << " is false" << std::endl; \
    }

#define ASSERT_FALSE(x)                                                                                           \
    {                                                                                                             \
        if (x)                                                                                                    \
            std::cout << __FUNCTION__ << " failed on line " << __LINE__ << ": " << #x << " is true" << std::endl; \
    }

class Test
{
protected:
    std::string name;

public:
    Test();
    Test(std::string name);
    virtual void setup() = 0;
    virtual void run() = 0;
};