#ifndef SIM_OBJECT
#define SIM_OBJECT

#include "pch.h"

namespace GE::Physics
{
	class PhysicsMain;
}
namespace GE::Graphics
{
	class Render_Object;
}

namespace GE::Core
{
	struct Pose;
	struct VisibleNode
	{
		std::string name = "";
		unsigned long uniqueSimId = 0;													//Use this for object identification and sorting; 
		Pose* transform = nullptr;													//ptr to pool
		Graphics::Render_Object* renderObject = nullptr;						//ptr to pool
		std::weak_ptr<VisibleNode> parentNode = std::weak_ptr<VisibleNode>();				//ptr to parent node
	};
}

#endif