// Include GL
#include <GL/glew.h>
#include <glm/glm.hpp>

// Include Header
#include "Light.hpp"

using namespace glm;

Light::Light():aPower{0.2f, 0.2f, 0.2f, 1}, dPower{0.4f, 0.4f, 0.4f, 1}, sPower{0.8f, 0.8f, 0.8f, 1}, pos{100, 100, -100}{}
Light::~Light(){}

void Light::draw(){
    glLightfv(GL_LIGHT0, GL_AMBIENT, aPower);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dPower);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sPower);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

    glEnable(GL_LIGHT0);
}