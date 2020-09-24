// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../src/shaders/shader.hpp"
#include "../src/setup/MainWindow.hpp"

#include "Node.hpp"

using namespace glm;

GLuint Node::vertexArrayIDCounter(0);

Node::Node(const GLchar * name){
    Node(name, GL_TRIANGLES, "/Users/tom/projects/sandbox/src/shaders/standard.fs", "/Users/tom/projects/sandbox/src/shaders/standard.vs");
}

Node::Node(const GLchar * name, GLenum drawType, const char * fs, const char * vs) : name(*name), drawType(drawType), programID(LoadShaders( vs, fs )), matrixID(glGetUniformLocation(programID, name)), vertexArrayID(vertexArrayIDCounter) {
    this->vertexArrayIDCounter++;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
    createBuffers();
}

Node::~Node(){
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &vertexArrayID);
    deleteNode();
}

void Node::draw(){

    glPushMatrix();

    // Use shader
	glUseProgram(programID);

    // Assign matrix to shader
    auto matrix = MainWindow::getMVPMatrix();
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);

    drawNode();
    
    // Draw the triangle !
	glDrawArrays(drawType, 0, vertexCount); // 12*3 indices starting at 0 -> 12 triangles

	disableBuffers();

    glPopMatrix();

}

void Node::drawBuffer(GLuint &buffer, int noPtsPrVtx, int buffrNo){
	glEnableVertexAttribArray(buffrNo);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(0,noPtsPrVtx,GL_FLOAT,GL_FALSE,0,(void*)0);
}

void Node::createBuffer(GLfloat data[], GLuint &buffer){
    vertexCount = sizeof(*data);
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(*data), data, GL_STATIC_DRAW);
}

void Node::disableBuffers(int noBuffers){
    for(int i = 0; i < noBuffers; i++){
        glDisableVertexAttribArray(i);
    }

}

GLuint Node::getProgramID() const{
    return this->programID;
}