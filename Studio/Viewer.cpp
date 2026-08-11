#include "studio_pch.h"
#include "UIMain.h"
#include "Viewer.h"


using namespace GE::Studio;

struct alignas(alignof(void*)) Viewer::Impl
{
	std::function<void(bool)> m_SelectWorldCallback;
	std::string m_viewerName;
	GLuint m_textureID;
	ViewerType m_viewerType = ViewerType::Empty;

	Impl() = delete;

	Impl(GLuint worldTex, std::string worldName, ViewerType viewerType, std::function<void(bool)> selectCallback)
		: m_SelectWorldCallback{ selectCallback }	
		, m_viewerName{ worldName }
		, m_textureID{ worldTex }
		, m_viewerType{ viewerType }
	{
	}

	Impl(Impl&& rhs) noexcept = default;
	Impl& operator=(Impl&& rhs) noexcept = default;

	Impl(const Impl& rhs) noexcept = delete;
	Impl& operator=(const Impl& rhs) noexcept = delete;

	GLuint GetTextureId() { return m_textureID; }
	std::string GetViewerName() { return m_viewerName; }
	ViewerType GetViewerType() { return m_viewerType; }
	void InvokeSelectCallback(bool isSelected) { m_SelectWorldCallback(isSelected); }

	~Impl() noexcept = default;
};

Viewer::Viewer(GLuint worldTex, std::string worldName, ViewerType viewerType, std::function<void(bool)> selectCallback)
	: m_pImpl{ Impl(worldTex, worldName, viewerType, selectCallback) }
{
}

Viewer::Viewer(Viewer&& rhs) noexcept = default;
Viewer& Viewer::operator=(Viewer&& rhs) noexcept = default;

GLuint Viewer::GetTextureId() { return Pimpl().GetTextureId(); }

std::string Viewer::GetViewerName() { return Pimpl().GetViewerName(); }

ViewerType Viewer::GetViewerType() { return Pimpl().GetViewerType(); }

void Viewer::InvokeSelectCallback(bool isSelected) { Pimpl().InvokeSelectCallback(isSelected); }

Viewer::~Viewer() noexcept = default;