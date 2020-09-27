#ifndef ROTATECAMERAY_HPP
#define ROTATECAMERAY_HPP

// Include interface
#include "../src/interface/Rotatable.hpp"

// Include Lense to action
#include "Lense.hpp"

// Actions rotations in the Y axis on the lense
class RotateCameraY : public Rotatable
{
private:
    Lense cam;
    float currentAngle;
public:
    RotateCameraY(Lense cam);
    ~RotateCameraY();
    float getAngle() const;
    void setAngle(float a);
    void rotate(float a);
};

#endif