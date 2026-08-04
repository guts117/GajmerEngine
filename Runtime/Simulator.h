#ifndef ENGINE_SIMULATOR
#define ENGINE_SIMULATOR

#include "pch.h"

namespace GajmerEngine::Runtime
{
	class Simulator
	{
	public:
		explicit Simulator() noexcept = delete;
		//explicit Simulator(const glm::ivec2& screenDims);

		void Update(const glm::ivec2& screenDims);
		void EndUpdate();

		Simulator(Simulator&& rhs) noexcept = delete;
		Simulator& operator=(Simulator&& rhs) noexcept = delete;

		Simulator(const Simulator& rhs) noexcept = delete;
		Simulator& operator=(const Simulator& rhs) noexcept = delete;

		void AddToUpdateStack(std::function<void(glm::ivec2)> updateFunc);

		~Simulator() noexcept;
	private:
		struct Impl;

		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}

#endif






