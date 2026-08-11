#ifndef UI_MAIN
#define UI_MAIN

#ifdef STUDIO_EXPORTS
#define STUDIO_API __declspec(dllexport)
#else
#define STUDIO_API __declspec(dllimport)
#endif

#include "studio_pch.h"

namespace GE::Studio
{
	enum ViewerType
	{
		Empty,
		Editor,
		InGame,
		//Add other sceneviewers for debug purposes too 
	};

	class STUDIO_API UIMain
	{
	public:
		explicit UIMain() noexcept = delete;
		explicit UIMain(const bool installCallbacks, const std::string version) noexcept;

		UIMain(UIMain&& rhs) noexcept = delete;
		UIMain& operator=(UIMain&& rhs) noexcept = delete;

		UIMain(const UIMain& rhs) noexcept = delete;
		UIMain& operator=(const UIMain& rhs) noexcept = delete;

		void Update(const glm::ivec2& screenDims);
		void EndUpdate();

		void AddViewers(GLuint sceneTex, std::string sceneName, ViewerType viewerType, std::function<void(bool)> selectCallback);
		GLFWwindow* GetMainWindow();
		glm::ivec2 GetScreenDimensions();
		bool IsUpdateBufferSize();
		static bool AddKeyBoardButtonEvent(int key, bool down);
		static bool AddCursorPosEvent(float x, float y);
		static bool AddMouseButtonEvent(int mouse_button, bool down);
		static bool AddMouseScrollEvent(float wheel_x, float wheel_y);

		bool IsEnd();

		~UIMain() noexcept;
	private:
		struct Impl;
		struct SimpleNodeEditorExample;
		struct BasicInteractionNodeEditorExample;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}

#endif


