#include "pch.h"
#include "Pose.h"

using namespace Core;

//ToDo: Wrap in Math class Global variable not good
const float toRadians = static_cast<float>(M_PI) / 180.0f;

void Pose::Translate(glm::vec3&& position)
{
	this->position = std::move(position);
}

void Pose::RotateOnAxis(float&& angleInDegrees, glm::vec3&& axis)
{
	quaternion = glm::rotate(quaternion, angleInDegrees, axis);
	eulerAngles = glm::eulerAngles(quaternion) * toRadians;
}

void Pose::Scale(glm::vec3&& scale)
{
	this->scale = std::move(scale);
}

void Pose::Updatematrix()
{
	model_matrix = glm::translate(model_matrix, position);
	model_matrix *= glm::toMat4(quaternion);
	model_matrix = glm::scale(model_matrix, scale);
}