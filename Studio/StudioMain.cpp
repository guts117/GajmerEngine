#include "studio_pch.h"
#include "StudioMain.h"
#include "UIMain.h"
#include "GraphicsMain.h"
#include "Viewer.h"
#include "InputManager.h"

using namespace GE::Studio;
using namespace GE::Graphics;


struct StudioMain::Impl
{
	UIMain ui;
	std::vector<RendererToViewer> m_renderer2Viewers;
	bool isEditorViewSelected;
	bool isGameViewSelected;
		
	Impl() noexcept
		: ui { true, "#version 460" }
		, m_renderer2Viewers{ RendererToViewer { "Final_Output_Pass", "EditorView", Editor, 0, 0 } , RendererToViewer { "CameraPass0", "GameView", InGame, 0, 0 } }
		, isEditorViewSelected { false }
		, isGameViewSelected { false }
	{
	}

	Impl(Impl&& rhs) noexcept = delete;
	Impl& operator=(Impl&& rhs) noexcept = delete;
	Impl(const Impl& rhs) noexcept = delete;
	Impl& operator=(const Impl& rhs) noexcept = delete;

	void Update(const glm::ivec2& screenDims)
	{
		ui.Update(screenDims);

		if (isEditorViewSelected)
		{
			//cameras[1]->keyControl(mainWindow->getKeys(), deltaTime);
			//auto xChange = 0.0f;
			//auto yChange = 0.0f;

			if (ImGui::IsMouseDown(ImGuiMouseButton_Middle))
			{
				std::cout << "yes editor" << std::endl;
			//	xChange = mainWindow->getXChange();
			//	yChange = mainWindow->getYChange();
			}
			//cameras[1]->mouseControl(xChange, yChange, mainWindow->scrollVal, deltaTime);

		}
		else if(isGameViewSelected)
		{
			if (InputManager::GetKeys()[GLFW_KEY_L])
			{
				std::cout << "L" << std::endl;
				//spotLights[0]->Toggle();
				//mainWindow->getKeys()[GLFW_KEY_L] = false;
			}
			//std::cout << "yes game" << std::endl;
			//cameras[0]->keyControl(mainWindow->getKeys(), deltaTime);
			//cameras[0]->mouseControl(mainWindow->getXChange(), mainWindow->getYChange(), 0, 0);
		}
	}

	void EndUpdate()
	{
		ui.EndUpdate();
	}

	void AddViewers(const GraphicsMain* graphicsMain)
	{
		auto editorSelectCallback = [this](bool isSelected) { isEditorViewSelected = isSelected; };
		auto gameSelectCallback = [this](bool isSelected) { isGameViewSelected = isSelected; };
		for(auto r2v : m_renderer2Viewers)
		{
			auto fbo = graphicsMain->GetFboBuffer(r2v.worldFboName, r2v.fboIndex, r2v.bufferIndex);
			
			std::function<void(bool)> selectCallback;
			if (r2v.viewerType == Editor)	{ selectCallback = editorSelectCallback; }
			else							{ selectCallback = gameSelectCallback; }
			ui.AddViewers(fbo, r2v.viewerName, static_cast<ViewerType>(r2v.viewerType), selectCallback);
		}
	}

	~Impl() noexcept = default;
};

StudioMain::StudioMain() noexcept
	: m_pImpl{ std::make_unique<Impl>()}
{
}

bool StudioMain::IsUpdateBufferSize() 
{
	return Pimpl()->ui.IsUpdateBufferSize();
}

glm::ivec2 StudioMain::GetScreenDimensions()
{
	return Pimpl()->ui.GetScreenDimensions();
}

bool StudioMain::IsEnd()
{
	return Pimpl()->ui.IsEnd();
}
void StudioMain::Update(const glm::ivec2& screenDims)
{
	Pimpl()->Update(screenDims);
}

void StudioMain::EndUpdate()
{
	Pimpl()->EndUpdate();
}

void StudioMain::AddViewers(const GraphicsMain* graphicsMain)
{
	Pimpl()->AddViewers(graphicsMain);
}

StudioMain::~StudioMain() noexcept = default;
