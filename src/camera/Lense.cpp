// Standard headers
#include <stdio.h>
#include <stdlib.h>

// OpenGL headers
#include <GL/glew.h>
#include <glm/glm.hpp>

// External class headers

// Class header
#include "Lense.hpp"

using namespace glm;

Lense::Lense(float posX, float posY, float posZ, 
    float focalX, float focalY, float focalZ, 
    float fov, float nearClip, float farClip) : 
    x(posX), 
    y(posY), 
    z(posZ), 
    focalX(focalX), 
    focalY(focalY), 
    focalZ(focalZ), 
    fov(fov), 
    nearClip(nearClip), 
    farClip(farClip)
    {

}

Lense::~Lense(){

}

void Lense::draw(){

    // Change to and load projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    setPerspective();

    // Return to the model drawing matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Lense::setPerspective(){

    // Set the perspective of the view
    gluPerspective(getFOV(), 1024/768, getNearClip(), getFarClip());

    // Define the point that is being looked at
    gluLookAt(getX(), getY(), getZ(), getFocalX(), getFocalY(), getFocalZ(), 0, 0, -1);

    // Perform the projection transformations
    setTransformations();

}

void Lense::setTransformations(){

    // Translate the lense from the pivot
    glTranslatef(getTranslateX(), getTranslateY(), getTranslateZ());

    // Rotate around the pivot point
    glRotatef(getRotateX(), 1, 0, 0);
    glRotatef(getRotateY(), 0, 1, 0);
    glRotatef(getRotateZ(), 0, 0, 1);

    // Move the focal point
    glTranslatef(getPivotX(), getPivotY(), getPivotZ());

}

float Lense::getFOV() const{
    return this->fov;
}

float Lense::getNearClip() const{
    return this->nearClip;
}

float Lense::getFarClip() const{
    return this->farClip;
}

float Lense::getX() const{
    return this->x;
}

float Lense::getY() const{
    return this->y;
}

float Lense::getZ() const{
    return this->z;
}

float Lense::getFocalX() const{
    return this->focalX;
}

float Lense::getFocalY() const{
    return this->focalY;
}

float Lense::getFocalZ() const{
    return this->focalZ;
}

float Lense::getRotateX() const{
    return this->rotateX;
}

float Lense::getRotateY() const{
    return this->rotateY;
}

float Lense::getRotateZ() const{
    return this->rotateZ;
}

float Lense::getTranslateX() const{
    return this->translateX;
}

float Lense::getTranslateY() const{
    return this->translateY;
}

float Lense::getTranslateZ() const{
    return this->translateZ;
}

float Lense::getPivotX() const{
    return this->pivotX;
}

float Lense::getPivotY() const{
    return this->pivotY;
}

float Lense::getPivotZ() const{
    return this->pivotZ;
}