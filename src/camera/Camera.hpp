#ifndef CAMERA_HPP
#define CAMERA_HPP

// Include interface
#include "../src/interface/Drawable.hpp"

// Include camera components
#include "Lense.hpp"
#include "RotateCameraX.hpp"
#include "RotateCameraY.hpp"
#include "RotateCameraZ.hpp"
#include "TranslateCamera.hpp"

// Include window
#include <GLFW/glfw3.h>

class Camera : public Drawable
{
private:
    GLFWwindow* window;
    Lense cam;
    double mousePosX, mousePosY;
    double mouseOldX, mouseOldY;
    double mouseDeltaX, mouseDeltaY;
    float shiftModifier, ctrlModifier, zoomModifier, panModifier, modifier;
    const float defaultModifier = 0.5f, defaultZoomModifier = 50, flipAngle = 5;
    void init();
    void getMouse();
    void getModifier();
    void getModifierForZoom();
public:
    RotateCameraX rx;
    RotateCameraY ry;
    RotateCameraZ rz;
    TranslateCamera t;
    Camera(GLFWwindow* window, float distance, GLFWscrollfun scroll_callback, GLFWcursorposfun callback);
    ~Camera();
    void draw();
    void setPerspective();
    void setTransforms();
    void handleRotate();
    void handleTranslate();
    void handleZoom(double xoffset, double yoffset);
    void mouseMove();
    float getShiftModifier()const;
    void setShiftModifier(float mod);
    float getCtrlModifier()const;
    void setCtrlModifier(float mod);
    float getZoomModifier()const;
    void setZoomModifier(float mod);
    float getPanModifier()const;
    void setPanModifier(float mod);
};

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

#endif