#ifndef SIM_OBJECT
#define SIM_OBJECT

#include "pch.h"

namespace Physics
{
	class PhysicsMain;
}
namespace Graphics
{
	class Render_Object;
}

namespace Core
{
	struct Pose;
	struct SimObject
	{
		std::string name = "";
		unsigned long uniqueSimId = 0;													//Use this for object identification and sorting; 
		Pose* transform = nullptr;													//ptr to pool
		Graphics::Render_Object* renderObject = nullptr;						//ptr to pool
		std::weak_ptr<SimObject> parentNode = std::weak_ptr<SimObject>();				//ptr to parent node
	};
}

#endif