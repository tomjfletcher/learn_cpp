// Include header
#include "TranslateCamera.hpp"

#include "../src/interface/Translatable.hpp"

TranslateCamera::TranslateCamera(Lense cam):cam(cam){
    setZoom(cam.getY());
}

TranslateCamera::~TranslateCamera(){

}

void TranslateCamera::setZoom(float zoom){
    if (zoom > -1) {
		zoom = -1.0f;
	}

	this->zoom = zoom;
	cam.setY(zoom);
}

float TranslateCamera::getZoom() const{
    return zoom;
}

void TranslateCamera::zoomBy(float d){
    setZoom(getZoom() + d);
}

float TranslateCamera::getPivotX() const{
    return cam.getPivotX();
}

float TranslateCamera::getPivotY() const{
    return cam.getPivotY();
}

float TranslateCamera::getPivotZ() const{
    return cam.getPivotZ();
}

void TranslateCamera::setPivot(float x, float y, float z){
    cam.setPivotX(x);
	cam.setPivotY(y);
	cam.setPivotZ(z);
	setXYZ(0, 0, 0);
	setZoom(getZoom());
}

void TranslateCamera::setXY(float x, float y){
    setX(x);
    setY(y);
}

void TranslateCamera::setXYZ(float x, float y, float z){
    setX(x);
    setY(y);
    setZ(z);
}

void TranslateCamera::translateXY(float x, float y){
    translateX(x);
    translateY(y);
}

void TranslateCamera::translateXYZ(float x, float y, float z){
    translateX(x);
    translateY(y);
    translateZ(z);
}

void TranslateCamera::setX(float x){
    translateX(x - cam.getTranslateX());
}

void TranslateCamera::setY(float y){
    translateY(y - cam.getTranslateX());
}

void TranslateCamera::setZ(float z){
    translateZ(z - cam.getTranslateX());
}

void TranslateCamera::translateX(float x){
    cam.setTranslateX(cam.getTranslateX() + x);
}

void TranslateCamera::translateY(float y){
    cam.setTranslateY(cam.getTranslateY() + y);
}

void TranslateCamera::translateZ(float z){
    cam.setTranslateZ(cam.getTranslateZ() + z);
}