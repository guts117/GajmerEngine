#include "render_pch.h"
#include "SpotLight.h"
#include "World_Fbo_Handler_Manager.h"

using namespace GajmerEngine::Presenter;

SpotLight::SpotLight() : PointLight() {
	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	edge = 0.0f;
	procEdge = cosf(glm::radians(edge));
	isOn = true;
}

SpotLight::SpotLight(GLuint shadowWidth, GLuint shadowHeight,
					GLfloat near, GLfloat far, 
					GLfloat red, GLfloat green, GLfloat blue,
				    GLfloat xPos, GLfloat yPos, GLfloat zPos, 
					GLfloat xDir, GLfloat yDir, GLfloat zDir, 
					GLfloat edg, World_Fbo_Handler_Manager* worldFboHndlrMgr)
				    : PointLight(shadowWidth, shadowHeight, near, far, red, green, blue, xPos, yPos, zPos, worldFboHndlrMgr){

	direction = glm::normalize(glm::vec3(xDir, yDir, zDir));
	edge = edg;
	procEdge = cosf(glm::radians(edge));
	isOn = true;
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir)
{
	position = pos;
	direction = dir;
}

SpotLight::~SpotLight() {
}






