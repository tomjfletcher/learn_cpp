// Include header
#include "Camera.hpp"

Camera* scrollCallCam;

void Camera::init(){
    rx.setAngle(-45);
	ry.setAngle(0);
	rz.setAngle(135);
	t.setXYZ(0, 0, 0);
}

Camera::Camera(GLFWwindow* window, float distance, GLFWscrollfun scroll_callback, GLFWcursorposfun callback):
window(window),
cam(*(new Lense(0, distance, 0, 0, 0, 0, 45, 1, 2000))),
t(*(new TranslateCamera(this->cam))),
rx(*(new RotateCameraX(this->cam))),
ry(*(new RotateCameraY(this->cam))),
rz(*(new RotateCameraZ(this->cam))),
mousePosX(1024/2), mousePosY(768/2),
mouseOldX(0), mouseOldY(0),
mouseDeltaX(0), mouseDeltaY(0),
shiftModifier(5), ctrlModifier(0.1), zoomModifier(1), panModifier(1), modifier(0){
    scrollCallCam = this;
    glfwSetCursorPos(window, mousePosX, mousePosY);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetCursorPosCallback(window, callback);
}

Camera::~Camera(){

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

void Camera::handleRotate(){
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

void Camera::getMouse(){
    // remembers old
	mouseOldX = mousePosX;
	mouseOldY = mousePosY;

	// gets new
	glfwGetCursorPos(window, &mousePosX, &mousePosY);

	// works out difference
	mouseDeltaX = -(mousePosX - mouseOldX);
	mouseDeltaY = -(mousePosY - mouseOldY);
}

void Camera::getModifier(){
    float ret = defaultModifier;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)==GLFW_PRESS) {
		ret = getCtrlModifier();
	} else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS) {
		ret = getShiftModifier();
	}
	modifier = ret;
}

void Camera::getModifierForZoom(){
    modifier *= zoomModifier;// modifies the modifier to zoom
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)==GLFW_PRESS) {
		modifier *= defaultZoomModifier * 0.5;
	} else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS) {
		modifier *= defaultZoomModifier * 0.8;
	} else {
		modifier *= defaultZoomModifier;
	}   
}

void Camera::handleTranslate(){
    getMouse();
	getModifier();
	modifier = modifier * panModifier;
	t.translateXY(mouseDeltaX * modifier, -mouseDeltaY * modifier);// translates by a relative amount
}

void Camera::handleZoom(double xoffset, double yoffset){
    getModifier();
	getZoomModifier();
	t.zoomBy((float) (yoffset * modifier * -1));
}

void Camera::mouseMove(){
	getMouse();
}


float Camera::getCtrlModifier()const{
    return this->ctrlModifier;
}

void Camera::setCtrlModifier(float mod){
    this->ctrlModifier = mod;
}

float Camera::getPanModifier()const{
    return this->panModifier;
}

void Camera::setPanModifier(float mod){
    this->panModifier = mod;
}

float Camera::getShiftModifier()const{
    return this->shiftModifier;
}

void Camera::setShiftModifier(float mod){
    this->shiftModifier = mod;
}

float Camera::getZoomModifier()const{
    return this->zoomModifier;
}

void Camera::setZoomModifier(float mod){
    this->zoomModifier = mod;
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    (*scrollCallCam).handleZoom(xoffset, yoffset);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1)==GLFW_PRESS) {
        (*scrollCallCam).handleRotate();
    } else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2)==GLFW_PRESS) {
        (*scrollCallCam).handleTranslate();
    }
}