#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../src/interface/Drawable.hpp"

class Light : public Drawable
{
private:
    float aPower[4];
	float dPower[4] ;
	float sPower[4] ;
    float pos[3] ;
public:
    Light();
    ~Light();
    void draw();
};

#endif