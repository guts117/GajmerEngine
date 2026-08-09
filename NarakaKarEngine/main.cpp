#include "pch.h"
#include "GraphicsMain.h"
#include "PhysicsMain.h"
#include "StudioMain.h"

//using namespace NarakaKarEngine;
using namespace Studio;
using namespace Graphics;
using namespace Physics;


int main()
{
	auto physics = PhysicsMain();
	auto creator = StudioMain();
	glm::ivec2 screenDims = glm::ivec2(creator.GetScreenDimensions());
	auto graphicsMain = GraphicsMain(screenDims);
	creator.AddViewers(&graphicsMain);

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