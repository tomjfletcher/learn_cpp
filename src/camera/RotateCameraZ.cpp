// Include header
#include "RotateCameraZ.hpp"

RotateCameraZ::RotateCameraZ(Lense cam) : cam(cam){
    this->currentAngle = 0;
}

RotateCameraZ::~RotateCameraZ(){

}

void RotateCameraZ::setAngle(float a){
    this->currentAngle = a;
    cam.setRotateZ(a);
}

void RotateCameraZ::rotate(float a){
    float newAngle = (getAngle() + a);
	setAngle(newAngle);
}

float RotateCameraZ::getAngle() const{
    return this->currentAngle;
}