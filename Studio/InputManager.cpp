#include "studio_pch.h"
#include "InputManager.h"
#include "UIMain.h"

using namespace GE::Studio;

double InputManager::scrollVal;
bool InputManager::keys[1024];

bool InputManager::isLeftMousePress;
bool InputManager::isLeftMouseRelease;
bool InputManager::isMiddleMousePress;
bool InputManager::isMiddleMouseRelease;

GLfloat InputManager::lastX;
GLfloat InputManager::lastY;
GLfloat InputManager::xChange;
GLfloat InputManager::yChange;
bool InputManager::mouseFirstMoved;

InputManager::InputManager()
{
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
}

GLfloat InputManager::GetXChange() {
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat  InputManager::GetYChange() {
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

glm::vec2 InputManager::GetCursorPos()
{
	return glm::vec2(lastX, lastY);
}

void InputManager::HandleKeysPresses(GLFWwindow* window, int key, int code, int action, int mode) 
{
	//ToDo: Key inputs on Imgui Windows.
	if (UIMain::AddKeyBoardButtonEvent(ImGuiKey::ImGuiKey_None, false))
	{
		if (key >= 0 && key < 1024) {
			if (action == GLFW_PRESS) {
				keys[key] = true;
			}
			else if (action == GLFW_RELEASE) {
				keys[key] = false;
			}
		}
	}
}
void InputManager::HandleCursorPosition(GLFWwindow* window, double xPos, double yPos) 
{
	if (UIMain::AddCursorPosEvent(xPos, yPos))
	{
		if (mouseFirstMoved) {
			lastX = static_cast<float>(xPos);
			lastY = static_cast<float>(yPos);
			mouseFirstMoved = false;
		}

		xChange = static_cast<float>(xPos) - lastX;
		yChange = lastY - static_cast<float>(yPos);

		lastX = static_cast<float>(xPos);
		lastY = static_cast<float>(yPos);
	}
}

void InputManager::HandleMousePresses(GLFWwindow* window, int button, int action, int mode) 
{
	if (UIMain::AddMouseButtonEvent(button, action == GLFW_PRESS)) 
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (action == GLFW_PRESS) {
				isLeftMousePress = true;
				isLeftMouseRelease = false;
			}
			else if (action == GLFW_RELEASE) {
				isLeftMouseRelease = true;
				isLeftMousePress = false;
			}
		}

		if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
			if (action == GLFW_PRESS) {
				isMiddleMousePress = true;
				isLeftMouseRelease = false;
			}
			else if (action == GLFW_RELEASE) {
				isLeftMouseRelease = true;
				isMiddleMousePress = false;
			}
		}
	}
}

void InputManager::HandleMouseScrolls(GLFWwindow* window, double xOffset, double yOffset)
{
	if (UIMain::AddMouseScrollEvent(xOffset, yOffset)) 
	{
		scrollVal = yOffset;
	}
}

InputManager::~InputManager()
{
	//empty
}
