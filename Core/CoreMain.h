#ifndef CORE
#define CORE

#include "pch.h"

namespace Core
{
	class CoreMain
	{
	public:
		explicit CoreMain() noexcept = delete;
		//explicit CoreMain(const glm::ivec2& screenDims);

		void Update(const glm::ivec2& screenDims);
		void EndUpdate();

		CoreMain(CoreMain&& rhs) noexcept = delete;
		CoreMain& operator=(CoreMain&& rhs) noexcept = delete;

		CoreMain(const CoreMain& rhs) noexcept = delete;
		CoreMain& operator=(const CoreMain& rhs) noexcept = delete;

		void AddToUpdateStack(std::function<void(glm::ivec2)> updateFunc);

		~CoreMain() noexcept;
	private:
		struct Impl;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}

#endif