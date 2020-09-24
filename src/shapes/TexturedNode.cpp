// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../src/textures/texture.hpp"

#include "Node.hpp"
#include "TexturedNode.hpp"

using namespace glm;

TexturedNode::TexturedNode(const GLchar * name, const char * texturePath) : 
Node(name, GL_TRIANGLES, "src/shaders/texture.fs", "src/shaders/transform.vs"), 
texture(loadDDS(texturePath)), 
textureID(glGetUniformLocation(getProgramID(), name)) {

}

void TexturedNode::drawNode(){

    // Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(textureID, 0);

    drawTexture();
}

void TexturedNode::deleteNode(){
    glDeleteTextures(1, &textureID);
    deleteTexturedNode();
}