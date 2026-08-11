#ifndef VIEWER
#define VIEWER

#include "studio_pch.h"
#include <ForwardDeclaredPimpl.h>

namespace GE::Studio
{
	enum ViewerType;

	class Viewer
	{
	public:
		explicit Viewer() = delete;
		explicit Viewer(GLuint worldTex, std::string worldName, ViewerType viewerType, std::function<void(bool)> selectCallback);

		Viewer(Viewer&& rhs) noexcept;
		Viewer& operator=(Viewer&& rhs) noexcept;

		Viewer(const Viewer& rhs) noexcept = delete;
		Viewer& operator=(const Viewer& rhs) noexcept = delete;

		GLuint GetTextureId();
		std::string GetViewerName();
		ViewerType GetViewerType();
		void InvokeSelectCallback(bool isSelected);

		~Viewer() noexcept;
	private:
		struct Impl;

		const Impl& Pimpl() const { return m_pImpl.Get(); }
		Impl& Pimpl() { return m_pImpl.Get(); }

#ifdef NDEBUG //size of string is debug(40) and release(32), function<> is debug/release(64)
		ForwardDeclaredPimpl<Impl, alignof(void*) * 13, alignof(void*)> m_pImpl;
#else
		ForwardDeclaredPimpl<Impl, alignof(void*) * 14, alignof(void*)> m_pImpl;
#endif;
	};
}

#endif

