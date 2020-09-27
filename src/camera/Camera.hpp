#ifndef CAMERA_HPP
#define CAMERA_HPP

// Include interface
#include "../src/interface/Drawable.hpp"

// Include camera components
#include "Lense.hpp"
#include "RotateCameraX.hpp"
#include "RotateCameraY.hpp"
#include "RotateCameraZ.hpp"
#include "TranslateCamera.hpp"

class Camera : public Drawable
{
private:
    Lense cam;
    void init();
public:
    RotateCameraX rx;
    RotateCameraY ry;
    RotateCameraZ rz;
    TranslateCamera t;
    Camera(float distance);
    ~Camera();
    void draw();
    void setPerspective();
    void setTransforms();
};

#endif