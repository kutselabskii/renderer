#pragma once
#include <string>
#include "Utils.hpp"
#include <unordered_map>
#include "ContextWrapper.hpp"

namespace Kernel {
	using namespace Utils;

	class InputListener {
	public:
		enum class Key {
			None,
			Escape,
		};

		InputListener(GLFWwindow* window) : _window(window), _lastUpdateKey(Key::None) {}
		~InputListener() = default;

		[[nodiscard]] bool IsPressed(Key);
		[[nodiscard]] bool IsReleased(Key);
		[[nodiscard]] bool WasPressed(Key);
		[[nodiscard]] bool WasReleased(Key);

	protected:
		static std::unordered_map<Key, int> _keyBindings;

		GLFWwindow* _window;
		Key _lastUpdateKey;
	};
}