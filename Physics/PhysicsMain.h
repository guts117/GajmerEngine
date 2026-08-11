#ifndef PHYSICS
#define PHYSICS

#ifdef PHYSICS_EXPORTS
#define PHYSICS_API __declspec(dllexport)
#else
#define PHYSICS_API __declspec(dllimport)
#endif

#include "physics_pch.h"

namespace GE::Physics
{
	class PHYSICS_API PhysicsMain
	{
	public:
		explicit PhysicsMain();
		PhysicsMain(PhysicsMain&& rhs) noexcept = delete;
		PhysicsMain& operator=(PhysicsMain&& rhs) noexcept = delete;

		PhysicsMain(const PhysicsMain& rhs) noexcept = delete;
		PhysicsMain& operator=(const PhysicsMain& rhs) noexcept = delete;

		void Update(float deltaTime);

		void AddStaticPlane(float x, float y, float z, float mass, glm::vec3 normal, glm::mat4* model);
		void AddSphere(float rad, float x, float y, float z, float mass, glm::mat4* model);

		~PhysicsMain() noexcept;

	private:
		struct Impl;
		const Impl* Pimpl() const { return m_pImpl.get(); }
		Impl* Pimpl() { return m_pImpl.get(); }

		std::unique_ptr<Impl> m_pImpl;
	};
}
#endif //PHYSICS


