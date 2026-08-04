#include "creator_pch.h"
#include "EngineUIMain.h"
#include "WorldViewer.h"


using namespace GajmerEngine::Creator;
using namespace EngineUI;

struct alignas(alignof(void*)) WorldViewer::Impl
{
	std::function<void(bool)> m_SelectWorldCallback;
	std::string m_viewerName;
	GLuint m_textureID;
	WorldViewerType m_viewerType = WorldViewerType::Empty;

	Impl() = delete;

	Impl(GLuint WorldTex, std::string WorldName, WorldViewerType viewerType, std::function<void(bool)> selectCallback)
		: m_SelectWorldCallback{ selectCallback }	
		, m_viewerName{ WorldName }
		, m_textureID{ WorldTex }
		, m_viewerType{ viewerType }
	{
	}

	Impl(Impl&& rhs) noexcept = default;
	Impl& operator=(Impl&& rhs) noexcept = default;

	Impl(const Impl& rhs) noexcept = delete;
	Impl& operator=(const Impl& rhs) noexcept = delete;

	GLuint GetTextureId() { return m_textureID; }
	std::string GetViewerName() { return m_viewerName; }
	WorldViewerType GetViewerType() { return m_viewerType; }
	void InvokeSelectCallback(bool isSelected) { m_SelectWorldCallback(isSelected); }

	~Impl() noexcept = default;
};

WorldViewer::WorldViewer(GLuint WorldTex, std::string WorldName, WorldViewerType viewerType, std::function<void(bool)> selectCallback)
	: m_pImpl{ Impl(WorldTex, WorldName, viewerType, selectCallback) }
{
}

WorldViewer::WorldViewer(WorldViewer&& rhs) noexcept = default;
WorldViewer& WorldViewer::operator=(WorldViewer&& rhs) noexcept = default;

GLuint WorldViewer::GetTextureId() { return Pimpl().GetTextureId(); }

std::string WorldViewer::GetViewerName() { return Pimpl().GetViewerName(); }

WorldViewerType WorldViewer::GetViewerType() { return Pimpl().GetViewerType(); }

void WorldViewer::InvokeSelectCallback(bool isSelected) { Pimpl().InvokeSelectCallback(isSelected); }

WorldViewer::~WorldViewer() noexcept = default;






