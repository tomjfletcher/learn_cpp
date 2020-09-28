#ifndef LENSE_HPP
#define LENSE_HPP

// Implement interface 
#include "../src/interface/Drawable.hpp"

class Lense : public Drawable
{
private:
    float fov;
    float nearClip, farClip;
    float x, y, z;
    float focalX, focalY, focalZ;
    float rotateX, rotateY, rotateZ;
    float translateX, translateY, translateZ;
    float pivotX, pivotY, pivotZ;
public:
    Lense();
    Lense(float posX, float posY, float posZ, 
    float focalX, float focalY, float focalZ, 
    float fov, float nearClip, float farClip);
    ~Lense();
    void draw();
    void setPerspective();
    void setTransformations();
    float getFOV() const;
    void setFOV(float fov);
    float getNearClip() const;
    void setNearClip(float nearClip);
    float getFarClip() const;
    void setFarClip(float farClip);
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getZ() const;
    void setZ(float z);
    float getFocalX() const;
    void setFocalX(float focalX);
    float getFocalY() const;
    void setFocalY(float focalY);
    float getFocalZ() const;
    void setFocalZ(float focalZ);
    float getRotateX() const;
    void setRotateX(float rotateX);
    float getRotateY() const;
    void setRotateY(float rotateY);
    float getRotateZ() const;
    void setRotateZ(float rotateZ);
    float getTranslateX() const;
    void setTranslateX(float translateX);
    float getTranslateY() const;
    void setTranslateY(float translateY);
    float getTranslateZ() const;
    void setTranslateZ(float translateZ);
    float getPivotX() const;
    void setPivotX(float pivotX);
    float getPivotY() const;
    void setPivotY(float pivotY);
    float getPivotZ() const;
    void setPivotZ(float pivotZ);
};

#endif