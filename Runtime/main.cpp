#include "pch.h"
#include "RenderEngineMain.h"
#include "PhysicsEngineMain.h"
#include "EngineEditorMain.h"

//using namespace GajmerEngine::Runtime;
using namespace GajmerEngine::Creator;
using namespace GajmerEngine::Presenter;
using namespace GajmerEngine::Physics;


int main()
{
	auto physicsEngine = PhysicsEngineMain();
	auto creator = EngineEditorMain();
	glm::ivec2 screenDims = glm::ivec2(creator.GetScreenDimensions());
	auto renderEngine = RenderEngineMain(screenDims);
	creator.AddWorldViewers(&renderEngine);

	do 
	{
		screenDims = glm::ivec2(creator.GetScreenDimensions());
		physicsEngine.Update(0.016f);
		renderEngine.Update(screenDims, creator.IsUpdateBufferSize());
		creator.Update(screenDims);
		renderEngine.EndUpdate();
		creator.EndUpdate();
	} while (!creator.IsEnd());

	return 0;
}






