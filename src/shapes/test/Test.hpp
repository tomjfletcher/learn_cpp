#ifndef TEST_HPP
#define TEST_HPP

#include "../src/interface/Drawable.hpp"

class Test : public Drawable
{
public:
    Test();
    ~Test();
    void draw();
};

#endif