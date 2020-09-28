// Include header
#include "ModelViewInputHandler.hpp"

#include "../src/AppStart.hpp"

ModelViewInputHandler::ModelViewInputHandler() :
mousePosX(1024/2), mousePosY(768/2),
mouseOldX(0), mouseOldY(0),
mouseDeltaX(0), mouseDeltaY(0),
shiftModifier(5), ctrlModifier(0.1), zoomModifier(1), panModifier(1), modifier(0){
    glfwSetCursorPos(window, mousePosX, mousePosY);
    glfwSetScrollCallback(window, scroll_callback);
}

ModelViewInputHandler::~ModelViewInputHandler(){

}

void ModelViewInputHandler::handleKeyDown(){

}

void ModelViewInputHandler::handleKeyPressed(){

}

void ModelViewInputHandler::handleKeyReleased(){

}

void ModelViewInputHandler::handleRotate(Rotatable* rx, Rotatable* ry, Rotatable* rz){
			getMouse();
			getModifier();
			float prev = rx.getAngle();
			rz.rotate(mouseDeltaX * modifier);// rotates by the modified mouse movement amount in the z
			rx.rotate(mouseDeltaY * modifier);// rotates by the modified mouse movement amount in the x
			if ((prev < flipAngle && rx.getAngle() >= flipAngle)
					|| (prev >= flipAngle && rx.getAngle() < flipAngle)) {
				//return true;
			}
            //return false;
}

void ModelViewInputHandler::getMouse(){
    // remembers old
	mouseOldX = mousePosX;
	mouseOldY = mousePosY;

	// gets new
	glfwGetCursorPos(window, &mousePosX, &mousePosY);

	// works out difference
	mouseDeltaX = -(mousePosX - mouseOldX);
	mouseDeltaY = -(mousePosY - mouseOldY);
}

void ModelViewInputHandler::getModifier(){
    float ret = defaultModifier;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)==GLFW_PRESS) {
		ret = getCtrlModifier();
	} else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS) {
		ret = getShiftModifier();
	}
	modifier = ret;
}

void ModelViewInputHandler::getModifierForZoom(){
    modifier *= zoomModifier;// modifies the modifier to zoom
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)==GLFW_PRESS) {
		modifier *= defaultZoomModifier * 0.5;
	} else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS) {
		modifier *= defaultZoomModifier * 0.8;
	} else {
		modifier *= defaultZoomModifier;
	}   
}

void ModelViewInputHandler::handleTranslate(Translatable* t){
    getMouse();
	getModifier();
	modifier = modifier * panModifier;
	t.translateXY(mouseDeltaX * modifier, -mouseDeltaY * modifier);// translates by a relative amount
}

void ModelViewInputHandler::handleZoom(Translatable* t, double xoffset, double yoffset){
    getModifier();
	getZoomModifier();
	t.zoomBy((float) (yoffset * modifier * -1));
}

void ModelViewInputHandler::mouseMove(){
	getMouse();
}

float ModelViewInputHandler::getCtrlModifier()const{
    return this->ctrlModifier;
}

void ModelViewInputHandler::setCtrlModifier(float mod){
    this->ctrlModifier = mod;
}

float ModelViewInputHandler::getPanModifier()const{
    return this->panModifier;
}

void ModelViewInputHandler::setPanModifier(float mod){
    this->panModifier = mod;
}

float ModelViewInputHandler::getShiftModifier()const{
    return this->shiftModifier;
}

void ModelViewInputHandler::setShiftModifier(float mod){
    this->shiftModifier = mod;
}

float ModelViewInputHandler::getZoomModifier()const{
    return this->zoomModifier;
}

void ModelViewInputHandler::setZoomModifier(float mod){
    this->zoomModifier = mod;
}