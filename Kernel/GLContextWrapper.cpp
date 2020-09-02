#include <iostream>
#include "GLContextWrapper.hpp"

Kernel::__OpenGL::ContextWrapper::~ContextWrapper() {
	glfwTerminate();
}

bool Kernel::__OpenGL::ContextWrapper::TryInstantiate() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	return true;
}

inline bool Kernel::__OpenGL::ContextWrapper::ShouldTerminate() {
	return glfwWindowShouldClose(window);
}

inline void Kernel::__OpenGL::ContextWrapper::InvokeEmptyEvent() {
	glfwPostEmptyEvent();
}

void Kernel::__OpenGL::ContextWrapper::Update() {
	glfwSwapBuffers(window);
	switch (_epb) {
	case EventProcessingBehavior::Continuous:
		glfwPollEvents();
		break;
	case EventProcessingBehavior::Sporadic:
		glfwWaitEvents();
		break;
	case EventProcessingBehavior::Periodic:
		glfwWaitEventsTimeout(_timeout.value);
		break;
	}
}

void Kernel::__OpenGL::ContextWrapper::Discard() {
	glfwSetWindowShouldClose(window, true);
}
