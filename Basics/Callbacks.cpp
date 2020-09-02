#include "Callbacks.h"

void Callbacks::OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
