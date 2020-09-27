#ifndef TRANSLATABLE_HPP
#define TRANSLATABLE_HPP

// An interface for translating
class Translatable
{
public:
    virtual void setX(float x){};
    virtual void setY(float y){};
    virtual void setZ(float z){};
    virtual void setXY(float x, float y){};
    virtual void setXYZ(float x, float y, float z){};
    virtual void translateX(float x){};
    virtual void translateY(float y){};
    virtual void translateZ(float z){};
    virtual void translateXY(float x, float y){};
    virtual void translateXYZ(float x, float y, float z){};
};

#endif