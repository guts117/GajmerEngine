#ifndef SCENE_VIEWER
#define SCENE_VIEWER

#include "creator_pch.h"
#include <ForwardDeclaredPimpl.h>

namespace GajmerEngine::Creator
{
	namespace EngineUI
	{
		enum WorldViewerType;

		class WorldViewer
		{
		public:
			explicit WorldViewer() = delete;
			explicit WorldViewer(GLuint WorldTex, std::string WorldName, WorldViewerType viewerType, std::function<void(bool)> selectCallback);

			WorldViewer(WorldViewer&& rhs) noexcept;
			WorldViewer& operator=(WorldViewer&& rhs) noexcept;

			WorldViewer(const WorldViewer& rhs) noexcept = delete;
			WorldViewer& operator=(const WorldViewer& rhs) noexcept = delete;

			GLuint GetTextureId();
			std::string GetViewerName();
			WorldViewerType GetViewerType();
			void InvokeSelectCallback(bool isSelected);

			~WorldViewer() noexcept;
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
}

#endif







