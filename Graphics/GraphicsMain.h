#ifndef GRAPHICS_MAIN
#define GRAPHICS_MAIN

#include "graphics_pch.h"
//#include "spimpl.h"

#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif

namespace GE::Graphics
{
	class Render_Object;
	class Texture;
	class World_Fbo_Handler_Manager;
	enum TexType;

	struct TexMapData
	{
		TexType&& type;
		std::string path;
	};

	class GRAPHICS_API GraphicsMain
	{
	public:
		explicit GraphicsMain() = delete;
		explicit GraphicsMain(const glm::ivec2& screenDims);

		GraphicsMain(GraphicsMain&& rhs) noexcept = delete;
		GraphicsMain& operator=(GraphicsMain&& rhs) noexcept = delete;

		GraphicsMain(const GraphicsMain& rhs) noexcept = delete;
		GraphicsMain& operator=(const GraphicsMain& rhs) noexcept = delete;

		void Update(const glm::ivec2& screenDims, const bool& isUpdateBuffers);
		void EndUpdate();

		const GLuint GetFboBuffer(const std::string& fboHandlerName, const GLuint& fboIndex, const GLuint& bufferIndex) const;

		//ToDo:
		//static std::unique_ptr<std::map<TexType, std::vector<std::weak_ptr<Texture>>>> CreateTextureMap(std::vector<TexMapData>&& texMapData);

		~GraphicsMain() noexcept;
	private:
		struct Impl;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}
#endif