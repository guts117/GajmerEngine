#ifndef WORLD_FBO_HANDLER_MANAGER
#define WORLD_FBO_HANDLER_MANAGER

#include "graphics_pch.h"

//Loads and manages all the framebuffers 

namespace GE::Graphics
{
	class Fbo_Handler;

	class World_Fbo_Handler_Manager
	{
	public:
		explicit World_Fbo_Handler_Manager() = delete;
		explicit World_Fbo_Handler_Manager(const std::string& worldName, const glm::ivec2& screenDims);

		World_Fbo_Handler_Manager(World_Fbo_Handler_Manager&& rhs) noexcept;
		World_Fbo_Handler_Manager& operator=(World_Fbo_Handler_Manager&& rhs) noexcept;

		World_Fbo_Handler_Manager(const World_Fbo_Handler_Manager& rhs) noexcept = delete;
		World_Fbo_Handler_Manager& operator=(const World_Fbo_Handler_Manager& rhs) noexcept = delete;

		Fbo_Handler* FindFboHandler(const std::string& handlerName);
		void ResizeScreenFboHandlers(const GLuint& width, const GLuint& height);
		Fbo_Handler* AddGameCameraFboHandlers(const int& cameraId, const glm::ivec2& screenDims);
		~World_Fbo_Handler_Manager() noexcept;

	private:
		//ToDo: Might have more than one instance that's why using ForwardDeclaredPimpl here
		struct Impl;

		const Impl& Pimpl() const { return m_pImpl.Get(); }
		Impl& Pimpl() { return m_pImpl.Get(); }

#ifdef NDEBUG //size of string debug(40), release(32) and size of vector debug(32), release(24)
		ForwardDeclaredPimpl<Impl, alignof(std::string) * 7, alignof(std::string)> m_pImpl;
#else
		ForwardDeclaredPimpl<Impl, alignof(std::string) * 9, alignof(std::string)> m_pImpl;
#endif;
	};

}
#endif