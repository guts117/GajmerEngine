#ifndef VISIBLE_NODE_HANDLER
#define VISIBLE_NODE_HANDLER

#include "pch.h"

namespace GajmerEngine::Runtime
{
	struct VisibleNode;
	class VisibleNodeHandler
	{
	public:
		explicit VisibleNodeHandler(std::shared_ptr<VisibleNode> simObj);

		//virtual void OnCreation();
		//virtual void OnFixedUpdate(); //This will run independent of the other function. the timing can be changed per function probably. Unity uses the physics deltatime.
		//virtual void OnPreUpdate();
		//virtual void OnUpdate();
		//virtual void OnPostUpdate();
		//virtual void OnDestruction();

		virtual ~VisibleNodeHandler() = 0;
	private:
		std::weak_ptr<VisibleNode> m_simObject;
	};
}

#endif //VISIBLE_NODE_HANDLER








