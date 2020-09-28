#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "Rotatable.hpp"
#include "Translatable.hpp"

class InputHandler
{
public:
    virtual void handleKeyDown(){};
    virtual void handleKeyPressed(){};
    virtual void handleKeyReleased(){};

    virtual void handleRotate(Rotatable* rx, Rotatable* ry, Rotatable* rz){};
    virtual void handleTranslate(Translatable* t){};
    virtual void handleZoom(Translatable* t, double xoffset, double yoffset){};
    virtual void mouseMove(){};

    virtual float getShiftModifier()const;
    virtual void setShiftModifier(float mod){};
    virtual float getCtrlModifier()const;
    virtual void setCtrlModifier(float mod){};
    virtual float getZoomModifier()const;
    virtual void setZoomModifier(float mod){};
    virtual float getPanModifier()const;
    virtual void setPanModifier(float mod){};
};

#endif