#ifndef MODELVIEWINPUTHANDLER_HPP
#define MODELVIEWINPUTHANDLER_HPP

// Include interface
#include "../src/interface/InputHandler.hpp"

class ModelViewInputHandler : public InputHandler
{
private:
    double mousePosX, mousePosY;
    double mouseOldX, mouseOldY;

    double mouseDeltaX, mouseDeltaY;

    float shiftModifier, ctrlModifier, zoomModifier, panModifier, modifier;

    const float defaultModifier = 0.5f, defaultZoomModifier = 50, flipAngle = 5;

    void getMouse();
    void getModifier();
    void getModifierForZoom();
public:
    ModelViewInputHandler();
    ~ModelViewInputHandler();
    void handleKeyDown();
    void handleKeyPressed();
    void handleKeyReleased();
    void handleRotate(Rotatable* rx, Rotatable* ry, Rotatable* rz);
    void handleTranslate(Translatable* t);
    void handleZoom(Translatable* t, double xoffset, double yoffset);
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

#endif