#ifndef ROTATECAMERAX_HPP
#define ROTATECAMERAX_HPP

// Include interface
#include "../src/interface/Rotatable.hpp"

// Include Lense to action
#include "Lense.hpp"

// Actions rotations in the X axis on the lense
class RotateCameraX : public Rotatable
{
private:
    Lense* cam;
    float currentAngle;
public:
    RotateCameraX(Lense* cam);
    ~RotateCameraX();
    float getAngle() const;
    void setAngle(float a);
    void rotate(float a);
};

#endif