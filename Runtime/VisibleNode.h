#ifndef VISIBLE_NODE
#define VISIBLE_NODE

#include "pch.h"

namespace GajmerEngine::Physics
{
	class PhysicsEngine;
}
namespace GajmerEngine::Presenter
{
	class Render_Object;
}

namespace GajmerEngine::Runtime
{
	struct Transform;
	struct VisibleNode
	{
		std::string name = "";
		unsigned long uniqueSimId = 0;													//Use this for object identification and sorting; 
		Transform* transform = nullptr;													//ptr to pool
		GajmerEngine::Presenter::Render_Object* renderObject = nullptr;						//ptr to pool
		std::weak_ptr<VisibleNode> parentNode = std::weak_ptr<VisibleNode>();				//ptr to parent node
	};
}

#endif







