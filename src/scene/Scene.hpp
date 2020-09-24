#ifndef SCENE_HPP
#define SCENE_HPP

//include glm
#include <glm/glm.hpp>

#include <vector>

#include "../src/shapes/Node.hpp"

class Scene{
private:
    float clearColour [4];
    std::vector<Node*> nodes;
    glm::mat4 modelViewProjMatrix;
public:
    Scene();
    ~Scene();
    void draw();
    void addNode(Node * n);
    std::vector<Node*> getNodes();
    glm::mat4 getMVPMatrix() const;
};



#endif