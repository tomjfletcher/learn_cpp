#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "../src/interface/Drawable.hpp"

class Material : public Drawable
{
private:
    float rgba[4];
public:
    Material(float r, float g, float b, float a);
    ~Material();
    void draw();
};

#endif