#ifndef CUBETEST_HPP
#define CUBETEST_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../src/shapes/Node.hpp"

using namespace glm;

class CubeTest : public Node{
private:
    GLfloat data[];
public:
    CubeTest();
    void deleteNode();
    void drawNode();
    void createBuffers();
    void disableBuffers();
};


#endif