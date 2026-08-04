#ifndef ENGINE_EDITOR
#define ENGINE_EDITOR

#ifdef GAJMER_CREATOR_EXPORTS
#define GAJMER_CREATOR_API __declspec(dllexport)
#else
#define GAJMER_CREATOR_API __declspec(dllimport)
#endif

#include "creator_pch.h"

namespace GajmerEngine::Presenter
{
	class RenderEngineMain;
}

namespace GajmerEngine::Creator
{
	namespace EngineUI
	{
		class WorldViewer;
		class EngineUIMain;
	}

	struct RendererToViewer
	{
		std::string WorldFboName;
		std::string viewerName;
		int viewerType;				//WorldViewerType
		int fboIndex;
		int bufferIndex;
	};

	class GAJMER_CREATOR_API EngineEditorMain
	{
	public:
		explicit EngineEditorMain() noexcept;

		EngineEditorMain(EngineEditorMain&& rhs) noexcept = delete;
		EngineEditorMain& operator=(EngineEditorMain&& rhs) noexcept = delete;

		EngineEditorMain(const EngineEditorMain& rhs) noexcept = delete;
		EngineEditorMain& operator=(const EngineEditorMain& rhs) noexcept = delete;
		
		bool IsUpdateBufferSize();
		glm::ivec2 GetScreenDimensions();
		bool IsEnd();

		void Update(const glm::ivec2& screenDims);
		void EndUpdate();

		void AddWorldViewers(const GajmerEngine::Presenter::RenderEngineMain* renderEngineMain);

		~EngineEditorMain() noexcept;
	private:
		struct Impl;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}

#endif






