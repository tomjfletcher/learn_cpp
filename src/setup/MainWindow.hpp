#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "../src/scene/Scene.hpp"

namespace MainWindow{
    static Scene* scene;
    void addNode(Node * n);
    void draw();
    glm::mat4 getMVPMatrix();
}
//For initialisation of a window
int init();
//For setup of the opengl environment
int setupGLEnvironment();
//For the drawing of the window
int drawGL();
//For disposal
int end();

#endif