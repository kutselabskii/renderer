#include "Application.hpp"
#include "GLContextWrapper.hpp"
#include "VKContextWrapper.hpp"
#include "InputListener.hpp"

Kernel::Application::Application(RenderingBackend backend, std::string title, Vector2<int> size) {
	switch (backend) {
	case RenderingBackend::OpenGL:
		context = new __OpenGL::ContextWrapper(title, size, Kernel::ContextWrapper::EventProcessingBehavior::Continuous);
		if (!context->TryInstantiate()) throw "Failed to create OpenGL context.";
		input = new InputListener(context->window);
		break;
	case RenderingBackend::Vulkan:
		// TODO.
		break;
	}
}
