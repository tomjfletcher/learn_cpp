#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../src/interface/Drawable.hpp"

class Light : public Drawable
{
private:
    float aPower[] {0.2f, 0.2f, 0.2f, 1};
	float dPower[] {0.4f, 0.4f, 0.4f, 1};
	float sPower[] {0.8f, 0.8f, 0.8f, 1};
    float pos[] {100, 100, -100};
public:
    void draw();
};

#endif