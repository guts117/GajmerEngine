#include "pch.h"
#include "GraphicsMain.h"
#include "PhysicsMain.h"
#include "EngineEditorMain.h"

//using namespace NarakaKarEngine;
using namespace NarakaCreator;
using namespace Graphics;
using namespace Physics;


int main()
{
	auto physics = PhysicsMain();
	auto creator = EngineEditorMain();
	glm::ivec2 screenDims = glm::ivec2(creator.GetScreenDimensions());
	auto graphicsMain = GraphicsMain(screenDims);
	creator.AddSceneViewers(&graphicsMain);

	do 
	{
		screenDims = glm::ivec2(creator.GetScreenDimensions());
		physics.Update(0.016f);
		graphicsMain.Update(screenDims, creator.IsUpdateBufferSize());
		creator.Update(screenDims);
		graphicsMain.EndUpdate();
		creator.EndUpdate();
	} while (!creator.IsEnd());

	return 0;
}