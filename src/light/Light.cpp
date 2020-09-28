// Include GL
#include <GL/glew.h>
#include <glm/glm.hpp>

// Include Header
#include "Light.hpp"

using namespace glm;

void Light::draw(){
    glLightfv(GL_LIGHT0, GL_AMBIENT, aPower);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dPower);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sPower);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

    glEnable(GL_LIGHT0);
}