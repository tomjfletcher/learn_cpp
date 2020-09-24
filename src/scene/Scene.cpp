// Include standard headers
#include <stdio.h>
#include <stdlib.h>

//include glew
#include <GL/glew.h>

//include glm
#include <glm/glm.hpp>

//include core
#include <vector>

//include header
#include "../src/scene/Scene.hpp"
#include "../src/camera/controls.hpp"
#include "../src/shapes/TexturedNode.hpp"
#include "../src/shapes/test/TexCubeTest.hpp"

using namespace glm;

Scene::Scene() : clearColour{0.0f,0.0f,0.0f,0.0f}, nodes {}{

    modelViewProjMatrix = mat4();

	Node * test = new TexCubeTest();

	addNode(test);
}

Scene::~Scene(){
    for(Node * n: getNodes()){
        delete(n);
    }
}

void Scene::draw(){
    // Background
	glClearColor(clearColour[0], clearColour[1], clearColour[2], clearColour[3]);

    // Clear the screen.
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Get inputs
    computeMatricesFromInputs();
    mat4 ProjectionMatrix = getProjectionMatrix();
	mat4 ViewMatrix = getViewMatrix();
	mat4 ModelMatrix = mat4(1.0);
	mat4 tempModelViewProjMatrix = ProjectionMatrix * ViewMatrix * ModelMatrix;
    modelViewProjMatrix = tempModelViewProjMatrix;

    // Draw Nodes
    for(Node * n: getNodes()){
        (*n).draw();
    }
}

void Scene::addNode(Node * n){
    nodes.push_back(n);
}

std::vector<Node *> Scene::getNodes(){
    return nodes;
}

mat4 Scene::getMVPMatrix() const{
    return modelViewProjMatrix;
}