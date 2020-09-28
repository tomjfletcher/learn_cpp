// Include header
#include "RotateCameraX.hpp"

RotateCameraX::RotateCameraX(Lense cam) : cam(cam){
    this->currentAngle = 0;
}

RotateCameraX::~RotateCameraX(){

}

void RotateCameraX::setAngle(float a){
    if (a > 90) {
		a = 90;
	} else if (a < -90) {
		a = -90;
	}
    this->currentAngle = a;
    cam.setRotateX(currentAngle);
}

void RotateCameraX::rotate(float a){
    float newAngle = (getAngle() + a);
	setAngle(newAngle);
}

float RotateCameraX::getAngle() const{
    return this->currentAngle;
}