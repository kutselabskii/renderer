#pragma once
#include "Utils.hpp"
#include "ContextWrapper.hpp"
#include "InputListener.hpp"

namespace Kernel {
	using namespace Utils;

	enum class RenderingBackend {
		OpenGL,
		Vulkan,
	};

	class Application {
	public:
		Application(RenderingBackend backend, std::string title, Vector2<int> size);
		~Application() = default;

		ContextWrapper* context;
		InputListener* input;
	};
}