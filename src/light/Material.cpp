#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Material.hpp"

Material::Material(float r, float g, float b, float a) : rgba{r,g,b,a} {
}

Material::~Material(){}

void Material::draw(){

		// describes the reaction to each light
		glMaterialfv(GL_FRONT, GL_AMBIENT, rgba);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, rgba);
		glMaterialfv(GL_FRONT, GL_SPECULAR, rgba);
		glMaterialf(GL_FRONT, GL_SHININESS, 50);
}