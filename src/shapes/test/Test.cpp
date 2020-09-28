#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Test.hpp"
#include "../src/shaders/Shader.hpp"

using namespace glm;

GLuint programID;

Test::Test(){
    programID = LoadShaders( "src/shaders/simple.vs", "src/shaders/simple.fs" );
}
Test::~Test(){

}
void Test::draw(){

    glUseProgram(programID);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(0,0,0);
    glVertex3f(10,0,0);
    glVertex3f(0,10,0);

    glVertex3f(0,0,0);
    glVertex3f(0,10,0);
    glVertex3f(10,0,0);

    glEnd();

}
