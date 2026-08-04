#include "pch.h"
#include "Simulator.h"
#include "VisibleNode.h"
#include "Pose.h"

using namespace GajmerEngine::Runtime;


struct Simulator::Impl
{
	std::vector<Pose> transformPool = std::vector<Pose>();
	std::vector<VisibleNode> simObjectpool = std::vector<VisibleNode>();

	//where game loops happen;
	std::vector<std::function<void()>> onCreation;
	std::vector<std::function<void()>> startFuncPool;
	std::vector<std::function<void()>> preUpdateFuncPool;
	std::vector<std::function<void()>> updateFuncPool;
	std::vector<std::function<void()>> endUpdateFuncPool;
	std::vector<std::function<void()>> endFuncPool;

	Impl() noexcept = delete;

	Impl(Impl&& rhs) noexcept = delete;
	Impl& operator=(Impl&& rhs) noexcept = delete;

	Impl(const Impl& rhs) noexcept = delete;
	Impl& operator=(const Impl& rhs) noexcept = delete;

	void UpdateObjectTransforms()
	{
		for (auto& t : transformPool)
		{
			t.UpdateModelMatrix();
		}
	}

	void Update(const glm::ivec2& screenDims) 
	{
		UpdateObjectTransforms();
	}
	void EndUpdate() 
	{
	}

	~Impl() noexcept = default;
};


void Simulator::Update(const glm::ivec2& screenDims)
{
}

void Simulator::EndUpdate()
{
}

void Simulator::AddToUpdateStack(std::function<void(glm::ivec2)>)
{
}

Simulator::~Simulator() noexcept = default;






