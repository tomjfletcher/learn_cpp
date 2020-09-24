#ifndef NODE_HPP
#define NODE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../src/scene/Drawable.hpp"

using namespace glm;

class Node : public Drawable
{
private:
    GLuint programID;
    GLuint matrixID;
    GLenum drawType;
    GLchar name;
    GLsizei vertexCount;
    GLuint vertexArrayID;
protected:
    static GLuint vertexArrayIDCounter;
    GLuint vertexBuffer;
    GLuint normalBuffer;
    Node(const GLchar * name);
    Node(const GLchar * name, GLenum drawType, const char * fs, const char * vs);
    void drawBuffer(GLuint &buffer, int noPtsPrVtx, int buffrNo);
    void createBuffer(GLfloat data[], GLuint &buffer);
    void disableBuffer(int noBuffers);
    virtual void deleteNode(){};
    virtual void createBuffers(){};
    virtual void drawNode(){};
    virtual void disableBuffers(){};
public: 
    ~Node();
    void draw();
    GLuint getProgramID() const;
};


#endif