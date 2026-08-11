#include "pch.h"
#include "VisibleNodeHandler.h"

using namespace GE::Core;

VisibleNodeHandler::VisibleNodeHandler(std::shared_ptr<VisibleNode> simObj)
	: m_visibleNode {simObj}
{
}
