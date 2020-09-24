// Include standard headers
#include <stdio.h>
#include <stdlib.h>

//include glew
#include <GL/glew.h>

//include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//include core
#include <vector>

//include header
#include "../src/scene/Scene.hpp"
#include "../src/camera/controls.hpp"
#include "../src/shapes/TexturedNode.hpp"
#include "../src/shapes/test/TexCubeTest.hpp"

using namespace glm;

Scene::Scene() : clearColour{0.0f,0.0f,1.0f,0.0f}, nodes {}{

    // Projection matrix : 45∞ Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	mat4 Projection = perspective(radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	mat4 View       = lookAt(
								vec3(4,3,3), // Camera is at (4,3,3), in World Space
								vec3(0,0,0), // and looks at the origin
								vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
						   );
	// Model matrix : an identity matrix (model will be at the origin)
	mat4 Model      = mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	modelViewProjMatrix = Projection * View * Model; // Remember, matrix multiplication is the other way around

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