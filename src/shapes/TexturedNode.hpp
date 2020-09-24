#ifndef TEXTUREDNODE_HPP
#define TEXTUREDNODE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../src/shapes/Node.hpp"

class TexturedNode : public Node
{
private:
    GLuint textureID;
    GLuint texture;
    void drawNode();
    void deleteNode();
protected:
    GLuint textureBuffer;
    TexturedNode(const GLchar * name, const char * texturePath);
    virtual void deleteTexturedNode(){};
    virtual void createBuffers(){};
    virtual void disableBuffers(){};
    virtual void drawTexture(){};
public:
};

#endif