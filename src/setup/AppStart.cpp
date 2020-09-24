// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>

// Include main window
#include "MainWindow.hpp"

int main( void )
{

	//initialise the main window
	init();

	//setup the OpenGL environment
	setupGLEnvironment();

	//enter the drawing loop
	drawGL();

	//end the main window
	end();

	return 0;
}

