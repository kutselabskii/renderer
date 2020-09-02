#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils.hpp"

namespace Kernel {
	using namespace Utils;

	class ContextWrapper {
	public:
		enum class EventProcessingBehavior {
			Continuous,
			Sporadic,
			Periodic,
		};

		ContextWrapper(std::string title, Vector2<int> size, EventProcessingBehavior epb, udouble timeout = 0)
			: window(nullptr), title(title), size(size), _epb(epb), _timeout(timeout) {}
		virtual ~ContextWrapper() = default;

		[[nodiscard]] virtual bool TryInstantiate() = 0;
		[[nodiscard]] virtual bool ShouldTerminate() = 0;
		virtual void InvokeEmptyEvent() = 0;
		virtual void Update() = 0;
		virtual void Discard() = 0;

		GLFWwindow* window;
		std::string title;
		Vector2<int> size;

	protected:
		EventProcessingBehavior _epb;
		udouble _timeout;
	};
}