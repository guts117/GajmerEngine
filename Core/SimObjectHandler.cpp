#include "pch.h"
#include "SimObjectHandler.h"

using namespace GE::Core;

SimObjectHandler::SimObjectHandler(std::shared_ptr<SimObject> simObj)
	: m_simObject {simObj}
{
}
