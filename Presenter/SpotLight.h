#ifndef SPOTLIGHT
#define SPOTLIGHT

#include "PointLight.h"

namespace GajmerEngine::Presenter
{
	class SpotLight :
		public PointLight
	{
	public:
		SpotLight();

		SpotLight(GLuint shadowWidth, GLuint shadowHeight,
			GLfloat near, GLfloat far,
			GLfloat red, GLfloat green, GLfloat blue,
			GLfloat xPos, GLfloat yPos, GLfloat zPos,
			GLfloat xDir, GLfloat yDir, GLfloat zDir,
			GLfloat edg, World_Fbo_Handler_Manager* worldFboHndlrMgr);

		void SetFlash(glm::vec3 pos, glm::vec3 dir);

		void Toggle() { isOn = !isOn; }

		~SpotLight();

		glm::vec3 direction;
		GLfloat procEdge;
	private:

		GLfloat edge;

		bool isOn;

	};
}
#endif






