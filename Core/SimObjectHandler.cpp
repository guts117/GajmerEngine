#include "pch.h"
#include "SimObjectHandler.h"

using namespace Core;

SimObjectHandler::SimObjectHandler(std::shared_ptr<SimObject> simObj)
	: m_simObject {simObj}
{
}
