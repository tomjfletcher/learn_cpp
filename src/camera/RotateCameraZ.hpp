#ifndef ROTATECAMERAZ_HPP
#define ROTATECAMERAZ_HPP

// Include interface
#include "../src/interface/Rotatable.hpp"

// Include Lense to action
#include "Lense.hpp"

// Actions rotations in the Y axis on the lense
class RotateCameraZ : public Rotatable
{
private:
    Lense* cam;
    float currentAngle;
public:
    RotateCameraZ(Lense* cam);
    ~RotateCameraZ();
    float getAngle() const;
    void setAngle(float a);
    void rotate(float a);
};

#endif