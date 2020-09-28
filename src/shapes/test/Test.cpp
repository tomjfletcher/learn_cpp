#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Test.hpp"

using namespace glm;

Test::Test(){

}
Test::~Test(){

}
void Test::draw(){

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0,1,0);

}
