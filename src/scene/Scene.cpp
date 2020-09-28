#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../src/camera/Camera.hpp"
#include "../src/light/Light.hpp"


#include "Scene.hpp"

using namespace glm;

Scene::Scene(GLFWwindow* window):items{new Camera(window, 20, scroll_callback, cursor_position_callback), new Light()} {

}

Scene::~Scene(){

}

void Scene::draw(){

    glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    for(Drawable* d : items){
        d->draw();
    }
}

void Scene::addItem(Drawable* item){
    items.push_back(item);
}