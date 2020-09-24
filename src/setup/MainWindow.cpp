// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "MainWindow.hpp"
#include "../src/shaders/shader.hpp"

using namespace glm;


int init(){
    // Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	MainWindow::window = glfwCreateWindow( 1024, 768, "Sandbox", NULL, NULL);
	if( MainWindow::window == NULL ){
		fprintf( stderr, "Failed to open GLFW window.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(MainWindow::window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(MainWindow::window, GLFW_STICKY_KEYS, GL_TRUE);

	// Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(MainWindow::window, 1024/2, 768/2);

	return 0;
}

int setupGLEnvironment(){

    // Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	MainWindow::scene = new Scene();

	return 0;
}

int drawGL(){


    do{
		// Draw
		MainWindow::draw();
		
		// Swap buffers
		glfwSwapBuffers(MainWindow::getWindow());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(MainWindow::window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(MainWindow::window) == 0 );

	return 0;
}

int end(){

	// Destroy scene
	delete(MainWindow::scene);

    // Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

GLFWwindow* MainWindow::getWindow(){
	return window;
}

void MainWindow::addNode(Node * n){
	(*scene).addNode(n);
}

void MainWindow::draw(){
	(*scene).draw();
}

mat4 MainWindow::getMVPMatrix(){
	return (*scene).getMVPMatrix();
}