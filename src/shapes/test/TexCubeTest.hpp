#ifndef TEXCUBETEST_HPP
#define TEXCUBETEST_HPP

#include <glm/glm.hpp>
#include "../src/shapes/TexturedNode.hpp"

using namespace glm;

class TexCubeTest : public TexturedNode
{
public:
    TexCubeTest();
    void deleteTexturedNode();
    void createBuffers();
    void disableBuffers();
    void drawTexture();
};

#endif