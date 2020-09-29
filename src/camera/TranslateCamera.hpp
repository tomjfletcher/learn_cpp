#ifndef TRANSLATECAMERA_HPP
#define TRANSLATECAMERA_HPP

// Include lense to action
#include "Lense.hpp"

// Include interface
#include "../src/interface/Translatable.hpp"

class TranslateCamera
{
private:
    Lense* cam;
    float zoom;
public:
    TranslateCamera(Lense* cam);
    ~TranslateCamera();
    void setZoom(float zoom);
    float getZoom()const;
    void zoomBy(float d);
    void setPivot(float x, float y, float z);
    void translatePivotZ(float d);
    float getPivotX()const;
    float getPivotY()const;
    float getPivotZ()const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setXY(float x, float y);
    void setXYZ(float x, float y, float z);
    void translateX(float x);
    void translateY(float y);
    void translateZ(float z);
    void translateXY(float x, float y);
    void translateXYZ(float x, float y, float z);
};

#endif