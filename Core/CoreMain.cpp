#include "pch.h"
#include "CoreMain.h"
#include "VisibleNode.h"
#include "Pose.h"

using namespace GE::Core;


struct CoreMain::Impl
{
	std::vector<Pose> posePool = std::vector<Pose>();
	std::vector<VisibleNode> visibleNodepool = std::vector<VisibleNode>();

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

	void UpdateObjectPoses()
	{
		for (auto& t : posePool)
		{
			t.Updatematrix();
		}
	}

	void Update(const glm::ivec2& screenDims) 
	{
		UpdateObjectPoses();
	}
	void EndUpdate() 
	{
	}

	~Impl() noexcept = default;
};


void CoreMain::Update(const glm::ivec2& screenDims)
{
}

void CoreMain::EndUpdate()
{
}

void CoreMain::AddToUpdateStack(std::function<void(glm::ivec2)>)
{
}

CoreMain::~CoreMain() noexcept = default;
