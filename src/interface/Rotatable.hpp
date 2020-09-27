#ifndef ROTATABLE_HPP
#define ROTATABLE_HPP

// An interface for rotating
class Rotatable
{
public:
    virtual float getAngle()const{return 0;};
    virtual void setAngle(float a){};
    virtual void rotate(float a){};
};

#endif