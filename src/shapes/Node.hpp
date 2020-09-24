#ifndef NODE_HPP
#define NODE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

class Node
{
private:
    GLuint programID;
    GLuint MatrixID;
    GLenum drawType;
    GLchar name;
    GLsizei vertexCount;
    GLuint vertexArrayID;
protected:
    static GLuint vertexArrayIDCounter;
    GLuint vertexBuffer;
    GLuint normalBuffer;
    Node(GLchar name);
    Node(GLchar name, GLenum drawType, const char * fs, const char * vs);
    void drawBuffer(GLuint &buffer);
    void createBuffer(GLfloat data[], GLuint &buffer);
    void disableBuffers(int noBuffers);
    virtual void deleteNode(){};
    virtual void createBuffers(){};
    virtual void drawNode(){};
    virtual void disableBuffers(){};
public: 
    ~Node();
    void draw();
};


#endif