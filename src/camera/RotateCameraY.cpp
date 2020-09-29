// Include header
#include "RotateCameraY.hpp"

RotateCameraY::RotateCameraY(Lense* cam) : cam(cam){
    this->currentAngle = 0;

}

RotateCameraY::~RotateCameraY(){

}

void RotateCameraY::setAngle(float a){
    this->currentAngle = a;
    (*cam).setRotateY(a);
}

void RotateCameraY::rotate(float a){
    float newAngle = (getAngle() + a);
	setAngle(newAngle);
}

float RotateCameraY::getAngle() const{
    return this->currentAngle;
}