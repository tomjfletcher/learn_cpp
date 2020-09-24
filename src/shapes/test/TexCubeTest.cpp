#include <stdio.h>
#include <stdlib.h>

#include "TexCubeTest.hpp"
#include "../src/shapes/TexturedNode.hpp"

GLfloat data[] {-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f};
GLfloat tex[] {0.000059f, 0.000004f, 
		0.000103f, 0.336048f, 
		0.335973f, 0.335903f, 
		1.000023f, 0.000013f, 
		0.667979f, 0.335851f, 
		0.999958f, 0.336064f, 
		0.667979f, 0.335851f, 
		0.336024f, 0.671877f, 
		0.667969f, 0.671889f, 
		1.000023f, 0.000013f, 
		0.668104f, 0.000013f, 
		0.667979f, 0.335851f, 
		0.000059f, 0.000004f, 
		0.335973f, 0.335903f, 
		0.336098f, 0.000071f, 
		0.667979f, 0.335851f, 
		0.335973f, 0.335903f, 
		0.336024f, 0.671877f, 
		1.000004f, 0.671847f, 
		0.999958f, 0.336064f, 
		0.667979f, 0.335851f, 
		0.668104f, 0.000013f, 
		0.335973f, 0.335903f, 
		0.667979f, 0.335851f, 
		0.335973f, 0.335903f, 
		0.668104f, 0.000013f, 
		0.336098f, 0.000071f, 
		0.000103f, 0.336048f, 
		0.000004f, 0.671870f, 
		0.336024f, 0.671877f, 
		0.000103f, 0.336048f, 
		0.336024f, 0.671877f, 
		0.335973f, 0.335903f, 
		0.667969f, 0.671889f, 
		1.000004f, 0.671847f, 
		0.667979f, 0.335851f};

TexCubeTest::TexCubeTest() : 
TexturedNode("TexTest", "/Users/tom/projects/sandbox/src/textures/uvtemplate.DDS")
{
    createBuffers();
}

void TexCubeTest::createBuffers(){
    createBuffer(tex, textureBuffer);
    createBuffer(data, vertexBuffer);
}

void TexCubeTest::disableBuffers(){
    disableBuffer(2);
}

void TexCubeTest::deleteTexturedNode(){
    
}

void TexCubeTest::drawTexture(){
    drawBuffer(vertexBuffer, 3, 0);
    drawBuffer(textureBuffer, 2, 0);
}