#ifndef DEBUG
#define DEBUG

#include "graphics_pch.h"

namespace GE::Graphics
{
	class Debug
	{
	public:
		Debug() = default;
		void static DebugPrintReferenceTBN(std::string header, GLfloat* vertices, int offset, glm::vec3 nm);
		void static DebugPrintTBN(std::string header, GLfloat* vertices, int offsetN, int offsetT, int offsetB = -1);
	private:
		~Debug() = default;
	};
}
#endif