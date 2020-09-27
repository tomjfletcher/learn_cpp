// Include header
#include "Camera.hpp"

Camera::Camera(float distance):
cam(*(new Lense(0, distance, 0, 0, 0, 0, 45, 1, 2000))),
t(*(new TranslateCamera(this->cam))),
rx(*(new RotateCameraX(this->cam))),
ry(*(new RotateCameraY(this->cam))),
rz(*(new RotateCameraZ(this->cam))) {

}

Camera::~Camera(){

}

void Camera::init(){
    rx.setAngle(-45);
	ry.setAngle(0);
	rz.setAngle(135);
	t.setXYZ(0, 0, 0);
}

void Camera::draw(){
    cam.draw();
}

void Camera::setPerspective(){
    cam.setPerspective();
}

void Camera::setTransforms(){
    cam.setTransformations();
}