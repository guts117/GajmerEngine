#ifndef STUDIO
#define STUDIO

#ifdef STUDIO_EXPORTS
#define STUDIO_API __declspec(dllexport)
#else
#define STUDIO_API __declspec(dllimport)
#endif

#include "studio_pch.h"

namespace GE::Graphics
{
	class GraphicsMain;
}

namespace GE::Studio
{
	class Viewer;
	class UIMain;

	struct RendererToViewer
	{
		std::string sceneFboName;
		std::string viewerName;
		int viewerType;				//ViewerType
		int fboIndex;
		int bufferIndex;
	};

	class STUDIO_API StudioMain
	{
	public:
		explicit StudioMain() noexcept;

		StudioMain(StudioMain&& rhs) noexcept = delete;
		StudioMain& operator=(StudioMain&& rhs) noexcept = delete;

		StudioMain(const StudioMain& rhs) noexcept = delete;
		StudioMain& operator=(const StudioMain& rhs) noexcept = delete;
		
		bool IsUpdateBufferSize();
		glm::ivec2 GetScreenDimensions();
		bool IsEnd();

		void Update(const glm::ivec2& screenDims);
		void EndUpdate();

		void AddViewers(const Graphics::GraphicsMain* graphicsMain);

		~StudioMain() noexcept;
	private:
		struct Impl;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}

#endif
