#ifndef SCENE_HPP
#define SCENE_HPP

#include <GLFW/glfw3.h>
#include <vector>
#include "../src/interface/Drawable.hpp"

class Scene : public Drawable
{
private:
    std::vector<Drawable*> items;
public:
    Scene(GLFWwindow* window);
    ~Scene();
    void draw();
    void addItem(Drawable* item);
};

#endif